package reactivos.demo.features.reactivo;

import lombok.*;

import java.util.UUID;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class ReactivoResponseDTO {

    private UUID externalId;
    private String nombre;
    private Integer nivelPeligro;
    private Boolean esPrecursorQuimico;
    private Boolean activo;
}
