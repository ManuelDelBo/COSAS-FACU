public class Accesorio extends Producto{
    private String tipoConexion;
    private boolean antiGhosting;

    public Accesorio() {
    }

    public String getTipoConexion() {
        return tipoConexion;
    }

    public void setTipoConexion(String tipoConexion) {
        this.tipoConexion = tipoConexion;
    }

    public boolean isAntiGhosting() {
        return antiGhosting;
    }

    public void setAntiGhosting(boolean antiGhosting) {
        this.antiGhosting = antiGhosting;
    }
}
