package reactivos.demo.features.estante;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.Optional;
import java.util.UUID;

@Repository
public interface EstanteRepository extends JpaRepository<EstanteEntity, Long> {
    Optional<EstanteEntity> findByExternalId(UUID externalId);

    Boolean existsByCodigoAlmacen(String codigoAlmacen);
}
