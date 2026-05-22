public class DispositivoMovil extends Producto {
    private boolean soporta5g;
    private String sistOperativo;

    public DispositivoMovil() {
    }

    public boolean isSoporta5g() {
        return soporta5g;
    }

    public void setSoporta5g(boolean soporta5g) {
        this.soporta5g = soporta5g;
    }

    public String getSistOperativo() {
        return sistOperativo;
    }

    public void setSistOperativo(String sistOperativo) {
        this.sistOperativo = sistOperativo;
    }
}
