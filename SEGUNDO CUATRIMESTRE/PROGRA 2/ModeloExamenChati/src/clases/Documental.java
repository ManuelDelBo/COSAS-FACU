package clases;

import enumeradores.DISPONIBILIDAD;
import enumeradores.GENERO;

public class Documental extends Material{
    private String tematica;

    //CONSTRUCTORES

    public Documental() {
    }

    //GETTERS Y SETTERS
    public Documental(String titulo, String director, String año, GENERO genero, DISPONIBILIDAD disponibilidad, String tematica) {
        super(titulo, director, año, genero, disponibilidad);
        this.tematica = tematica;
    }

    public String getTematica() {
        return tematica;
    }

    public void setTematica(String tematica) {
        this.tematica = tematica;
    }
}
