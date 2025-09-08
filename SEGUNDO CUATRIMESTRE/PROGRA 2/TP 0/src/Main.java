import java.util.Scanner;
//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

public class Main {
    public static void main(String[] args)
    {
        /* EJ 1
        int numN = 1;
        double numA = 1.0;
        char numC = '2';

        System.out.println("Valor de numN: " + numN);
        System.out.println("Valor de numA: " + numA);
        System.out.println("Valor de numC: " + numC);

        System.out.println("Suma (numN + numA): " + (numN + numA));
        System.out.println("Diferencia (numA - numN): " + (numA - numN));
        System.out.println("Valor numérico de numC: " + (int) numC);

         */
        /* EJ 2

        int numX = 2;
        int numY = 3;
        double numN = 1.2;
        double numM = 2.1;


        System.out.println("suma enteros" + (numX + numY));
        System.out.println("suma decimales" + (numN + numM));
        System.out.println("resta enteros" + (numY - numX));
        System.out.println("resta decimales" + (numM - numN));
        System.out.println("suma entero y decimal" + (numX + numN));
        System.out.println("resta entero y decimal" + (numY - numN));

         */
        /* EJ 3

        int N;

        Scanner scanner = new Scanner(System.in);

        System.out.println("Ingrese un numero: ");
        N = scanner.nextInt();

        System.out.println("Numero ingresado: " + N);
        System.out.println((N + 77) + "/ incrementeado en 77");
        int reducidoa3 = N + 3;
        reducidoa3 = reducidoa3 - N;
        System.out.println(reducidoa3 + "/ reducido su valor a 3");
        System.out.println((N * 2) + "/ valor duplicado");

        */

        /* EJ 4


        int A = 1;
        int B = 2;
        int C = 3;
        int D = 4;

        int aux = B;
        int aux2 = B;
        B = C;
        aux = C;
        C = A;
        aux = A;
        A = D;
        D = aux2;


        */

        /* EJ 5

        int A = (int)(Math.random()*101);

        if(A % 2 == 0)
        {
            System.out.println("A es par. " + A);
        }
        else
        {
            System.out.println("A es impar. " + A);
        }


         */
        /* Ej 6

        Scanner scanner = new Scanner(System.in);

        System.out.println("Ingrese un numero neggativo o positico: ");
        int B = scanner.nextInt();

        if(B < 0)
        {
            System.out.println("B es menor a 0. " + B);
        }
        else
        {
            System.out.println("B es mayor a 0. " + B);
        }

         */
        /* EJ 7

        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingrese una frase corta");
        char caracter = scanner.next().charAt(0);

        int caracterASCI = (int)caracter;

        System.out.println("El codigo ASCI de " + caracter + " es " + caracterASCI);

         */

        /* EJ 8

        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingrese un numero: ");
        int C = scanner.nextInt();
        System.out.println("NUMERO INGRESADO " + C);

        if(C % 2 == 0)
        {
            System.out.println("El numero ingresado es par.");
        }
        else
        {
            System.out.println("El numero ingresado es impar.");
        }

        if(C > 0)
        {
            System.out.println("El numero ingresado es positivo.");
        }
        else
        {
            System.out.println("El numero ingresado es negativo.");
        }

        if(C % 5 == 0)
        {
            System.out.println("El numero ingresado es multiplo de 5.");
        }
        else
        {
            System.out.println("El numero ingresado no es multiplo de 5.");
        }
        if(C % 10 == 0)
        {
            System.out.println("El numero ingresado es multiplo de 10.");
        }
        else
        {
            System.out.println("El numero ingresado no es multiplo de 10.");
        }

        if(C > 100)
        {
            System.out.println("El numero ingresado es mayor a 10.");
        }
        else
        {
            System.out.println("El numero ingresado es menor a 100.");
        }

         */

        /* EJ 9

        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingresa tu nombre bestia: ");
        String nombre = scanner.nextLine();

        System.out.println("Buenos días " + nombre);

         */

        /* EJ 10

        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingresa el radio de un cirgunferencia: ");
        int radio = scanner.nextInt();
        System.out.println("El radio es " + radio);

        double longitud = 2.0 * Math.PI * (double) radio;
        System.out.println("La longitud es " + longitud);

        double area = Math.PI * Math.pow(radio, 2);
        System.out.println("El area es " + area);

         */

        // EJ 11

        double velocidadKMH = 80.50;
        System.out.println("Velocidad en km/h " + velocidadKMH);

        double velocidadMS = velocidadKMH * 1000 / 3600;
        System.out.println("Velocidad en m/s " + velocidadMS);





    }
}