public class Empleado {
    String dni;
    String nombre;
    String apellido;
    double salario;

    public Empleado(String dni, String nombre, String apellido, double salario) {
        this.dni = dni;
        this.nombre = nombre;
        this.apellido = apellido;
        this.salario = salario;
    }

    public double calcularSalarioAnual()
    {
        double salarioAnualizado = salario * 12;
        System.out.println("Salario por año: " + salarioAnualizado);
        return salarioAnualizado;
    }

    public double aumentarSalario(double porcentaje)
    {
        double aumento = salario * (porcentaje / 100);
        System.out.println("Salario incial " + salario);
        salario = salario + aumento;
        System.out.println("Salario aumentado a " + salario);
        return  salario;
    }

    public void imprimir()
    {
        System.out.println("Empleado[dni= " + dni + ", nombre= " + nombre +
                ", apellido= " + apellido + ", salario= " + salario + "]");
    }
}


