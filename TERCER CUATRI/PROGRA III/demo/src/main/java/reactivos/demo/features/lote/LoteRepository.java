package reactivos.demo.features.lote;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.Optional;
import java.util.UUID;

@Repository
public interface LoteRepository extends JpaRepository<LoteEntity, Long> {
    Optional<LoteEntity> findByExternalId(UUID externalId);

    Optional<LoteEntity> existsByNroLote(String nroLote);

    List<LoteEntity> findByEstanteExternalId(UUID estanteExternalId);

    List<LoteEntity> findByReactivoExternalId(UUID reactivoExternalId);
}
