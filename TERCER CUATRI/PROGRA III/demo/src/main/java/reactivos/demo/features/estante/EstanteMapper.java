package reactivos.demo.features.estante;

import org.modelmapper.ModelMapper;
import org.springframework.stereotype.Component;

@Component
public class EstanteMapper {

    private final ModelMapper modelMapper;

    public EstanteMapper(ModelMapper modelMapper) {
        this.modelMapper = modelMapper;
    }


    public EstanteResponseDTO toResponse(EstanteEntity estanteEntity) {
        EstanteResponseDTO estanteResponseDTO = modelMapper.map(estanteEntity, EstanteResponseDTO.class);
        return estanteResponseDTO;
    }

    public EstanteEntity toEntity(EstanteRequestDTO estanteRequestDTO) {
        EstanteEntity estanteEntity = modelMapper.map(estanteRequestDTO, EstanteEntity.class);
        return estanteEntity;
    }

    public void updateEntity(EstanteEntity estanteEntity, EstanteRequestDTO estanteRequestDTO) {
        modelMapper.map(estanteRequestDTO, estanteEntity);
    }
}
