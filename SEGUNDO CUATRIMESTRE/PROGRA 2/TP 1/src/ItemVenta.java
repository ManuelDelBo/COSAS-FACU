public class ItemVenta {
    int identificador;
    String descripcion;
    int cantidad;
    double precioUnitario;

    double precioTotal;

    public ItemVenta(int identificador, String descripcion, int cantidad, double precioUnitario) {
        this.identificador = identificador;
        this.descripcion = descripcion;
        this.cantidad = cantidad;
        this.precioUnitario = precioUnitario;
    }

    public int getIdentificador() {
        return identificador;
    }

    public void setIdentificador(int identificador) {
        this.identificador = identificador;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public int getCantidad() {
        return cantidad;
    }

    public void setCantidad(int cantidad) {
        this.cantidad = cantidad;
    }

    public double getPrecioUnitario() {
        return precioUnitario;
    }

    public void setPrecioUnitario(double precioUnitario) {
        this.precioUnitario = precioUnitario;
    }

    public double calcularPrecioTotal()
    {
        precioTotal = precioUnitario * (double) cantidad;
        System.out.println("Precio total de los items: " + precioTotal);
        return precioTotal;
    }

    public void imprimir()
    {
        System.out.println("ItemVenta[id= " + identificador + ", descripcion= " + descripcion + ", cantidad= " + cantidad +
                ", pUnitario= " + precioUnitario + ", pTotal= " + precioTotal + "]");
    }
}
