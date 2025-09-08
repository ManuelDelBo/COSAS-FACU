import java.util.Scanner;

public class EmpleadoContratista extends Empleado{
    int horasTrabajadas;
    double tarifaXProyecto;
    double gananciaXProyecto;

    public EmpleadoContratista() {
    }

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
    protected EmpleadoContratista addEmpleado() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingrese el nombre: ");
        setNombre(scanner.nextLine());
        System.out.println("Ingrese el salario: ");
        setSalario(scanner.nextDouble());
        System.out.println("Ingrese la cantidad de horas trabajadas: ");
        horasTrabajadas = scanner.nextInt();
        System.out.println("Ingrese la tarifa del proyecto: ");
        tarifaXProyecto = scanner.nextDouble();
        scanner.nextLine();

        EmpleadoContratista empleado = new EmpleadoContratista(getNombre(), getSalario(), horasTrabajadas, tarifaXProyecto);

        System.out.println("Empleado contratista creado con éxito.");
        return empleado;

    }

    @Override
    public String toString() {
        return "EmpleadoContratista{" +
                "horasTrabajadas=" + horasTrabajadas +
                ", tarifaXProyecto=" + tarifaXProyecto +
                ", gananciaXProyecto=" + gananciaXProyecto +
                ", id=" + getId() +
                ", nombre='" + getNombre() + '\'' +
                ", salario=" + getSalario() +
                '}';
    }
}
