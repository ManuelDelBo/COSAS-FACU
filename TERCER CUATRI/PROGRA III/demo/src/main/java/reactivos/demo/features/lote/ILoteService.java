package reactivos.demo.features.lote;

import java.math.BigDecimal;
import java.util.List;
import java.util.UUID;

public interface ILoteService {
    LoteResponseDTO create(LoteRequestDTO loteRequestDTO);
    LoteResponseDTO update(UUID externalId, LoteRequestDTO loteRequestDTO);
    LoteResponseDTO getByExternalId(UUID externalId);
    List<LoteResponseDTO> getAll();
    LoteResponseDTO consumir(UUID externalId, BigDecimal cantidadKg);
}
