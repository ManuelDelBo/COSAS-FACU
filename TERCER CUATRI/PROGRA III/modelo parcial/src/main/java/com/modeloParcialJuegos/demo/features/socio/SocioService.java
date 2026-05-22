package com.modeloParcialJuegos.demo.features.socio;

import com.modeloParcialJuegos.demo.exception.RecursoNoEncontradoException;
import com.modeloParcialJuegos.demo.exception.ReglaNegocioException;
import com.modeloParcialJuegos.demo.features.juego.JuegoEntity;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.UUID;

@Service
@AllArgsConstructor
public class SocioService implements ISocioService{

    private final SocioRepository socioRepository;
    private final SocioMapper socioMapper;


    @Override
    public SocioResponseDTO create(SocioRequestDTO socioRequestDTO) {
        if(socioRepository.findByDniAndEmail(
                socioRequestDTO.getDni(),
                socioRequestDTO.getEmail()).isPresent()) {
            throw new ReglaNegocioException("El DNI ya existe");
        }
        SocioEntity socioEntity = socioMapper.toEntity(socioRequestDTO);
        socioEntity = socioRepository.save(socioEntity);
        return socioMapper.toResponse(socioEntity);
    }

    @Override
    public SocioResponseDTO update(UUID externalId, SocioRequestDTO socioRequestDTO) {
        SocioEntity socioEntity =
                socioRepository
                        .findByExternalId(externalId)
                        .orElseThrow(() ->
                                new RecursoNoEncontradoException("Socio no encontrado"));
        socioMapper.updateEntity(socioEntity, socioRequestDTO);

        socioEntity = socioRepository.save(socioEntity);
        return socioMapper.toResponse(socioEntity);
    }

    @Override
    public void delete(UUID externalId) {
        SocioEntity socioEntity =
                socioRepository
                        .findByExternalId(externalId)
                        .orElseThrow(() ->
                                new RecursoNoEncontradoException("Socio no encontrado"));
        socioEntity.setActivo(false);
        socioRepository.save(socioEntity);
    }

    @Override
    public SocioResponseDTO getById(UUID externalId) {
        SocioEntity socioEntity =
                socioRepository
                        .findByExternalId(externalId)
                        .orElseThrow(() ->
                                new RecursoNoEncontradoException("Socio no encontrado"));
        return socioMapper.toResponse(socioEntity);
    }

    @Override
    public List<SocioResponseDTO> getAll() {
        return socioRepository.findAll()
                .stream()
                .map(socioMapper::toResponse)
                .toList();
    }
}
