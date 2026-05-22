package reactivos.demo.features.estante;

import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;
import reactivos.demo.exception.RecursoNoEncontradoException;
import reactivos.demo.exception.RecursoYaExisteException;
import reactivos.demo.exception.ReglaNegocioException;
import reactivos.demo.features.lote.LoteRepository;
import reactivos.demo.features.lote.LoteEntity;

import java.math.BigDecimal;
import java.util.Comparator;
import java.util.List;
import java.util.UUID;

@Service
@AllArgsConstructor
public class EstanteService implements IEstanteService{

    private final EstanteRepository estanteRepository;
    private final LoteRepository loteRepository;
    private final EstanteMapper estanteMapper;


    @Override
    public EstanteResponseDTO create(EstanteRequestDTO estanteRequestDTO) {
        if (estanteRepository.existsByCodigoAlmacen(estanteRequestDTO.getCodigoAlmacen())) {
            throw new RecursoYaExisteException(
                    "Ya existe un estante con el código " + estanteRequestDTO.getCodigoAlmacen()
            );
        }

        EstanteEntity estanteEntity = estanteMapper.toEntity(estanteRequestDTO);
        estanteEntity.setNivelRiesgoActual(BigDecimal.ZERO);
        estanteEntity = estanteRepository.save(estanteEntity);
        return estanteMapper.toResponse(estanteEntity);
    }

    @Override
    public EstanteResponseDTO update(UUID externalId, EstanteRequestDTO estanteRequestDTO) {
        EstanteEntity estanteEntity = estanteRepository
                .findByExternalId(externalId)
                .orElseThrow(() ->
                        new RecursoNoEncontradoException("No se ha encontrado el estante con el id " + externalId));

        estanteMapper.updateEntity(estanteEntity, estanteRequestDTO);
        estanteEntity = estanteRepository.save(estanteEntity);
        return estanteMapper.toResponse(estanteEntity);
    }

    @Override
    public void delete(UUID externalId) {
        EstanteEntity estanteEntity = estanteRepository
                .findByExternalId(externalId)
                .orElseThrow(() ->
                        new RecursoNoEncontradoException("No se ha encontrado el estante con el id " + externalId));
        List<LoteEntity> lotes = loteRepository.findByEstanteExternalId(externalId);

        if (!lotes.isEmpty()) {
            throw new ReglaNegocioException(
                    "No se puede eliminar el estante porque tiene lotes asociados."
            );
        }

        estanteRepository.delete(estanteEntity);
    }

    @Override
    public EstanteResponseDTO getByExternalId(UUID externalId) {
        EstanteEntity estanteEntity = estanteRepository
                .findByExternalId(externalId)
                .orElseThrow(() ->
                        new RecursoNoEncontradoException("No se ha encontrado el estante con el id " + externalId));
        return estanteMapper.toResponse(estanteEntity);
    }

    @Override
    public List<EstanteResponseDTO> getAll() {
        return estanteRepository.findAll()
                .stream()
                .sorted(Comparator.comparing(
                        EstanteEntity::getNivelRiesgoActual
                ))
                .map(estanteMapper::toResponse)
                .toList();
    }
}
