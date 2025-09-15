package aviones;

import interfaces.Ingreso;

public class Militar extends Avion implements Ingreso {
    private SistemaArmas sistemaArmas;
    private int canidadBalas;

    public Militar(String nombreDeModelo, String marca, int capacidadCombustible, String tipoDeMotor, int cantidadDeAsientos, SistemaArmas sistemaArmas, int canidadBalas) {
        super(nombreDeModelo, marca, capacidadCombustible, tipoDeMotor, cantidadDeAsientos);
        this.sistemaArmas = sistemaArmas;
        this.canidadBalas = canidadBalas;
    }

    public Militar() {
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
    public boolean ingresar() {
        return false;
    }
}
