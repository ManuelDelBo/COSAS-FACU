package carpetaCirculoYCilindro;

public class Cilindro extends  Circulo{
    private double altura = 1.0;

    private double volumen;

    public Cilindro() {
    }

    public Cilindro(double altura) {
        this.altura = altura;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public double getVolumen() {
        return volumen;
    }

    public void setVolumen(double volumen) {
        this.volumen = volumen;
    }

    public Cilindro(double radio, Color color, double altura) {
        super(radio, color);
        this.altura = altura;
    }

    public double calcularVolumen()
    {
        volumen = Math.PI * Math.pow(getRadio(), 2) * altura;
        return volumen;
    }
    @Override
    public double calcularArea()
    {
        double areaBase = Math.PI * Math.pow(getRadio(), 2);
        double areaLateral = 2 * Math.PI * getRadio() * altura;
        return 2 * areaBase + areaLateral;
    }

    @Override
    public String toString() {
        return "Cilindro{" +
                "radio=" + getRadio() +
                ", color=" + getColor() +
                ", area=" + getAltura() +
                "altura=" + altura +
                ", volumen=" + volumen +
                '}';
    }

}
