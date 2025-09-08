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
                    System.out.println("Ingrese el nombre: ");
                    String nombre = scanner.nextLine();
                    System.out.println("Ingrese el salario: ");
                    double salario = scanner.nextDouble();
                    System.out.println("Ingrese la cantidad de horas fijas por mes: ");
                    int horasFijasXMes = scanner.nextInt();
                    scanner.nextLine();

                    arregloTC[i1] = new EmpleadoTiempoCompleto(nombre, salario, horasFijasXMes);
                    i1++;

                    System.out.println("Empleado tiempo completo creado con éxito.");
                    break;

                case 2:
                    System.out.println("Ingrese el nombre: ");
                    nombre = scanner.nextLine();
                    System.out.println("Ingrese el salario: ");
                    salario = scanner.nextDouble();
                    System.out.println("Ingrese la cantidad de horas trabajadas: ");
                    int horasTrabajadas = scanner.nextInt();
                    scanner.nextLine();

                    arregloXH[i2] = new EmpleadoPorHoras(nombre, salario, horasTrabajadas);
                    i2++;

                    System.out.println("Empleado por hora creado con éxito.");
                    break;

                case 3:
                    System.out.println("Ingrese el nombre: ");
                    nombre = scanner.nextLine();
                    System.out.println("Ingrese el salario: ");
                    salario = scanner.nextDouble();
                    System.out.println("Ingrese la cantidad de horas trabajadas: ");
                    horasTrabajadas = scanner.nextInt();
                    System.out.println("Ingrese la tarifa del proyecto: ");
                    double tarifaXProyecto = scanner.nextDouble();
                    scanner.nextLine();

                    arregloC[i3] = new EmpleadoContratista(nombre, salario, horasTrabajadas, tarifaXProyecto);
                    i3++;

                    System.out.println("Empleado contratista creado con éxito.");
                    break;

                case 4:
                    int idEncontado = 0;

                    System.out.println("Ingrese el id del empleado que quiera calcular su sueldo");
                    for (int i = 0;i<i1;i++)
                    {
                        System.out.println(arregloTC[i].id + arregloTC[i].nombre);
                    }
                    int idElegido = scanner.nextInt();

                    for(int j = 0;j<i1;j++)
                    {
                        if(idElegido == arregloTC[j].id)
                        {
                            arregloTC[j].calcularPago();
                            idEncontado++;
                        }

                    }
                    if(idEncontado != 1)
                    {
                        System.out.println("El ID ingresado es erroneo.");
                    }
                    break;

                case 5:
                    idEncontado = 0;

                    System.out.println("Ingrese el id del empleado que quiera calcular su sueldo");
                    for (int i = 0;i<i1;i++)
                    {
                        System.out.println(arregloXH[i].id + arregloXH[i].nombre);
                    }
                    idElegido = scanner.nextInt();

                    for(int j = 0;j<i1;j++)
                    {
                        if(idElegido == arregloXH[j].id)
                        {
                            arregloXH[j].calcularPago();
                            idEncontado++;
                        }

                    }
                    if(idEncontado != 1)
                    {
                        System.out.println("El ID ingresado es erroneo.");
                    }
                    break;

                case 6:
                    idEncontado = 0;

                    System.out.println("Ingrese el id del empleado que quiera calcular su sueldo");
                    for (int i = 0;i<i1;i++)
                    {
                        System.out.println(arregloC[i].id + arregloC[i].nombre);
                    }
                    idElegido = scanner.nextInt();

                    for(int j = 0;j<i1;j++)
                    {
                        if(idElegido == arregloC[j].id)
                        {
                            arregloC[j].calcularPago();
                            idEncontado++;
                        }

                    }
                    if(idEncontado != 1)
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

    }
}