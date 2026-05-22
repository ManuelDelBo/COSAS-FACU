package reactivos.demo.features.reactivo;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.JpaSpecificationExecutor;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.Optional;
import java.util.UUID;

@Repository
public interface ReactivoRepository extends JpaRepository<ReactivoEntity, Long>, JpaSpecificationExecutor<ReactivoEntity> {
    Optional<ReactivoEntity> findByExternalId(UUID externalId);

    Optional<ReactivoEntity> findByNombre(String nombre);

    List<ReactivoEntity> findByNivelPeligro(Integer nivelPeligro);

    List<ReactivoEntity> findByEsPrecursorQuimico(Boolean esPrecursorQuimico);



}
