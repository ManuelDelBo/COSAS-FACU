public abstract class Empleado {
    private static int contador = 0;

    private int id;
    private String nombre;
    private double salario;

    public Empleado() {
    }

    public Empleado(String nombre, double salario) {
        this.id = contador++;
        this.nombre = nombre;
        this.salario = salario;
    }

    public static int getContador() {
        return contador;
    }

    public static void setContador(int contador) {
        Empleado.contador = contador;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    protected abstract double calcularPago();

    protected abstract Empleado addEmpleado();

    @Override
    public String toString() {
        return "Empleado{" +
                "id=" + id +
                ", nombre='" + nombre + '\'' +
                ", salario=" + salario +
                '}';
    }
}
