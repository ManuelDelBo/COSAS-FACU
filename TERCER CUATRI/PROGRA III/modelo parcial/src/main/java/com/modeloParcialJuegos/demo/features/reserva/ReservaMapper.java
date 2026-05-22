package com.modeloParcialJuegos.demo.features.reserva;

import com.modeloParcialJuegos.demo.features.juego.JuegoEntity;
import com.modeloParcialJuegos.demo.features.socio.SocioEntity;
import org.modelmapper.ModelMapper;
import org.springframework.stereotype.Component;

@Component
public class ReservaMapper {
    public ModelMapper modelMapper;

    public ReservaMapper(ModelMapper modelMapper) {
        this.modelMapper = modelMapper;
    }

    public ReservaResponseDTO toResponse(ReservaEntity reservaEntity) {
        ReservaResponseDTO responseDTO = modelMapper.map(reservaEntity, ReservaResponseDTO.class);

        responseDTO.setJuegoId(reservaEntity.getJuego().getExternalId());
        responseDTO.setJuego(reservaEntity.getJuego().getNombre());
        responseDTO.setSocioId(reservaEntity.getSocio().getExternalId());
        responseDTO.setSocio(reservaEntity.getSocio().getNombre());

        return responseDTO;
    }

    public ReservaEntity toEntity(
            ReservaRequestDTO reservaRequestDTO,
            JuegoEntity juegoEntity,
            SocioEntity socioEntity) {

        return ReservaEntity.builder()
                .fechaReserva(reservaRequestDTO.getFechaReserva())
                .fechaRetiro(reservaRequestDTO.getFechaRetiro())
                .cantidad(reservaRequestDTO.getCantidad())
                .estado(reservaRequestDTO.getEstado())
                .juego(juegoEntity)
                .socio(socioEntity)
                .build();

        /*ReservaEntity reservaEntity = modelMapper.map(reservaRequestDTO, ReservaEntity.class);

        reservaEntity.setJuego(juegoEntity);
        reservaEntity.setSocio(socioEntity);

        return reservaEntity;

         */
    }

    public void updateEntity(ReservaEntity reservaEntity,
                             ReservaRequestDTO reservaRequestDTO,
                             JuegoEntity juegoEntity,
                             SocioEntity socioEntity) {

        modelMapper.map(reservaRequestDTO, reservaEntity);

        reservaEntity.setJuego(juegoEntity);
        reservaEntity.setSocio(socioEntity);
    }

}
