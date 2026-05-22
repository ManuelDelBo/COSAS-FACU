package com.modeloParcialJuegos.demo.features.socio;

import java.util.List;
import java.util.UUID;

public interface ISocioService {
    SocioResponseDTO create(SocioRequestDTO socioRequestDTO);
    SocioResponseDTO update(UUID externalId, SocioRequestDTO socioRequestDTO);
    void delete(UUID externalId);
    SocioResponseDTO getById(UUID externalId);
    List<SocioResponseDTO> getAll();
}
