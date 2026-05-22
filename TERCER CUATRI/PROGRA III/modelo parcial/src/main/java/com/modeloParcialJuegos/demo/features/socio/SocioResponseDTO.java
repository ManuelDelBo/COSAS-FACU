package com.modeloParcialJuegos.demo.features.socio;

import lombok.*;

import java.time.LocalDate;
import java.util.UUID;

@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
@Builder
public class SocioResponseDTO {
    private UUID externalId;
    private String nombre;
    private String email;
    private String dni;
    private LocalDate fechaAlta;
    private boolean activo;
}
