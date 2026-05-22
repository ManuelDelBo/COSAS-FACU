package reactivos.demo.features.reactivo;

import org.modelmapper.ModelMapper;
import org.springframework.stereotype.Component;

@Component
public class ReactivoMapper {

    private final ModelMapper modelMapper;
    public ReactivoMapper(ModelMapper modelMapper) {
        this.modelMapper = modelMapper;
    }

    public ReactivoResponseDTO toResponse(ReactivoEntity reactivoEntity) {
        ReactivoResponseDTO reactivoResponseDTO = modelMapper.map(reactivoEntity, ReactivoResponseDTO.class);
        return reactivoResponseDTO;
    }

    public ReactivoEntity toEntity(ReactivoRequestDTO reactivoRequestDTO) {
        ReactivoEntity reactivoEntity = modelMapper.map(reactivoRequestDTO, ReactivoEntity.class);
        return reactivoEntity;
    }

    public void updateEntity(ReactivoEntity reactivoEntity, ReactivoRequestDTO reactivoRequestDTO) {
        modelMapper.map(reactivoRequestDTO, reactivoEntity);
    }
}
