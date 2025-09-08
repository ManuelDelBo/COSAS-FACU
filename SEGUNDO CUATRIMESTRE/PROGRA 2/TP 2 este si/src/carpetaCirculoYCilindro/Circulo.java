package carpetaCirculoYCilindro;

public class Circulo {
    private double radio = 1.0;
    private Color color = Color.Rojo;

    private double area;

    public Circulo() {
    }

    public Circulo(double radio, Color color) {
        this.radio = radio;
        this.color = color;
    }

    public double getRadio() {
        return radio;
    }

    public void setRadio(double radio) {
        this.radio = radio;
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public double getArea() {
        return area;
    }

    public void setArea(double area) {
        this.area = area;
    }

    public double calcularArea()
    {
        area = Math.PI * Math.pow(radio, 2);
        return area;
    }


    @Override
    public String toString() {
        return "Circulo{" +
                "radio=" + radio +
                ", color=" + color +
                ", area=" + area +
                '}';
    }
}
