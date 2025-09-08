public abstract class Empleado {
    private static int contador = 0;

    int id;
    String nombre;
    double salario;

    public Empleado(String nombre, double salario) {
        this.id = contador++;
        this.nombre = nombre;
        this.salario = salario;
    }

    protected abstract double calcularPago();

    protected abstract void addEmpleado();

}
