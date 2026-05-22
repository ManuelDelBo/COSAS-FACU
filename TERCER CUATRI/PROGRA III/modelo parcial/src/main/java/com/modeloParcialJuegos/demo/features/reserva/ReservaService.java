package com.modeloParcialJuegos.demo.features.reserva;

import com.modeloParcialJuegos.demo.exception.RecursoNoEncontradoException;
import com.modeloParcialJuegos.demo.exception.ReglaNegocioException;
import com.modeloParcialJuegos.demo.exception.StockInsuficienteException;
import com.modeloParcialJuegos.demo.features.juego.JuegoEntity;
import com.modeloParcialJuegos.demo.features.juego.JuegoRepository;
import com.modeloParcialJuegos.demo.features.socio.SocioEntity;
import com.modeloParcialJuegos.demo.features.socio.SocioRepository;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.UUID;

@Service
@AllArgsConstructor
public class ReservaService implements IReservaService {
    private final ReservaRepository reservaRepository;
    private final SocioRepository socioRepository;
    private final JuegoRepository juegoRepository;

    private final ReservaMapper reservaMapper;

    @Override
    public ReservaResponseDTO create(ReservaRequestDTO reservaRequestDTO) {
        JuegoEntity juegoEntity = juegoRepository
                .findByExternalId(reservaRequestDTO.getJuegoId())
                .orElseThrow(() ->
                        new RecursoNoEncontradoException("Juego no encontrado"));

        if (!juegoEntity.getActivo()) {
            throw new ReglaNegocioException("Juego no disponible");
        }
        if (juegoEntity.getStockDisponible() < reservaRequestDTO.getCantidad()) {
            throw new StockInsuficienteException("Stock insuficiente");
        }
        SocioEntity socioEntity = socioRepository
                .findByExternalId(reservaRequestDTO.getSocioId())
                .orElseThrow(() ->
                        new RecursoNoEncontradoException("Socio no encontrado"));
        if (!socioEntity.getActivo()) {
            throw new ReglaNegocioException("Socio no disponible");
        }
        ReservaEntity reservaEntity =
                reservaMapper.toEntity(
                        reservaRequestDTO,
                        juegoEntity,
                        socioEntity);

        reservaEntity = reservaRepository.save(reservaEntity);

        juegoEntity.setStockDisponible(
                juegoEntity.getStockDisponible() - reservaRequestDTO.getCantidad());
        juegoRepository.save(juegoEntity);

        return reservaMapper.toResponse(reservaEntity);
    }

    @Override
    public void cancelar(UUID externalId) {
        ReservaEntity reservaEntity =
                reservaRepository
                        .findByExternalId(externalId)
                        .orElseThrow(() ->
                                new RecursoNoEncontradoException("Reserva no encontrada"));

        if (reservaEntity.getEstado() != estadoEnum.CONFIRMADA) {
            throw new ReglaNegocioException("La reserva ya fue cancelada");
        }
        reservaEntity.setEstado(estadoEnum.CANCELADA);

        JuegoEntity juegoEntity = reservaEntity.getJuego();

        juegoEntity.setStockDisponible(
                juegoEntity.getStockDisponible() + reservaEntity.getCantidad());

        juegoRepository.save(juegoEntity);

        reservaRepository.save(reservaEntity);
    }

    @Override
    public ReservaResponseDTO getById(UUID externalId) {
        ReservaEntity reservaEntity = reservaRepository
                .findByExternalId(externalId)
                .orElseThrow(() -> new RecursoNoEncontradoException("Reserva no encontrada"));
        return reservaMapper.toResponse(reservaEntity);
    }

    @Override
    public List<ReservaResponseDTO> getAll(estadoEnum estado) {
        List<ReservaEntity> reservas;

        if(estado != null) {
            reservas = reservaRepository.findAllByEstado(estado);
        } else {
            reservas = reservaRepository.findAll();
        }
        return reservas
                .stream()
                .map(reservaMapper::toResponse)
                .toList();
    }

    @Override
    public List<ReservaResponseDTO> getBySocio(UUID socioId) {
        return reservaRepository
                .findAllBySocioExternalId(socioId)
                .stream()
                .map(reservaMapper::toResponse)
                .toList();
    }

    @Override
    public ReservaResponseDTO update(UUID externalId,
                                     ReservaRequestDTO reservaRequestDTO)
    {
        ReservaEntity reservaEntity = reservaRepository
                .findByExternalId(externalId)
                .orElseThrow(() -> new RecursoNoEncontradoException("Reserva no encontrada"));

        JuegoEntity juegoEntity = juegoRepository
                .findByExternalId(reservaRequestDTO.getJuegoId())
                .orElseThrow(() ->
                        new RecursoNoEncontradoException("Juego no encontrado"));
        SocioEntity socioEntity = socioRepository
                .findByExternalId(reservaRequestDTO.getSocioId())
                .orElseThrow(() ->
                        new RecursoNoEncontradoException("Socio no encontrado"));

        reservaMapper.updateEntity(
                reservaEntity,
                reservaRequestDTO,
                juegoEntity,
                socioEntity);

        reservaEntity = reservaRepository.save(reservaEntity);
        return reservaMapper.toResponse(reservaEntity);
    }
}
