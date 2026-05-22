package reactivos.demo.features.lote;

import jakarta.validation.constraints.NotNull;
import lombok.*;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.util.UUID;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class LoteResponseDTO {
    private UUID externalId;
    private String nroLote;
    private LocalDate fechaRecepcion;
    private LocalDate fechaVencimiento;
    private BigDecimal cantidadKg;
    private UUID reactivoExternalId;
    private UUID estanteExternalId;
}
