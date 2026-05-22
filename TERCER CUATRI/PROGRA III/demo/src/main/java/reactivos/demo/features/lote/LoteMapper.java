package reactivos.demo.features.lote;

import org.modelmapper.ModelMapper;
import org.springframework.stereotype.Component;
import reactivos.demo.features.estante.EstanteEntity;
import reactivos.demo.features.reactivo.ReactivoEntity;

@Component
public class LoteMapper {

    private final ModelMapper modelMapper;

    public LoteMapper(ModelMapper modelMapper) {
        this.modelMapper = modelMapper;
    }

    public LoteResponseDTO toResponse(
            LoteEntity loteEntity) {

        LoteResponseDTO loteResponseDTO = modelMapper.map(loteEntity, LoteResponseDTO.class);
        loteResponseDTO.setReactivoExternalId(loteEntity.getReactivo().getExternalId());
        loteResponseDTO.setEstanteExternalId(loteEntity.getEstante().getExternalId());
        return loteResponseDTO;
    }

    public LoteEntity toEntity(LoteRequestDTO loteRequestDTO) {
        return LoteEntity.builder()
                .nroLote(loteRequestDTO.getNroLote())
                .fechaRecepcion(loteRequestDTO.getFechaRecepcion())
                .fechaVencimiento(loteRequestDTO.getFechaVencimiento())
                .cantidadKg(loteRequestDTO.getCantidadKg())
                .build();
    }

    public void updateEntity(LoteEntity loteEntity,
                             LoteRequestDTO loteRequestDTO) {
        loteEntity.setNroLote(loteRequestDTO.getNroLote());
        loteEntity.setFechaRecepcion(loteRequestDTO.getFechaRecepcion());
        loteEntity.setFechaVencimiento(loteRequestDTO.getFechaVencimiento());
        loteEntity.setCantidadKg(loteRequestDTO.getCantidadKg());
    }
}
