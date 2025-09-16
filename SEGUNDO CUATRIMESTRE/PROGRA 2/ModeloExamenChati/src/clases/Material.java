package clases;

import enumeradores.DISPONIBILIDAD;
import enumeradores.GENERO;

import java.util.Objects;

public abstract class Material implements Comparable<Material>{
    public static int incrementable;

    private int id;
    private String titulo;
    private String director;
    private String año;
    private GENERO genero;
    protected DISPONIBILIDAD disponibilidad;


    //CONSTRUCTORES
    public Material() {
    }

    public Material(String titulo, String director, String año, GENERO genero, DISPONIBILIDAD disponibilidad) {
        this.id = incrementable++;
        this.titulo = titulo;
        this.director = director;
        this.año = año;
        this.genero = genero;
        this.disponibilidad = disponibilidad;
    }

    //GETTERS Y SETTERS


    public int getId() {
        return id;
    }


    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getDirector() {
        return director;
    }

    public void setDirector(String director) {
        this.director = director;
    }

    public String getAño() {
        return año;
    }

    public void setAño(String año) {
        this.año = año;
    }

    public GENERO getGenero() {
        return genero;
    }

    public void setGenero(GENERO genero) {
        this.genero = genero;
    }

    public void alquilar() {
        if(this.disponibilidad == DISPONIBILIDAD.SOLOSUSCRIPCION)
        {
            System.out.println("Este material esta disponible en la suscripciòn basica, no es necesario alquilarlo");
            return;
        }
        if(this.disponibilidad == DISPONIBILIDAD.DISPONIBLE)
        {
            System.out.println("Pelicula alquilada.");
            this.disponibilidad = DISPONIBILIDAD.ALQUILADO;
        }
        if(this.disponibilidad == DISPONIBILIDAD.ALQUILADO)
        {
            System.out.println("EL material no se encuentra disponible.");
            return;
        }
    }

    public void devolver() {
        if(this.disponibilidad == DISPONIBILIDAD.SOLOSUSCRIPCION)
        {
            System.out.println("Este material esta disponible en la suscripciòn basica, no es necesario alqilarlo ni devolverlo");
            return;
        }
        if(this.disponibilidad == DISPONIBILIDAD.DISPONIBLE)
        {
            System.out.println("El material no esta alquilado, no debe ser devuelto.");
            return;
        }
        if(this.disponibilidad == DISPONIBILIDAD.ALQUILADO)
        {
            System.out.println("Material devuelto, muchas gracias.");
            this.disponibilidad = DISPONIBILIDAD.DISPONIBLE;
        }
    }

    @Override
    public String toString() {
        return "Material{" +
                "id=" + id +
                ", titulo='" + titulo + '\'' +
                ", director='" + director + '\'' +
                ", año='" + año + '\'' +
                ", genero=" + genero +
                ", disponibilidad=" + disponibilidad +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Material material)) return false;
        return getId() == material.getId() && Objects.equals(getTitulo(), material.getTitulo()) && Objects.equals(getDirector(), material.getDirector()) && Objects.equals(getAño(), material.getAño()) && getGenero() == material.getGenero() && disponibilidad == material.disponibilidad;
    }

    @Override
    public int hashCode() {
        return Objects.hash(getId(), getTitulo(), getDirector(), getAño(), getGenero(), disponibilidad);
    }

    @Override
    public int compareTo(Material o) {
        return this.titulo.compareTo(o.titulo);
    }
}
