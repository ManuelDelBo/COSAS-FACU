package reactivos.demo.features.lote;

import jakarta.persistence.*;
import lombok.*;
import org.hibernate.annotations.UuidGenerator;
import reactivos.demo.features.estante.EstanteEntity;
import reactivos.demo.features.reactivo.ReactivoEntity;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.util.UUID;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Builder
@Entity
@Table(name = "lotes")
public class LoteEntity {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(name = "externalId", nullable = false, unique = true)
    @UuidGenerator
    private UUID externalId;

    @Column(name = "nroLote", nullable = false, unique = true)
    private String nroLote;

    @Column(name = "fechaRecepcion", nullable = false)
    private LocalDate fechaRecepcion;

    @Column(name = "fechaVencimiento", nullable = false)
    private LocalDate fechaVencimiento;

    @Column(name = "cantidadKg", nullable = false)
    private BigDecimal cantidadKg;

    @ManyToOne
    @JoinColumn(name = "reactivoId")
    private ReactivoEntity reactivo;

    @ManyToOne
    @JoinColumn(name = "estanteId", nullable = true)
    private EstanteEntity estante;
}
