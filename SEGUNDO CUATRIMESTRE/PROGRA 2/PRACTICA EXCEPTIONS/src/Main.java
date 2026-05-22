import exceptions.EdadInvalidaException;
import exceptions.TemperaturaInvalidaException;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        /*System.out.println("Ingrese el primer numero: ");
        int primero = scanner.nextInt();
        System.out.println("Ingrese el segundo numero: ");
        int segundo = scanner.nextInt();

        try {
            int division =  primero/segundo;
            System.out.println("Resultado: " + division);
        } catch (ArithmeticException e)
        {
            System.out.println("No se puede dividir por 0;");
        }
        scanner.close();

         */

        /*
        Edad edad1 = new Edad();
        System.out.println("Ingrese la edad: ");
        int edad = scanner.nextInt();
        edad1.setEdad(edad);

        try {
            Edad.validacion(edad1.getEdad());

        } catch (EdadInvalidaException e)
        {
            System.out.println("Error: " + e.getMessage());
        }
        scanner.close();

         */

        /*
        try {
            System.out.println("Ingrese el primer numero: ");
            int primero = scanner.nextInt();
            System.out.println("Ingrese el segundo numero: ");
            int segundo = scanner.nextInt();

            int division = primero/segundo;
            System.out.println("Resultado: " + division);

        } catch (ArithmeticException e)
        {
            System.out.println("Error: No es posible dividir por 0.");

        } catch (InputMismatchException e)
        {
            System.out.println("El valor ingresado no es un numero.");
        } finally {
            scanner.close();
        }

         */

        Horno horno1 = new Horno();

        try {
            System.out.println("Ingrese la temperatura: ");
            int temp = scanner.nextInt();

            horno1.setTemperatura(temp);
            System.out.println("Temperatura ingresada: " + temp + "°C");

        } catch (TemperaturaInvalidaException e)
        {
            System.out.println(e.getMessage());
        } catch (InputMismatchException e)
        {
            System.out.println("Error: El valor ingresado no es un número.");
        } finally {
            scanner.close();
        }

    }
}
