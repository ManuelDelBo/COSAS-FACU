public class Libro {
    private static int contador = 0;
    private int id;
    private String titulo;
    private String autor;
    private double precio;
    private int disponibles;

    public Libro(String titulo, String autor, double precio, int disponibles) {
        this.id = ++contador;
        this.titulo = titulo;
        this.autor = autor;
        this.precio = precio;
        this.disponibles = disponibles;
    }

    public int getId() {
        return id;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public int getDisponibles() {
        return disponibles;
    }

    public void setDisponibles(int disponibles) {
        this.disponibles = disponibles;
    }

    public void venderCopias(int cantCompra)
    {
        if(disponibles < cantCompra)
        {
            System.out.println("Cantidad de libros insuficicentes.");
        }
        else
        {
            System.out.println("Cantidad disponible = " + disponibles);
            System.out.println("Cantidad vendidos = " + cantCompra);
            disponibles = disponibles - cantCompra;

            System.out.println("Nueva cantidad disponible = " + disponibles);
        }
    }

    public void incrementarDisponibles(int aumento)
    {
        System.out.println("Cant disponibles " + disponibles);
        disponibles = disponibles + aumento;
        System.out.println("Cant agregados " + aumento);
        System.out.println("Nueva cant disponibles " + disponibles);
    }

    public void imprimir()
    {
        System.out.println(": Libro[id= " + id + ", título= " + titulo + ", autor= " + autor + ", precio= " + precio + ", copias disponibles= " + disponibles + "]");
    }
}


