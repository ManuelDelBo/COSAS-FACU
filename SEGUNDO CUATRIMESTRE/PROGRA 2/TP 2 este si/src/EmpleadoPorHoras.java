import java.util.Scanner;

public class EmpleadoPorHoras extends Empleado{
    int horasTrabajadas;
    double salarioXHoras;

    public EmpleadoPorHoras() {
    }

    public EmpleadoPorHoras(String nombre, double salario, int horasTrabajadas) {
        super(nombre, salario);
        this.horasTrabajadas = horasTrabajadas;
    }

    @Override
    protected double calcularPago() {
        salarioXHoras = getSalario() * (double) horasTrabajadas;
        System.out.println("Salario por " + horasTrabajadas + " horas trabajadas: " + salarioXHoras);
        return salarioXHoras;
    }

    @Override
    protected EmpleadoPorHoras addEmpleado() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingrese el nombre: ");
        setNombre(scanner.nextLine());
        System.out.println("Ingrese el salario: ");
        setSalario(scanner.nextDouble());
        System.out.println("Ingrese la cantidad de horas trabajadas: ");
        horasTrabajadas = scanner.nextInt();
        scanner.nextLine();

        EmpleadoPorHoras empleado = new EmpleadoPorHoras(getNombre(), getSalario(), horasTrabajadas);

        System.out.println("Empleado por hora creado con éxito.");

        return empleado;
    }

    @Override
    public String toString() {
        return "EmpleadoPorHoras{" +
                "horasTrabajadas=" + horasTrabajadas +
                ", salarioXHoras=" + salarioXHoras +
                ", id=" + getId() +
                ", nombre='" + getNombre() + '\'' +
                ", salario=" + getSalario() +
                '}';
    }
}
