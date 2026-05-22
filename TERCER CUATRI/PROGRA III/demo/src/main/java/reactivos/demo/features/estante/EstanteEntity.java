package reactivos.demo.features.estante;

import jakarta.persistence.*;
import lombok.*;
import org.hibernate.annotations.UuidGenerator;
import reactivos.demo.features.lote.LoteEntity;

import java.math.BigDecimal;
import java.util.List;
import java.util.UUID;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Builder
@Entity
@Table(name = "estantes")
public class EstanteEntity {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(name = "externalId", nullable = false, unique = true)
    @UuidGenerator
    private UUID externalId;

    @Column(name = "codigoAlmacen", nullable = false)
    private String codigoAlmacen;

    @Column(name = "capacidadMaxKg", nullable = false)
    private BigDecimal capacidadMaxKg;

    @Column(name = "riesgoLimite", nullable = false)
    private BigDecimal riesgoLimite;

    @Column(name = "nivelRiesgoActual", nullable = false)
    private BigDecimal nivelRiesgoActual;

    @OneToMany(mappedBy = "estante")
    private List<LoteEntity> lotes;
}
