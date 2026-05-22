package com.modeloParcialJuegos.demo.features.reserva;

import lombok.*;

import java.time.LocalDate;
import java.util.UUID;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class ReservaResponseDTO {
    private UUID externalId;
    private LocalDate fechaReserva;
    private LocalDate fechaRetiro;
    private Integer cantidad;
    private estadoEnum estado;

    private UUID juegoId;
    private String juego;

    private UUID socioId;
    private String socio;

}
