package com.modeloParcialJuegos.demo.features.juego;

import lombok.*;

import java.util.UUID;

@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
@Builder
public class JuegoResponseDTO {
    private UUID externalId;
    private String nombre;
    private String categoria;
    private Integer edadMinima;
    private Integer stockDisponible;
    private Boolean activo;
}
