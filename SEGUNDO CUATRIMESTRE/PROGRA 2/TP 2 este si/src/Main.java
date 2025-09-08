import carpetaCirculoYCilindro.Cilindro;
import carpetaLibros.Autor;
import carpetaLibros.Genero;
import carpetaLibros.Libro;
import carpetaUniversidad.Estudiante;
import carpetaUniversidad.Persona;
import carpetaUniversidad.Staff;
import carpetaUniversidad.Turnos;
import carpetaVentas.Cliente;
import carpetaVentas.Factura;

import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int seleccion;
        int i1= 0;
        int i2 = 0;
        int i3 = 0;

        EmpleadoTiempoCompleto[] arregloTC = new EmpleadoTiempoCompleto[20];
        EmpleadoPorHoras[] arregloXH = new EmpleadoPorHoras[20];
        EmpleadoContratista[] arregloC = new EmpleadoContratista[20];

        /*EJ 1-------------------------------------------------------------------------
        do {
            System.out.println("Que desea hacer?");
            System.out.println("1 - Crear empleado por tiempo completo");
            System.out.println("2 - Crear empleado por hora");
            System.out.println("3 - Crear empleado por proyecto");
            System.out.println("4 - Calcular pago mensual empleado tiempo completo");
            System.out.println("5 - Calcular pago por X cantidad de horas, empleado por hora");
            System.out.println("6 - Calcular pago por proyecto, empleado por proyecto");
            System.out.println("0 - Salir");
            System.out.print("Seleccione una opción: ");

            seleccion = scanner.nextInt();
            scanner.nextLine();

            switch (seleccion) {
                case 1:
                    arregloTC[i1] = new EmpleadoTiempoCompleto().addEmpleado();
                    System.out.println(arregloTC[i1].toString());
                    i1++;
                    break;

                case 2:
                    arregloXH[i2] = new EmpleadoPorHoras().addEmpleado();
                    System.out.println(arregloXH[i2].toString());
                    i2++;
                    break;

                case 3:
                    arregloC[i3] = new EmpleadoContratista().addEmpleado();
                    System.out.println(arregloC[i3].toString());
                    i3++;
                    break;

                case 4:
                    boolean encontrado1 = false;

                    System.out.println("Ingrese el id del empleado que quiera calcular su sueldo");
                    for (int i = 0;i<i1;i++)
                    {
                        System.out.println(arregloTC[i].getId() + " " + arregloTC[i].getNombre());
                    }
                    int idElegido = scanner.nextInt();

                    for(int j = 0;j<i1;j++)
                    {
                        if(idElegido == arregloTC[j].getId())
                        {
                            arregloTC[j].calcularPago();
                            encontrado1 = true;
                        }

                    }
                    if(!encontrado1)
                    {
                        System.out.println("El ID ingresado es erroneo.");
                    }
                    break;

                case 5:
                    boolean encontrado2 = false;

                    System.out.println("Ingrese el id del empleado que quiera calcular su sueldo");
                    for (int i = 0;i<i2;i++)
                    {
                        System.out.println(arregloXH[i].getId() + " " + arregloXH[i].getNombre());
                    }
                    idElegido = scanner.nextInt();

                    for(int j = 0;j<i2;j++)
                    {
                        if(idElegido == arregloXH[j].getId())
                        {
                            arregloXH[j].calcularPago();
                            encontrado2 = true;
                        }

                    }
                    if(!encontrado2)
                    {
                        System.out.println("El ID ingresado es erroneo.");
                    }
                    break;

                case 6:
                    boolean encontrado3 = false;

                    System.out.println("Ingrese el id del empleado que quiera calcular su sueldo");
                    for (int i = 0;i<i3;i++)
                    {
                        System.out.println(arregloC[i].getId() + " " + arregloC[i].getNombre());
                    }
                    idElegido = scanner.nextInt();

                    for(int j = 0;j<i3;j++)
                    {
                        if(idElegido == arregloC[j].getId())
                        {
                            arregloC[j].calcularPago();
                            encontrado3 = true;
                        }

                    }
                    if(!encontrado3)
                    {
                        System.out.println("El ID ingresado es erroneo.");
                    }
                    break;

                case 0:
                    System.out.println("Saliendo del programa...");
                    break;

                default:
                    System.out.println("Opción inválida.");
                    break;
            }
        } while (seleccion != 0);

         */

        /*EJ 2-------------------------------------------------------------------------
        Autor autor1 = new Autor("Joshua", "Bloch", "joshua@gmail.com", Genero.M);
        System.out.println(autor1.toString());

        Libro libro1 = new Libro("Effective Java", 450, 150, autor1);
        System.out.println(libro1.toString());

        libro1.setPrecio(500);
        libro1.setStock(libro1.getStock() + 50);

        System.out.println(libro1.toString());

        System.out.println(libro1.getAutor().toString());

         */

        /*EJ 3-------------------------------------------------------------------------

        Cliente cliente1 = new Cliente("Carleto", "carleto@gmail.com", 10);
        System.out.println(cliente1.toString());

        Factura factura = new Factura(1000, cliente1);

        System.out.println(factura.getMontoTotal());

        factura.calcularMontoFinal();
        System.out.println("factura menos " + factura.getCliente().getPorcentajeDescuento() + " porciento de descuentoe: " + factura.getMontoTotal());

        System.out.println(factura.toString());

         */

        /*EJ4-------------------------------------------------------------------------
        Cilindro cilindro = new Cilindro();
        cilindro.calcularVolumen();
        cilindro.calcularArea();
        System.out.println(cilindro.toString());

        Cilindro cilindro1 = new Cilindro(2.1);
        cilindro1.setRadio(2.1);
        cilindro1.calcularArea();
        cilindro1.calcularVolumen();
        System.out.println(cilindro1.toString());

         */

        //EJ4-------------------------------------------------------------------------
        Persona[] arregloPersonas = new Persona[20];

        arregloPersonas[0] = new Estudiante("123456", "Jorege", "Uribarri", "manudelbo@gmail.com", "Libertad 1234", "primero", 100000, "Programacion");
        arregloPersonas[1] = new Estudiante("258483", "Ulises", "Carlitos", "maasdasdlbo@gmail.com", "Maipu 1234", "segundo", 120000, "Programacion");
        arregloPersonas[2] = new Estudiante("789456", "Cristian", "Castro", "reter@gmail.com", "Croacia 1234", "primero", 200000, "Diseño");
        arregloPersonas[3] = new Estudiante("987456", "Maria", "Claudia", "marimari@gmail.com", "Necochea 1234", "tercero", 90000, "Arquitectura");

        arregloPersonas[4] = new Staff("111111", "Mario", "Pavon", "maritoperrealo@gmail.com", "Colombia 123", 900000, Turnos.Mañana);
        arregloPersonas[5] = new Staff("222222", "Claudio", "Garica", "Clauclaudito@gmail.com", "Camino 123", 1200000, Turnos.Noche);
        arregloPersonas[6] = new Staff("333333", "Nicanor", "Leguizamon", "Nicannica@gmail.com", "Pasaje 123", 3000000, Turnos.Noche);
        arregloPersonas[7] = new Staff("444444", "Judith", "Sturf", "Judith@gmail.com", "Seccion 123", 700000, Turnos.Mañana);

        int contadorEstudiantes = 0;
        int contadorStaff = 0;
        double ingresosInsti = 0;

        for(int i = 0; i<arregloPersonas.length;i++)
        {
            if(arregloPersonas[i] instanceof Estudiante)
            {
                contadorEstudiantes++;
                ingresosInsti+= ((Estudiante) arregloPersonas[i]).getCuotaMensual();

            } else if (arregloPersonas[i] instanceof Staff) {
                contadorStaff++;
            }
        }

        System.out.println("Cantidad estudiantes: " + contadorEstudiantes);
        System.out.println("Cantidad staff: " + contadorStaff);

        System.out.println("Ingreso mensual por cuotas: $" + ingresosInsti);

    }

}
