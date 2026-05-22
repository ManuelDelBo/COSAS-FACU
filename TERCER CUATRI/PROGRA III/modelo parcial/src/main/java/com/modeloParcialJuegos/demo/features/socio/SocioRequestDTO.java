package com.modeloParcialJuegos.demo.features.socio;

import jakarta.validation.constraints.*;
import lombok.*;

import java.time.LocalDate;

@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
@Builder
public class SocioRequestDTO {
    @NotBlank(message = "El nombre no puede estar vacio")
    @Size(min = 3, max = 50, message = "El nombre debe tener entre 3 y 50 caracteres")
    private String nombre;

    @NotBlank(message = "El email no puede estar vacio")
    @Email(message = "El email no es valido")
    private String email;

    @NotBlank(message = "El DNI no puede estar vacio")
    @Pattern(regexp = "\\d{7,8}", message = "El DNI debe tener 7 u 8 números")
    private String dni;

    @NotNull(message = "La fecha no puede estar vacía")
    @PastOrPresent(message = "La fecha no puede ser futura")
    private LocalDate fechaAlta;

    @NotNull(message = "El activo no puede estar vacio")
    private Boolean activo;

}
