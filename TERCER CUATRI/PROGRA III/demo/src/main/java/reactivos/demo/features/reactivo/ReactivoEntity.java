package reactivos.demo.features.reactivo;

import jakarta.persistence.*;
import lombok.*;
import org.hibernate.annotations.UuidGenerator;
import reactivos.demo.features.lote.LoteEntity;

import java.util.List;
import java.util.UUID;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Builder
@Entity
@Table(name = "reactivos")
public class ReactivoEntity {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(name = "externalId", nullable = false, unique = true)
    @UuidGenerator
    private UUID externalId;

    @Column(name = "nombre", nullable = false)
    private String nombre;

    @Column(name = "nivelPeligro", nullable = false)
    private Integer nivelPeligro;

    @Column(name = "esPrecursorQuimico", nullable = false)
    private Boolean esPrecursorQuimico;

    @Column(name = "activo", nullable = false)
    private Boolean activo;

    @OneToMany(mappedBy = "reactivo")
    private List<LoteEntity> lotes;
}
