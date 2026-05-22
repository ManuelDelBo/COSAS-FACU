package reactivos.demo.features.estante;

import java.util.List;
import java.util.UUID;

public interface IEstanteService {
    EstanteResponseDTO create(EstanteRequestDTO estanteRequestDTO);
    EstanteResponseDTO update(UUID externalId, EstanteRequestDTO estanteRequestDTO);
    void delete(UUID externalId);
    EstanteResponseDTO getByExternalId(UUID externalId);

    List<EstanteResponseDTO> getAll();
}
