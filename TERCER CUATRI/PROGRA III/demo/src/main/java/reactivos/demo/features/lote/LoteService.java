package reactivos.demo.features.lote;

import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;
import reactivos.demo.exception.ReglaNegocioException;
import reactivos.demo.features.estante.EstanteEntity;
import reactivos.demo.features.estante.EstanteRepository;
import reactivos.demo.features.reactivo.ReactivoEntity;
import reactivos.demo.features.reactivo.ReactivoRepository;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.util.List;
import java.util.UUID;

@Service
@AllArgsConstructor
public class LoteService implements ILoteService{

    private final LoteRepository loteRepository;
    private final ReactivoRepository reactivoRepository;
    private final EstanteRepository estanteRepository;

    private final LoteMapper loteMapper;

    @Override
    public LoteResponseDTO create(LoteRequestDTO loteRequestDTO) {
        ReactivoEntity reactivoEntity = reactivoRepository
                .findByExternalId(loteRequestDTO.getReactivoExternalId())
                .orElseThrow(()
                        -> new RuntimeException("Reactivo no encontrado."));

        EstanteEntity estanteEntity = estanteRepository
                .findByExternalId(loteRequestDTO.getEstanteExternalId())
                .orElseThrow(()
                        -> new RuntimeException("Estante no encontrado."));

       if (loteRequestDTO.getFechaVencimiento().isBefore(LocalDate.now().plusMonths(6))) {
           throw new ReglaNegocioException("La fecha de vencimiento debe ser al menos 6 meses en el futuro.");
       }

        if (reactivoEntity.getEsPrecursorQuimico() && !estanteEntity.getCodigoAlmacen().equals("SEC-01")) {
            throw new ReglaNegocioException("El reactivo es un precursor químico y debe estar en el estante SEC-01.");
        }

       LoteEntity loteEntity = loteMapper.toEntity(loteRequestDTO);
       loteEntity.setEstante(estanteEntity);
       loteEntity.setReactivo(reactivoEntity);

        BigDecimal riesgoNuevo = loteEntity.getCantidadKg()
                .multiply(BigDecimal.valueOf(reactivoEntity.getNivelPeligro()));
        BigDecimal riesgoActualizado = estanteEntity.getNivelRiesgoActual().add(riesgoNuevo);

       if (riesgoActualizado.compareTo(estanteEntity.getRiesgoLimite()) > 0) {
           throw new ReglaNegocioException("El estante ha superado el límite de riesgo.");
       }

       estanteEntity.setNivelRiesgoActual(riesgoActualizado);
       estanteRepository.save(estanteEntity);

       loteRepository.save(loteEntity);
       return loteMapper.toResponse(loteEntity);
    }

    @Override
    public LoteResponseDTO update(UUID externalId, LoteRequestDTO loteRequestDTO) {
        LoteEntity loteEntity = loteRepository
                .findByExternalId(externalId)
                .orElseThrow(() -> new RuntimeException("Lote no encontrado."));

        ReactivoEntity reactivoEntity = reactivoRepository
                .findByExternalId(loteRequestDTO.getReactivoExternalId())
                .orElseThrow(()
                        -> new RuntimeException("Reactivo no encontrado."));

        EstanteEntity estanteEntity = estanteRepository
                .findByExternalId(loteRequestDTO.getEstanteExternalId())
                .orElseThrow(()
                        -> new RuntimeException("Estante no encontrado."));

        EstanteEntity estanteViejo = loteEntity.getEstante();

        BigDecimal riesgoViejo = loteEntity.getCantidadKg()
                .multiply(BigDecimal.valueOf(
                        loteEntity.getReactivo().getNivelPeligro()
                ));

        estanteViejo.setNivelRiesgoActual(
                estanteViejo.getNivelRiesgoActual()
                        .subtract(riesgoViejo)
        );

        loteMapper.updateEntity(loteEntity, loteRequestDTO);

        loteEntity.setReactivo(reactivoEntity);
        loteEntity.setEstante(estanteEntity);


        BigDecimal riesgoNuevo = loteEntity.getCantidadKg()
                .multiply(BigDecimal.valueOf(
                        reactivoEntity.getNivelPeligro()
                ));

        BigDecimal nuevoRiesgoTotal = estanteEntity
                .getNivelRiesgoActual()
                .add(riesgoNuevo);

        if (nuevoRiesgoTotal.compareTo(
                estanteEntity.getRiesgoLimite()) > 0) {
            throw new ReglaNegocioException(
                    "El estante ha superado el límite de riesgo."
            );
        }

        estanteEntity.setNivelRiesgoActual(nuevoRiesgoTotal);

        estanteRepository.save(estanteViejo);
        estanteRepository.save(estanteEntity);

        loteEntity = loteRepository.save(loteEntity);

        return loteMapper.toResponse(loteEntity);
    }

    @Override
    public LoteResponseDTO getByExternalId(UUID externalId) {
        LoteEntity loteEntity = loteRepository
                .findByExternalId(externalId)
                .orElseThrow(() -> new RuntimeException("Lote no encontrado."));
        return loteMapper.toResponse(loteEntity);
    }
    @Override
    public List<LoteResponseDTO> getAll() {
        return loteRepository
                .findAll()
                .stream()
                .map(loteMapper::toResponse)
                .toList();
    }
    @Override
    public LoteResponseDTO consumir(UUID externalId, BigDecimal cantidadKg) {
        LoteEntity loteEntity = loteRepository
                .findByExternalId(externalId)
                .orElseThrow(() -> new RuntimeException("Lote no encontrado."));

        if (loteEntity.getCantidadKg().compareTo(cantidadKg) < 0) {
            throw new ReglaNegocioException("La cantidad a consumir es mayor que la cantidad disponible.");
        }
        loteEntity.setCantidadKg(loteEntity.getCantidadKg().subtract(cantidadKg));

        EstanteEntity estanteEntity = loteEntity.getEstante();
        BigDecimal riesgoConsumido = cantidadKg.multiply(
                BigDecimal.valueOf(
                        loteEntity.getReactivo().getNivelPeligro()));

        estanteEntity.setNivelRiesgoActual(
                estanteEntity.getNivelRiesgoActual()
                        .subtract(riesgoConsumido));

        estanteRepository.save(estanteEntity);

        loteEntity = loteRepository.save(loteEntity);
        return loteMapper.toResponse(loteEntity);
    }
}
