package com.modeloParcialJuegos.demo.features.juego;


import java.util.List;
import java.util.UUID;

public interface IJuegoService {
    JuegoResponseDTO create(JuegoRequestDTO juegoRequestDTO);
    JuegoResponseDTO update(UUID externalId, JuegoRequestDTO juegoRequestDTO);
    JuegoResponseDTO delete(UUID externalId);
    List<JuegoResponseDTO> getAll(Boolean activo);
    JuegoResponseDTO getById(UUID externalId);

}
