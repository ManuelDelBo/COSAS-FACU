package com.modeloParcialJuegos.demo.features.juego;

import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.PositiveOrZero;
import jakarta.validation.constraints.Size;
import lombok.*;

@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
@Builder
public class JuegoRequestDTO {

    @NotBlank(message = "El nombre no puede estar vacio")
    @Size(min = 3, max = 50, message = "El nombre debe tener entre 3 y 50 caracteres")
    private String nombre;

    @NotBlank(message = "La categoria no puede estar vacia")
    @Size(min = 3, max = 50, message = "La categoria debe tener entre 3 y 50 caracteres")
    private String categoria;

    @NotNull(message = "La edad minima no puede estar vacia")
    @PositiveOrZero(message = "La edad minima debe ser mayor o igual a 0")
    private Integer edadMinima;

    @NotNull(message = "El stock disponible no puede estar vacio")
    @PositiveOrZero(message = "El stock disponible debe ser mayor o igual a 0")
    private Integer stockDisponible;

    @NotNull(message = "El activo no puede estar vacio")
    private Boolean activo;
}
