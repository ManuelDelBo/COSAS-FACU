package EJ3;

public class Cancion {
    static public int contador;
    private int id;
    private String nombre;
    private double duracion;
    private Genero genero;
    private Album album;
    private String artistaInvitado;

    public Cancion(String nombre, double duracion, Genero genero, Album album, String artistaInvitado) {
        this.id = contador++;
        this.nombre = nombre;
        this.duracion = duracion;
        this.genero = genero;
        this.album = album;
        this.artistaInvitado = artistaInvitado;
    }

    public Cancion() {
    }
}
