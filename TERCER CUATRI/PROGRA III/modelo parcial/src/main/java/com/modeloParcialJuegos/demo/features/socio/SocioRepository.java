package com.modeloParcialJuegos.demo.features.socio;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.Optional;
import java.util.UUID;

@Repository
public interface SocioRepository extends JpaRepository<SocioEntity, Long> {
    Optional<SocioEntity> findByExternalId(UUID externalId);

    Optional<SocioEntity> findByDniAndEmail(String dni, String email);
}
