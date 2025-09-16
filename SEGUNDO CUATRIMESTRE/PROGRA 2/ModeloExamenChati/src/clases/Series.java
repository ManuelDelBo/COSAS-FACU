package clases;

import enumeradores.DISPONIBILIDAD;
import enumeradores.GENERO;
import interfaces.Alquilar;
import interfaces.ReproduccionOnline;

public class Series extends Material implements ReproduccionOnline {
    private int cantidadTemporadas;
    private int cantidadEpisodios;

    //CONTRUCTORES
    public Series() {
    }
    public Series(String titulo, String director, String año, GENERO genero, DISPONIBILIDAD disponibilidad, int cantidadTemporadas, int cantidadEpisodios) {
        super(titulo, director, año, genero, disponibilidad);
        this.cantidadTemporadas = cantidadTemporadas;
        this.cantidadEpisodios = cantidadEpisodios;
    }

    //GETTERS Y SETTERS

    public int getCantidadTemporadas() {
        return cantidadTemporadas;
    }

    public void setCantidadTemporadas(int cantidadTemporadas) {
        this.cantidadTemporadas = cantidadTemporadas;
    }

    public int getCantidadEpisodios() {
        return cantidadEpisodios;
    }

    public void setCantidadEpisodios(int cantidadEpisodios) {
        this.cantidadEpisodios = cantidadEpisodios;
    }

    //METODOS

    @Override
    public void reproducirOnline() {
        System.out.println("Reproduciendo Pelicula.");
    }



}
