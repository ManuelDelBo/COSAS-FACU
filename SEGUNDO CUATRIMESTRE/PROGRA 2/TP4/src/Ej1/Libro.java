package Ej1;

import java.time.LocalDate;
import java.util.Objects;

public class Libro {
    public static int contador = 0;


    private int id;
    private String titulo;
    private String autor;
    private double precio;
    private LocalDate añoPublicacion;

    public Libro() {
    }

    public Libro(String titulo, String autor, double precio, LocalDate añoPublicacion) {
        this.id = contador++;
        this.titulo = titulo;
        this.autor = autor;
        this.precio = precio;
        this.añoPublicacion = añoPublicacion;
    }

    public int getId() {
        return id;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public LocalDate getAñoPublicacion() {
        return añoPublicacion;
    }

    public void setAñoPublicacion(LocalDate añoPublicacion) {
        this.añoPublicacion = añoPublicacion;
    }

    @Override
    public String toString() {
        return "Libro{" +
                "id=" + id +
                ", titulo='" + titulo + '\'' +
                ", autor='" + autor + '\'' +
                ", precio=" + precio +
                ", añoPublicacion=" + añoPublicacion +
                '}';
    }

    public String toStringIdTitulo() {
        return "Libro{" +
                "id=" + id +
                ", titulo='" + titulo +
                '}';
    }
}
