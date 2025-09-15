package carpetaLibros;

public abstract class Libros {
    public static int contador;
    private int id;
    private String titulo;
    private String autor;
    private String año;
    private TipoMaterial tipoMaterial;

    private boolean disponible = true;

    //CONSTRUCTORES
    public Libros() {
    }
    public Libros(String titulo, String autor, String año, TipoMaterial tipoMaterial) {
        this.id = contador++;
        this.titulo = titulo;
        this.autor = autor;
        this.año = año;
        this.tipoMaterial = tipoMaterial;
        this.disponible = true;
    }

    //GETTERS Y SETTERS
    public int getId() {
        return id;
    }

    public String getTitulo() {
        return titulo;
    }

    public boolean isDisponible() {
        return disponible;
    }
    public void setId(int id) {
        this.id = id;
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

    public String getAño() {
        return año;
    }

    public void setAño(String año) {
        this.año = año;
    }

    public TipoMaterial getTipoMaterial() {
        return tipoMaterial;
    }

    public void setTipoMaterial(TipoMaterial tipoMaterial) {
        this.tipoMaterial = tipoMaterial;
    }

    public void setDisponible(boolean disponible) {
        this.disponible = disponible;
    }

    //METODOS
    @Override
    public String toString() {
        return "Libros{" +
                "id=" + id +
                ", titulo='" + titulo + '\'' +
                ", autor='" + autor + '\'' +
                ", año='" + año + '\'' +
                ", tipoMaterial=" + tipoMaterial +
                '}';
    }

    public String toStringIdTitulo() {
        return "id=" + id + ", titulo='" + titulo;
    }
}
