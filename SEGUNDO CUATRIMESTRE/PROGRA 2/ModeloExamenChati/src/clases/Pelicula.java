package clases;

import clases.Material;
import enumeradores.DISPONIBILIDAD;
import enumeradores.GENERO;
import interfaces.Alquilar;
import interfaces.ReproduccionOnline;

public class Pelicula extends Material implements ReproduccionOnline {
    private int duracionMinutos;

    //CONSTRUCTORES

    public Pelicula() {
    }

    public Pelicula(String titulo, String director, String año, GENERO genero, DISPONIBILIDAD disponibilidad, int duracionMinutos) {
        super(titulo, director, año, genero, disponibilidad);
        this.duracionMinutos = duracionMinutos;
    }

    //GETTERS Y SETTERS


    public int getDuracionMinutos() {
        return duracionMinutos;
    }

    public void setDuracionMinutos(int duracionMinutos) {
        this.duracionMinutos = duracionMinutos;
    }

    //METODOS

    @Override
    public void reproducirOnline() {
        System.out.println("Reproduciendo Pelicula.");
    }

}
