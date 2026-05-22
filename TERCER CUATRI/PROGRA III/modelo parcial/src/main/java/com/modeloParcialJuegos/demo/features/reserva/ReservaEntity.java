package com.modeloParcialJuegos.demo.features.reserva;

import com.modeloParcialJuegos.demo.features.juego.JuegoEntity;
import com.modeloParcialJuegos.demo.features.socio.SocioEntity;
import jakarta.persistence.*;
import lombok.*;
import org.hibernate.annotations.UuidGenerator;

import java.time.LocalDate;
import java.util.UUID;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Builder
@Entity
@Table(name = "reservas")
public class ReservaEntity {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @UuidGenerator
    @Column(name = "externalId", nullable = false)
    private UUID externalId;

    @Column(name = "fechaReserva", nullable = false)
    private LocalDate fechaReserva;

    @Column(name = "fechaRetiro", nullable = false)
    private LocalDate fechaRetiro;

    @Column(name = "cantidad", nullable = false)
    private Integer cantidad;

    @Enumerated(EnumType.STRING)
    @Column(name = "estado", nullable = false)
    private estadoEnum estado;

    @ManyToOne()
    @JoinColumn(name = "juegoId", nullable = false)
    private JuegoEntity juego;

    @ManyToOne()
    @JoinColumn(name = "socioId", nullable = false)
    private SocioEntity socio;
}
