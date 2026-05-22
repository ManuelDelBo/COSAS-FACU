package reactivos.demo.features.lote;

import jakarta.validation.constraints.*;
import lombok.*;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.util.UUID;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class LoteRequestDTO {

    @NotBlank(message = "El número de lote es requerido")
    private String nroLote;

    @NotNull(message = "La fecha de recepción es requerida")
    private LocalDate fechaRecepcion;

    @NotNull(message = "La fecha de vencimiento es requerida")
    @Future(message = "La fecha de vencimiento debe ser futura")
    private LocalDate fechaVencimiento;

    @NotNull(message = "La cantidad es requerida")
    @PositiveOrZero(message = "La cantidad debe ser un número no negativo")
    private BigDecimal cantidadKg;

    @NotNull(message = "El reactivo es requerido")
    private UUID reactivoExternalId;

    @NotNull(message = "El estante es requerido")
    private UUID estanteExternalId;

}
