package aviones;

import interfaces.Servicios;

public class Privado extends Avion implements Servicios {
    private boolean jacuzzi;
    public boolean verMundial;
    private String claveWIFI;

    public Privado(String nombreDeModelo, String marca, int capacidadCombustible, String tipoDeMotor, int cantidadDeAsientos, boolean jacuzzi, String claveWIFI) {
        super(nombreDeModelo, marca, capacidadCombustible, tipoDeMotor, cantidadDeAsientos);
        this.jacuzzi = jacuzzi;
        this.claveWIFI = claveWIFI;
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
