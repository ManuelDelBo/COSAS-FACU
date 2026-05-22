package com.modeloParcialJuegos.demo.features.juego;

import org.modelmapper.ModelMapper;
import org.springframework.stereotype.Component;

@Component
public class JuegoMapper {
    public final ModelMapper modelMapper;


    public JuegoMapper(ModelMapper modelMapper) {
        this.modelMapper = modelMapper;
    }

    public JuegoResponseDTO toResponse(JuegoEntity juegoEntity) {
        JuegoResponseDTO responseDTO = modelMapper.map(juegoEntity, JuegoResponseDTO.class);
        return responseDTO;
    }

    public JuegoEntity toEntity(JuegoRequestDTO juegoRequestDTO) {
        JuegoEntity juegoEntity = modelMapper.map(juegoRequestDTO, JuegoEntity.class);
        return juegoEntity;
    }

    public void updateEntity(JuegoEntity juegoEntity, JuegoRequestDTO juegoRequestDTO) {
        modelMapper.map(juegoRequestDTO, juegoEntity);
    }
}
