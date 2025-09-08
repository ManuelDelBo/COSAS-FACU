package carpetaUniversidad;

public class Staff extends Persona{
    private double salario;
    private Turnos turno;
    public Staff() {
    }
    public Staff(String dni, String nombre, String apellido, String email, String direccion, double salario, Turnos turno) {
        super(dni, nombre, apellido, email, direccion);
        this.salario = salario;
        this.turno = turno;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public Turnos getTurno() {
        return turno;
    }

    public void setTurno(Turnos turno) {
        this.turno = turno;
    }
}
