import java.util.Scanner;

public class EmpleadoTiempoCompleto extends Empleado{
    private int horasFijasXMes = 120;
    private double salarioMensulal;

    public EmpleadoTiempoCompleto() {
    }

    public EmpleadoTiempoCompleto(String nombre, double salario, int horasFijasXMes) {
        super(nombre, salario);
        this.horasFijasXMes = horasFijasXMes;
    }

    @Override
    protected double calcularPago() {
        salarioMensulal = getSalario() * (double) horasFijasXMes;
        System.out.println("Salario mensual: " + salarioMensulal);
        return salarioMensulal;
    }

    @Override
    protected EmpleadoTiempoCompleto addEmpleado() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingrese el nombre: ");
        setNombre(scanner.nextLine());
        System.out.println("Ingrese el salario: ");
        setSalario(scanner.nextDouble());
        System.out.println("Ingrese la cantidad de horas fijas por mes: ");
        horasFijasXMes = scanner.nextInt();
        scanner.nextLine();

        EmpleadoTiempoCompleto empleado = new EmpleadoTiempoCompleto(getNombre(), getSalario(), horasFijasXMes);
        System.out.println("Empleado tiempo completo creado con éxito.");

        return empleado;
    }

    @Override
    public String toString() {
        return "EmpleadoTiempoCompleto{" +
                "horasFijasXMes=" + horasFijasXMes +
                ", salarioMensulal=" + salarioMensulal +
                ", id=" + getId() +
                ", nombre='" + getNombre() + '\'' +
                ", salario=" + getSalario() +
                '}';
    }


}
