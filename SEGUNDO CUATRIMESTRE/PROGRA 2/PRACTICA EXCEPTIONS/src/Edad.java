import exceptions.EdadInvalidaException;
public class Edad {
    private int edad;

    public Edad(int edad) {
        this.edad = edad;
    }

    public Edad() {
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }
    public static void validacion(int edad) throws EdadInvalidaException
    {
        if (edad>120 || edad<0)
        {
            throw new EdadInvalidaException();
        }
        System.out.println("Edad ingresada: " + edad);
    }

}
