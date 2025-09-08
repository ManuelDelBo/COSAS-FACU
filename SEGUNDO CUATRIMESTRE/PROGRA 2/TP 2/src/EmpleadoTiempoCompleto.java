public class EmpleadoTiempoCompleto extends Empleado{
    int horasFijasXMes = 120;
    double salarioMensulal;

    public EmpleadoTiempoCompleto(String nombre, double salario, int horasFijasXMes) {
        super(nombre, salario);
        this.horasFijasXMes = horasFijasXMes;
    }

    @Override
    protected double calcularPago() {
        salarioMensulal = salario * (double) horasFijasXMes;
        System.out.println("Salario mensual: " + salarioMensulal);
        return salarioMensulal;
    }

    @Override
    protected void addEmpleado() {

    }


}
