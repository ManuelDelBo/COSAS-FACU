package reactivos.demo.features.lote;

import jakarta.validation.Valid;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.math.BigDecimal;
import java.util.List;
import java.util.UUID;

@RestController
@RequestMapping("/lotes")
public class LoteController {
    private final ILoteService loteService;

    public LoteController(ILoteService loteService) {
        this.loteService = loteService;
    }

    @PostMapping
    public ResponseEntity<LoteResponseDTO> create(
            @Valid
            @RequestBody LoteRequestDTO loteRequestDTO) {
        return ResponseEntity
                .status(201)
                .body(loteService.create(loteRequestDTO));
    }

    @PatchMapping("/{externalId}")
    public ResponseEntity<LoteResponseDTO> update(
            @Valid
            @PathVariable UUID externalId,
            @RequestBody LoteRequestDTO loteRequestDTO) {
        return ResponseEntity
                .status(200)
                .body(loteService.update(externalId, loteRequestDTO));
    }

    @GetMapping("/{externalId}")
    public ResponseEntity<LoteResponseDTO> getByExternalId(@PathVariable UUID externalId) {
        return ResponseEntity
                .status(200)
                .body(loteService.getByExternalId(externalId));
    }

    @GetMapping
    public ResponseEntity<List<LoteResponseDTO>> getAll() {
        return ResponseEntity
                .status(200)
                .body(loteService.getAll());
    }

    @PostMapping("/{externalId}/consumir")
    public ResponseEntity<LoteResponseDTO> consumir(
            @Valid
            @PathVariable UUID externalId,
            @RequestBody BigDecimal cantidadKg) {
        return ResponseEntity
                .status(200)
                .body(loteService.consumir(externalId, cantidadKg));
    }

}
