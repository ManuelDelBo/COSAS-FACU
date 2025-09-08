public class EmpleadoContratista extends Empleado{
    int horasTrabajadas;
    double tarifaXProyecto;
    double gananciaXProyecto;

    public EmpleadoContratista(String nombre, double salario, int horasTrabajadas, double tarifaXProyecto) {
        super(nombre, salario);
        this.horasTrabajadas = horasTrabajadas;
        this.tarifaXProyecto = tarifaXProyecto;
    }

    @Override
    protected double calcularPago() {
        gananciaXProyecto = tarifaXProyecto * (double) horasTrabajadas;
        System.out.println("Ganancia total por proyecto: " + gananciaXProyecto);
        return gananciaXProyecto;
    }

    @Override
    protected void addEmpleado() {

    }
}
