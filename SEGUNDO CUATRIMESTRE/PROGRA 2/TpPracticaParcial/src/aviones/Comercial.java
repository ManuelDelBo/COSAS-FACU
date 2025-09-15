package aviones;

import interfaces.Servicios;

public class Comercial extends Avion implements Servicios {
    private int cantidadAzafatas;
    private String listaServicios;

    public Comercial(String nombreDeModelo, String marca, int capacidadCombustible, String tipoDeMotor, int cantidadDeAsientos, int cantidadAzafatas, String listaServicios) {
        super(nombreDeModelo, marca, capacidadCombustible, tipoDeMotor, cantidadDeAsientos);
        this.cantidadAzafatas = cantidadAzafatas;
        this.listaServicios = listaServicios;
    }
    public Comercial() {
    }

    @Override
    public void despegar() {

    }

    @Override
    public void aterrizar() {

    }

    @Override
    public void volando() {

    }

    @Override
    public void darComida() {

    }

    @Override
    public void darManta() {

    }
}
