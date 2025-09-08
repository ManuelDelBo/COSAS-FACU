package carpetaLibros;

public class Autor {
    private static int contador = 0;
    private int id;
    private String nombre;
    private String apellido;
    private String email;
    private Genero genero;
    public Autor() {
    }

    public Autor(String nombre, String apellido, String email, Genero genero) {
        this.id = contador++;
        this.nombre = nombre;
        this.apellido = apellido;
        this.email = email;
        this.genero = genero;
    }

    //GETTERS Y SETTERS

    public static int getContador() {
        return contador;
    }

    public static void setContador(int contador) {
        Autor.contador = contador;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellido() {
        return apellido;
    }

    public void setApellido(String apellido) {
        this.apellido = apellido;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public Genero getGenero() {
        return genero;
    }

    public void setGenero(Genero genero) {
        this.genero = genero;
    }

    //METODOS

    @Override
    public String toString() {
        return "Autor{" +
                "id=" + getId() +
                ", nombre='" + getNombre() + '\'' +
                ", apellido='" + getApellido() + '\'' +
                ", email='" + getEmail() + '\'' +
                ", genero=" + getGenero() +
                '}';
    }
}
