package reactivos.demo.features.estante;

import jakarta.validation.Valid;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.UUID;

@RestController
@RequestMapping("/estantes")
public class EstanteController {

    private final IEstanteService estanteService;

    public EstanteController(IEstanteService estanteService) {
        this.estanteService = estanteService;
    }

    @PostMapping
    public ResponseEntity<EstanteResponseDTO> create(
            @Valid
            @RequestBody EstanteRequestDTO estanteRequestDTO) {
        return ResponseEntity
                .status(201)
                .body(estanteService.create(estanteRequestDTO));
    }

    @PatchMapping("/{externalId}")
    public ResponseEntity<EstanteResponseDTO> update(
            @Valid
            @PathVariable UUID externalId,
            @RequestBody EstanteRequestDTO estanteRequestDTO) {
        return ResponseEntity
                .status(200)
                .body(estanteService.update(externalId, estanteRequestDTO));
    }

    @DeleteMapping("/{externalId}")
    public ResponseEntity<Void> delete(@PathVariable UUID externalId) {
        estanteService.delete(externalId);
        return ResponseEntity.noContent().build();
    }

    @GetMapping("/{externalId}")
    public ResponseEntity<EstanteResponseDTO> getByExternalId(@PathVariable UUID externalId) {
        return ResponseEntity.ok(estanteService.getByExternalId(externalId));
    }

    @GetMapping
    public ResponseEntity<List<EstanteResponseDTO>> getAll() {
        return ResponseEntity.ok(estanteService.getAll());
    }
}
