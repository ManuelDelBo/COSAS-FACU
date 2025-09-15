package carpetaLibros;

public class Libro extends Libros{
    private int cantidadPaginas;
    private GENERO genero;

    //CONSTRUCTORES
    public Libro() {
    }
    public Libro(String titulo, String autor, String año, TipoMaterial tipoMaterial, int cantidadPaginas, GENERO genero) {
        super(titulo, autor, año, tipoMaterial);
        this.cantidadPaginas = cantidadPaginas;
        this.genero = genero;
    }

    //GETTERS Y SETTERS


    public int getCantidadPaginas() {
        return cantidadPaginas;
    }

    public void setCantidadPaginas(int cantidadPaginas) {
        this.cantidadPaginas = cantidadPaginas;
    }

    public GENERO getGenero() {
        return genero;
    }

    public void setGenero(GENERO genero) {
        this.genero = genero;
    }
}
