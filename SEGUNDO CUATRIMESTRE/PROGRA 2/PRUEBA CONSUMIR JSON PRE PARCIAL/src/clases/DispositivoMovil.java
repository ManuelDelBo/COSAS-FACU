package clases;

public class DispositivoMovil extends Producto{
    private boolean soporta5G;
    private String sistemaOperativo;

    public DispositivoMovil() {
    }

    public boolean isSoporta5G() {
        return soporta5G;
    }

    public void setSoporta5G(boolean soporta5G) {
        this.soporta5G = soporta5G;
    }

    public String getSistemaOperativo() {
        return sistemaOperativo;
    }

    public void setSistemaOperativo(String sistemaOperativo) {
        this.sistemaOperativo = sistemaOperativo;
    }
}
