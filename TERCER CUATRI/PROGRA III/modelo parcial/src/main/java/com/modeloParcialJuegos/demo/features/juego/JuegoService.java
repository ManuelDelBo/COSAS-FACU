package com.modeloParcialJuegos.demo.features.juego;

import com.modeloParcialJuegos.demo.exception.RecursoNoEncontradoException;
import com.modeloParcialJuegos.demo.exception.ReglaNegocioException;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.PathVariable;

import java.util.List;
import java.util.UUID;

@Service
@AllArgsConstructor
public class JuegoService implements IJuegoService {

    private final JuegoRepository juegoRepository;
    private final JuegoMapper juegoMapper;


    @Override
    public JuegoResponseDTO create(JuegoRequestDTO juegoRequestDTO) {
        if(juegoRepository.existsByNombre(juegoRequestDTO.getNombre())) {
            throw new ReglaNegocioException("Juego ya registrado");
        }

        JuegoEntity juegoEntity = juegoMapper.toEntity(juegoRequestDTO);
        juegoEntity = juegoRepository.save(juegoEntity);
        return juegoMapper.toResponse(juegoEntity);
    }

    @Override
    public JuegoResponseDTO update(UUID externalId, JuegoRequestDTO juegoRequestDTO) {
        JuegoEntity juegoEntity =
                juegoRepository
                        .findByExternalId(externalId)
                        .orElseThrow(() -> new RecursoNoEncontradoException("Juego no encontrado"));
        juegoMapper.updateEntity(juegoEntity, juegoRequestDTO);
        juegoEntity = juegoRepository.save(juegoEntity);
        return juegoMapper.toResponse(juegoEntity);
    }

    @Override
    public JuegoResponseDTO delete(UUID externalId) {
        JuegoEntity juegoEntity =
                juegoRepository
                        .findByExternalId(externalId)
                        .orElseThrow(() -> new RecursoNoEncontradoException("Juego no encontrado"));
        juegoEntity.setActivo(false);
        juegoRepository.save(juegoEntity);
        return juegoMapper.toResponse(juegoEntity);
    }

    @Override
    public List<JuegoResponseDTO> getAll(Boolean activo) {
        if(activo == null) {
            return juegoRepository.findAll()
                    .stream()
                    .map(juegoMapper::toResponse)
                    .toList();

        }
        return juegoRepository.findAllByActivo(activo)
                .stream()
                .map(juegoMapper::toResponse)
                .toList();
    }

    @Override
    public JuegoResponseDTO getById(@PathVariable UUID externalId) {
        JuegoEntity juegoEntity =
                juegoRepository
                        .findByExternalId(externalId)
                        .orElseThrow(() -> new RecursoNoEncontradoException("Juego no encontrado"));
        return juegoMapper.toResponse(juegoEntity);
    }

}
