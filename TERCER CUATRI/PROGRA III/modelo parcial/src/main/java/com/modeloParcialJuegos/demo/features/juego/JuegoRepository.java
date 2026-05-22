package com.modeloParcialJuegos.demo.features.juego;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.Optional;
import java.util.UUID;

@Repository
public interface JuegoRepository extends JpaRepository<JuegoEntity, Long> {

    Optional<JuegoEntity> findByExternalId(UUID externalId);

    List<JuegoEntity> findAllByActivo(Boolean activo);

    Boolean existsByNombre(String nombre);
}
