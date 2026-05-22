package com.modeloParcialJuegos.demo.features.socio;

import org.modelmapper.ModelMapper;
import org.springframework.stereotype.Component;

@Component
public class SocioMapper {
    public final ModelMapper modelMapper;

    public SocioMapper(ModelMapper modelMapper) {
        this.modelMapper = modelMapper;
    }

    public SocioResponseDTO toResponse(SocioEntity socioEntity) {
        SocioResponseDTO responseDTO = modelMapper.map(socioEntity, SocioResponseDTO.class);
        return responseDTO;
    }

    public SocioEntity toEntity(SocioRequestDTO socioRequestDTO) {
        SocioEntity socioEntity = modelMapper.map(socioRequestDTO, SocioEntity.class);
        return socioEntity;
    }

    public void updateEntity(SocioEntity socioEntity, SocioRequestDTO socioRequestDTO) {
        modelMapper.map(socioRequestDTO, socioEntity);
    }
}
