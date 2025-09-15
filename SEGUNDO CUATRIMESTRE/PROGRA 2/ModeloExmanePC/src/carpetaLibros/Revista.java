package carpetaLibros;

public class Revista extends Libros{
    private boolean tapDura;

    public Revista() {
    }
    //CONSTRUCTORES
    public Revista(String titulo, String autor, String año, TipoMaterial tipoMaterial, boolean tapDura) {
        super(titulo, autor, año, tipoMaterial);
        this.tapDura = tapDura;
    }

    //GETTERS Y SETTERS
    public boolean isTapDura() {
        return tapDura;
    }

    public void setTapDura(boolean tapDura) {
        this.tapDura = tapDura;
    }
}
