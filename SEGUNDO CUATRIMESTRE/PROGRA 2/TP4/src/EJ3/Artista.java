package EJ3;

public class Artista {
    static public int contador;
    private int id;
    private String nombre;
    private int edad;
    private String nacionalidad;

    public Artista() {
    }

    public Artista(String nombre, int edad, String nacionalidad) {
        this.id = contador++;
        this.nombre = nombre;
        this.edad = edad;
        this.nacionalidad = nacionalidad;
    }
}
