import EJ2.Persona;
import EJ2.Sexo;
import EJ3.Album;
import EJ3.Artista;
import EJ3.Cancion;
import EJ3.Genero;
import Ej1.Inventario;
import Ej1.Libro;

import java.time.LocalDate;
import java.util.*;

public class Main {
    public static void main(String[] args)
    {
        /*Inventario inventario = new Inventario();

        Scanner scanner = new Scanner(System.in);
        int opcion;

        do {
            System.out.println("MENU INVENTARIO");
            System.out.println("--------------------------------");
            System.out.println("1- Agregar un libro.");
            System.out.println("3- Mostrar los libros.");
            System.out.println("3- Eliminar un libro.");
            System.out.println("4- Buscar libro por titulo.");
            System.out.println("5- Actualizar precio de un libro.");
            System.out.println("6- Ver el precio total de todos los libros.");
            System.out.println("7- Ver la cantidad de libros disponibles.");
            System.out.println("8- Ver el libro mas caro.");
            System.out.println("9- Ver el libro mas barato.");
            System.out.println("--------------------------------");
            System.out.println("Ingrese el nro para la opciòn que desee:");

            opcion = scanner.nextInt();
            scanner.nextLine();

            switch (opcion)
            {
                case 1:
                    inventario.addLibro(scanner);
                    break;
                case 2:
                    inventario.mostrarLibros();
                    break;
                case 3:
                    inventario.eliminarLibro(scanner);
                    break;
                case 4:
                    inventario.buscarXTitulo(scanner);
                    break;
                case 5:
                    inventario.actualizarPrecio(scanner);
                    break;
                case 6:
                    inventario.precioTotal();
                    break;
                case 7:
                    inventario.totalLibros();
                    break;
                case 8:
                    inventario.masCaro();
                    break;
                case 9:
                    inventario.masBarato();
                    break;
                case 0:
                    System.out.println("Saliendo del programa.");
                    break;
                default:
                    System.out.println("Opción inválida. Intente nuevamente.");

            }



        } while (opcion != 0);

         */

        /* EJ 2!!!!!!!!!
        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingrese el nombre: ");
        String nombre = scanner.nextLine();

        System.out.println("Ingrese la edad: ");
        int edad = scanner.nextInt();
        scanner.nextLine();

        System.out.println("Ingrese el sexo (H/M): ");
        String sexoInput = scanner.nextLine().trim().toUpperCase();
        Sexo sexo = sexoInput.equals("M") ? Sexo.M : Sexo.H;

        System.out.println("Ingrese el peso (kg): ");
        double peso = scanner.nextDouble();

        System.out.println("Ingrese la altura (m): ");
        double altura = scanner.nextDouble();


        Persona p1 = new Persona(nombre, edad, "", sexo, peso, altura);
        Persona p2 = new Persona(nombre, edad, sexo);
        Persona p3 = new Persona();


        p3.setNombre("Persona por defecto");
        p3.setEdad(30);
        p3.setSexo(Sexo.M);
        p3.setPeso(70);
        p3.setAltura(1.75);


        Map<String, Persona> personas = new HashMap<>();
        personas.put(p1.getDNI(), p1);
        personas.put(p2.getDNI(), p2);
        personas.put(p3.getDNI(), p3);


        for (Map.Entry<String, Persona> entry : personas.entrySet()) {
            Persona persona = entry.getValue();
            System.out.println("\n--- Datos de la persona ---");
            System.out.println(persona);
            persona.calcularIMC();
        }

         */

        //EJ 3
        Artista artista1 = new Artista("Soda Stereo", 40, "Argentina");
        Artista artista2 = new Artista("Shakira", 45, "Colombia");

        Album album1 = new Album(LocalDate.of(1986, 6, 1), "Signos", artista1);
        Album album2 = new Album(LocalDate.of(2001, 11, 13), "Laundry Service", artista2);

        Cancion cancion1 = new Cancion("Persiana Americana", 4.52, Genero.ROCK, album1, "");
        Cancion cancion2 = new Cancion("Prófugos", 5.19, Genero.ROCK, album1, "");
        Cancion cancion3 = new Cancion("Whenever, Wherever", 3.15, Genero.POP, album2, "");
        Cancion cancion4 = new Cancion("Objection (Tango)", 3.42, Genero.POP, album2, "");

        List<Cancion> canciones = new ArrayList<>();

        canciones.add(cancion1);
        canciones.add(cancion2);
        canciones.add(cancion3);
        canciones.add(cancion4);

    }
}
