package com.modeloParcialJuegos.demo.features.juego;

import com.modeloParcialJuegos.demo.features.reserva.ReservaEntity;
import jakarta.persistence.*;
import lombok.*;
import org.hibernate.annotations.UuidGenerator;

import java.util.List;
import java.util.UUID;

@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
@Builder
@Entity
@Table(name = "juego")
public class JuegoEntity {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(name = "externalId", nullable = false)
    @UuidGenerator
    private UUID externalId;

    @Column(name = "nombre", nullable = false)
    private String nombre;

    @Column(name = "categoria", nullable = false)
    private String categoria;

    @Column(name = "edadMinima", nullable = false)
    private Integer edadMinima;

    @Column(name = "stockDisponible", nullable = false)
    private Integer stockDisponible;

    @Column(name = "activo", nullable = false)
    private Boolean activo;

    @OneToMany(mappedBy = "juego")
    private List<ReservaEntity> reserva;
}
