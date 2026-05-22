package reactivos.demo.features.reactivo;

import jakarta.validation.Valid;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.UUID;

@RestController
@RequestMapping("/reactivos")
public class ReactivoController {

    private final IReactivoService reactivoService;

    public ReactivoController(IReactivoService reactivoService) {
        this.reactivoService = reactivoService;
    }

    @PostMapping
    public ResponseEntity<ReactivoResponseDTO> create(
            @Valid
            @RequestBody ReactivoRequestDTO reactivoRequestDTO) {
        return ResponseEntity
                .status(201)
                .body(reactivoService.create(reactivoRequestDTO));
    }
    @PatchMapping("/{externalId}")
    public ResponseEntity<ReactivoResponseDTO> update(
            @Valid
            @PathVariable UUID externalId,
            @RequestBody ReactivoRequestDTO reactivoRequestDTO) {
        return ResponseEntity
                .status(200)
                .body(reactivoService.update(externalId, reactivoRequestDTO));
    }

    @DeleteMapping("/{externalId}")
    public ResponseEntity<ReactivoResponseDTO> delete(@PathVariable UUID externalId) {
        return ResponseEntity
                .status(200)
                .body(reactivoService.delete(externalId));
    }

    @GetMapping("/{externalId}")
    public ResponseEntity<ReactivoResponseDTO> getByExternalId(@PathVariable UUID externalId) {
        return ResponseEntity
                .status(200)
                .body(reactivoService.getByExternalId(externalId));
    }

    @GetMapping
    public ResponseEntity<List<ReactivoResponseDTO>> getAll(
            @RequestParam (required = false) String nombre,
            @RequestParam (required = false) Integer nivelPeligro,
            @RequestParam (required = false) Boolean esPrecursorQuimico) {
        return ResponseEntity
                .status(200)
                .body(reactivoService.getAll(nombre, nivelPeligro, esPrecursorQuimico));
    }
}
