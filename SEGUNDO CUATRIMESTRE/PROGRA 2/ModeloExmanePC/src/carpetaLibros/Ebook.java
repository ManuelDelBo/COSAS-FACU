package carpetaLibros;

public class Ebook extends Libros implements LecturaPlataforma{
    private String tipoArchivo;

    //CONSTRUCTORES
    public Ebook() {
    }
    public Ebook(String titulo, String autor, String año, TipoMaterial tipoMaterial, String tipoArchivo) {
        super(titulo, autor, año, tipoMaterial);
        this.tipoArchivo = tipoArchivo;
    }

    //METODOS
    @Override
    public boolean leerEnPlataforma() {
        System.out.println("Ebook listo para leer en plataforma;");
        return true;
    }

    //GETTERS Y SETTERS

    public String getTipoArchivo() {
        return tipoArchivo;
    }

    public void setTipoArchivo(String tipoArchivo) {
        this.tipoArchivo = tipoArchivo;
    }
}
