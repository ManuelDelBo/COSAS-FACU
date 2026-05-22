package reactivos.demo.features.reactivo;

import java.util.List;
import java.util.UUID;

public interface IReactivoService {

    ReactivoResponseDTO create(ReactivoRequestDTO reactivoRequestDTO);

    ReactivoResponseDTO update(UUID externalId, ReactivoRequestDTO reactivoRequestDTO);

    ReactivoResponseDTO delete(UUID externalId);

    ReactivoResponseDTO getByExternalId(UUID externalId);

    List<ReactivoResponseDTO> getAll(String nombre, Integer nivelPeligro, Boolean esPrecursorQuimico);
}
