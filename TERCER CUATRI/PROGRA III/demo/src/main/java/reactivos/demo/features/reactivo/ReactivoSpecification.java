package reactivos.demo.features.reactivo;

import org.springframework.data.jpa.domain.Specification;
import reactivos.demo.features.reactivo.ReactivoEntity;
import reactivos.demo.features.reactivo.ReactivoResponseDTO;

public class ReactivoSpecification {

    public static Specification<ReactivoEntity> hasNombre(String nombre) {
        return (root, query, cb) ->
                nombre == null ? null : cb.like(root.get("nombre"), "%" + nombre + "%");
    }

    public static Specification<ReactivoEntity> hasNivelPeligro(Integer nivelPeligro) {
        return (root, query, cb) ->
                nivelPeligro == null ? null : cb.equal(root.get("nivelPeligro"), nivelPeligro);
    }

    public static Specification<ReactivoEntity> hasEsPrecursorQuimico(Boolean esPrecursorQuimico) {
        return (root, query, cb) ->
                esPrecursorQuimico == null ? null : cb.equal(root.get("esPrecursorQuimico"), esPrecursorQuimico);
    }
}
