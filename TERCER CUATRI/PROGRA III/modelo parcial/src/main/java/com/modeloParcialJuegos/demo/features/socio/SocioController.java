package com.modeloParcialJuegos.demo.features.socio;

import jakarta.validation.Valid;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.UUID;

@RestController
@RequestMapping("/socios")
public class SocioController {

    private final ISocioService socioService;

    public SocioController(ISocioService socioService) {
        this.socioService = socioService;
    }

    @GetMapping("{externalId}")
    public ResponseEntity<SocioResponseDTO> getById(@PathVariable UUID externalId) {
        return ResponseEntity.ok(socioService.getById(externalId));
    }

    @GetMapping
    public ResponseEntity<List<SocioResponseDTO>> getAll() {
        return ResponseEntity.ok(socioService.getAll());
    }

    @PostMapping
    public ResponseEntity<SocioResponseDTO> create(
            @Valid
            @RequestBody SocioRequestDTO socioRequestDTO) {
        return ResponseEntity
                .status(201)
                .body(socioService.create(socioRequestDTO));
    }
}
