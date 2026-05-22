package com.modeloParcialJuegos.demo.features.reserva;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.Optional;
import java.util.UUID;

@Repository
public interface ReservaRepository extends JpaRepository<ReservaEntity, Long> {
    Optional<ReservaEntity> findByExternalId(UUID externalId);
    List<ReservaEntity> findAllBySocioExternalId(UUID socioId);

    List<ReservaEntity> findAllByEstado(estadoEnum estado);
}
