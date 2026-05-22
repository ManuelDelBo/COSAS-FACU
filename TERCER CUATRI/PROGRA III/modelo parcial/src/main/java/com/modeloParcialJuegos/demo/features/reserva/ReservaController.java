package com.modeloParcialJuegos.demo.features.reserva;

import jakarta.validation.Valid;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.UUID;

@RestController
@RequestMapping("/reservas")
public class ReservaController {
    private final IReservaService reservaService;

    public ReservaController(IReservaService reservaService) {
        this.reservaService = reservaService;
    }

    @GetMapping("/{externalId}")
    public ResponseEntity<ReservaResponseDTO> getById(@PathVariable UUID externalId) {
        return ResponseEntity.ok(reservaService.getById(externalId));
    }

    @PostMapping
    public ResponseEntity<ReservaResponseDTO> create(
            @Valid
            @RequestBody ReservaRequestDTO reservaRequestDTO) {
        return ResponseEntity
                .status(201)
                .body(reservaService.create(reservaRequestDTO));
    }

    @GetMapping
    public ResponseEntity<List<ReservaResponseDTO>> getAll(
            @RequestParam (required = false) estadoEnum estado) {

        return ResponseEntity.ok
                (reservaService.getAll(estado));
    }

    @GetMapping(params = "socioId")
    public ResponseEntity<List<ReservaResponseDTO>> getBySocio(
            @RequestParam UUID socioId) {
        return ResponseEntity.ok(reservaService.getBySocio(socioId));
    }

    @PatchMapping("/{externalId}/cancelar")
    public ResponseEntity<Void> cancelar(@Valid @PathVariable UUID externalId) {
        reservaService.cancelar(externalId);

        return ResponseEntity.ok().build();
    }

}
