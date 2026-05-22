package com.modeloParcialJuegos.demo.features.reserva;

import java.util.List;
import java.util.UUID;

public interface IReservaService {
    ReservaResponseDTO create(ReservaRequestDTO reservaRequestDTO);
    ReservaResponseDTO update(UUID externalId, ReservaRequestDTO reservaRequestDTO);
    void cancelar(UUID externalId);
    ReservaResponseDTO getById(UUID externalId);
    List<ReservaResponseDTO> getAll(estadoEnum estado);
    List<ReservaResponseDTO> getBySocio(UUID socioExternalId);


}
