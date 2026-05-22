package reactivos.demo.features.reactivo;

import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.PositiveOrZero;
import jakarta.validation.constraints.Size;
import lombok.*;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class ReactivoRequestDTO {
    @NotBlank(message = "El nombre es requerido")
    @Size(min = 3, max = 50, message = "El nombre debe tener entre 3 y 50 caracteres")
    private String nombre;

    @NotNull(message = "El nivel de peligro es requerido")
    @PositiveOrZero(message = "El nivel de peligro debe ser un número no negativo")
    private Integer nivelPeligro;

    @NotNull(message = "El esPrecursorQuimico es requerido")
    private Boolean esPrecursorQuimico;

    @NotNull(message = "El activo es requerido")
    private Boolean activo;
}
