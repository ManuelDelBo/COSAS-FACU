public class EmpleadoPorHoras extends Empleado{
    int horasTrabajadas;
    double salarioXHoras;

    public EmpleadoPorHoras(String nombre, double salario, int horasTrabajadas) {
        super(nombre, salario);
        this.horasTrabajadas = horasTrabajadas;
    }

    @Override
    protected double calcularPago() {
        salarioXHoras = salario * (double) horasTrabajadas;
        System.out.println("Salario por " + horasTrabajadas + " horas trabajadas: " + salarioXHoras);
        return salarioXHoras;
    }

    @Override
    protected void addEmpleado() {

    }
}
