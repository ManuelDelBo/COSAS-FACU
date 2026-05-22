package reactivos.demo.features.estante;

import jakarta.validation.constraints.*;
import lombok.*;

import java.math.BigDecimal;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class EstanteRequestDTO {
    @NotBlank(message = "El código de almacen es requerido")
    @Size(min = 3, max = 50, message = "El código de almacen debe tener entre 3 y 50 caracteres")
    private String codigoAlmacen;

    @NotNull(message = "La capacidad máxima es requerida")
    @PositiveOrZero(message = "La capacidad máxima debe ser un número no negativo")
    private BigDecimal capacidadMaxKg;

    @NotNull(message = "El riesgo límite es requerido")
    @PositiveOrZero(message = "El riesgo límite debe ser un número no negativo")
    private Integer riesgoLimite;

}
