package carpetaVentas;

import java.time.LocalDateTime;
import java.util.UUID;

public class Factura {
    private String id;
    private double montoTotal;
    private LocalDateTime fecha;
    private Cliente cliente;

    public Factura() {
    }

    public Factura(double montoTotal, Cliente cliente) {
        this.id = generarID();
        this.montoTotal = montoTotal;
        this.fecha = LocalDateTime.now();
        this.cliente = cliente;
    }

    //GETTERS Y SETTERS

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public double getMontoTotal() {
        return montoTotal;
    }

    public void setMontoTotal(double montoTotal) {
        this.montoTotal = montoTotal;
    }

    public LocalDateTime getFecha() {
        return fecha;
    }

    public void setFecha(LocalDateTime fecha) {
        this.fecha = fecha;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }
//METODOS
    private String generarID()
    {
        return UUID.randomUUID().toString().substring(0, 8).toUpperCase();
    }

    public double calcularMontoFinal()
    {
        montoTotal = montoTotal - (montoTotal * cliente.getPorcentajeDescuento() / 100);
        return montoTotal;
    }

    @Override
    public String toString() {
        return "Factura{" +
                "id='" + getId() + '\'' +
                ", montoTotal=" + getMontoTotal() +
                ", fecha=" + getFecha() +
                "Cliente{" +
                "id='" + getCliente().getId() + '\'' +
                ", nombre='" + getCliente().getNombre() + '\'' +
                ", mail='" + getCliente().getMail() + '\'' +
                ", porcentajeDescuento=" + getCliente().getPorcentajeDescuento() +
                '}';
    }
}
