package reactivos.demo.features.estante;

import lombok.*;

import java.math.BigDecimal;
import java.util.UUID;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class EstanteResponseDTO {
    private UUID externalId;
    private String codigoAlmacen;
    private BigDecimal capacidadMaxKg;
    private Integer riesgoLimite;
    private BigDecimal nivelRiesgoActual;
}
