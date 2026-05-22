package reactivos.demo.features.reactivo;

import lombok.AllArgsConstructor;
import org.springframework.data.jpa.domain.Specification;
import org.springframework.stereotype.Service;
import reactivos.demo.exception.RecursoYaExisteException;
import reactivos.demo.features.lote.LoteRepository;
import reactivos.demo.features.lote.LoteEntity;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.util.List;
import java.util.UUID;

@Service
@AllArgsConstructor
public class ReactivoService implements IReactivoService{

    private final ReactivoRepository reactivoRepository;
    private final LoteRepository loteRepository;
    private final ReactivoMapper reactivoMapper;

    @Override
    public ReactivoResponseDTO create(ReactivoRequestDTO reactivoRequestDTO) {
        if(reactivoRepository.findByNombre(reactivoRequestDTO.getNombre()).isPresent()) {
            throw new RecursoYaExisteException("El reactivo ya existe");
        }
        ReactivoEntity reactivoEntity = reactivoMapper.toEntity(reactivoRequestDTO);
        reactivoRepository.save(reactivoEntity);
        return reactivoMapper.toResponse(reactivoEntity);
    }

    @Override
    public ReactivoResponseDTO update(UUID externalId, ReactivoRequestDTO reactivoRequestDTO) {
        ReactivoEntity reactivoEntity = reactivoRepository
                .findByExternalId(externalId)
                .orElseThrow(() ->
                        new RecursoYaExisteException("El reactivo no existe"));

        reactivoMapper.updateEntity(reactivoEntity, reactivoRequestDTO);
        reactivoEntity = reactivoRepository.save(reactivoEntity);
        return reactivoMapper.toResponse(reactivoEntity);
    }

    @Override
    public ReactivoResponseDTO delete(UUID externalId) {
        ReactivoEntity reactivoEntity = reactivoRepository
                .findByExternalId(externalId)
                .orElseThrow(() ->
                        new RecursoYaExisteException("El reactivo no existe"));

        List<LoteEntity> lotes = loteRepository
                .findByReactivoExternalId(externalId);

        for(LoteEntity lote : lotes) {
            if (lote.getFechaVencimiento().isAfter(LocalDate.now()) &&
                    lote.getCantidadKg().compareTo(BigDecimal.ZERO) > 0) {
                throw new RecursoYaExisteException("El reactivo tiene lote activo");
            }
        }

        reactivoRepository.delete(reactivoEntity);
        return reactivoMapper.toResponse(reactivoEntity);
    }

    @Override
    public ReactivoResponseDTO getByExternalId(UUID externalId) {
        ReactivoEntity reactivoEntity = reactivoRepository
                .findByExternalId(externalId)
                .orElseThrow(() ->
                        new RecursoYaExisteException("El reactivo no existe"));
        return reactivoMapper.toResponse(reactivoEntity);
    }

    @Override
    public List<ReactivoResponseDTO> getAll(
            String nombre,
            Integer nivelPeligro,
            Boolean esPrecursorQuimico) {

        Specification<ReactivoEntity> specification = Specification
                .where(ReactivoSpecification.hasNombre(nombre))
                .and(ReactivoSpecification.hasNivelPeligro(nivelPeligro))
                .and(ReactivoSpecification.hasEsPrecursorQuimico(esPrecursorQuimico));

        return reactivoRepository
                .findAll(specification)
                .stream()
                .map(reactivoMapper::toResponse)
                .toList();


        /*
        return reactivoRepository
                .findAll()
                .stream().filter(reactivo -> nombre == null || reactivo.getNombre().toLowerCase().contains(nombre.toLowerCase()))
                .filter(reactivo -> nivelPeligro == null || reactivo.getNivelPeligro().equals(nivelPeligro))
                .filter(reactivo -> esPrecursorQuimico == null || reactivo.getEsPrecursorQuimico().equals(esPrecursorQuimico))
                .map(reactivoMapper::toResponse)
                .toList();

         */

        /*
        if (nivelPeligro != null) {
            reactivoRepository
                    .findByNivelPeligro(nivelPeligro)
                    .stream()
                    .map(reactivoMapper::toResponse)
                    .toList();
        }
        if (esPrecursorQuimico != null) {
            return reactivoRepository
                    .findByEsPrecursorQuimico(esPrecursorQuimico)
                    .stream()
                    .map(reactivoMapper::toResponse)
                    .toList();
        }

        return reactivoRepository
                .findByNombre(nombre)
                .stream()
                .map(reactivoMapper::toResponse)
                .toList();

         */


    }


}
