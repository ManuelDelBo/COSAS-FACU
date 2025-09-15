package aviones;

import interfaces.Ingreso;

public class Carga extends Avion implements Ingreso {
    private int cantKG;
    private String listaProductos;

    public Carga(String nombreDeModelo, String marca, int capacidadCombustible, String tipoDeMotor, int cantidadDeAsientos, int cantKG, String listaProductos) {
        super(nombreDeModelo, marca, capacidadCombustible, tipoDeMotor, cantidadDeAsientos);
        this.cantKG = cantKG;
        this.listaProductos = listaProductos;
    }

    public void descargar(){
        System.out.println("Descargar contenido");
        cantKG = 0;
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
