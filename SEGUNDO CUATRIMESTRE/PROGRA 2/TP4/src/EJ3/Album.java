package EJ3;

import java.time.LocalDate;

public class Album {
    static public int contador;
    private int id;
    private LocalDate añoPublicacion;
    private String titulo;
    private Artista artista;

    public Album() {
    }

    public Album(LocalDate añoPublicacion, String titulo, Artista artista) {
        this.id = contador++;
        this.añoPublicacion = añoPublicacion;
        this.titulo = titulo;
        this.artista = artista;
    }
}
