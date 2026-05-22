package clases;

public class Portatil extends Producto{
    private String tipoAlmacenamiento;
    private String sistemaOperativoPreinstalado;

    public Portatil() {
    }

    public String getTipoAlmacenamiento() {
        return tipoAlmacenamiento;
    }

    public void setTipoAlmacenamiento(String tipoAlmacenamiento) {
        this.tipoAlmacenamiento = tipoAlmacenamiento;
    }

    public String getSistemaOperativoPreinstalado() {
        return sistemaOperativoPreinstalado;
    }

    public void setSistemaOperativoPreinstalado(String sistemaOperativoPreinstalado) {
        this.sistemaOperativoPreinstalado = sistemaOperativoPreinstalado;
    }
}
