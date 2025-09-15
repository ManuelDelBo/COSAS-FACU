package carpetaUsuarios;
import carpetaLibros.Libros;
import java.util.List;
import java.util.Scanner;

public abstract class Usuario{
    public static int contador;
    private int id;
    private String nombre;
    private String dni;
    private String direccion;

    //CONSTRUCTORES
    public Usuario() {
    }
    public Usuario(String nombre, String dni, String direccion) {
        this.id = contador++;
        this.nombre = nombre;
        this.dni = dni;
        this.direccion = direccion;
    }

    //GETTERS Y SETTERS
    public int getId() {
        return id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getDni() {
        return dni;
    }

    public void setDni(String dni) {
        this.dni = dni;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    //METODOS
    public void buscar(Scanner scanner, List<Libros> biblioteca)
    {
        if (biblioteca.isEmpty()) {
            System.out.println("La biblioteca está vacía.");
            return;
        }
        for(Libros libro : biblioteca)
        {
            System.out.println(libro.toStringIdTitulo());
        }
        System.out.println("Ingrese el id del libro que desee buscar:");
        int idIngresado = scanner.nextInt();
        scanner.nextLine();

        boolean encontrado = false;

        for(Libros libro1 : biblioteca)
        {
            if(libro1.getId() == idIngresado)
            {
                System.out.println("Libro encontrado: " + libro1.toString());
                encontrado = true;
                return;
            }
        }
        if (!encontrado)
        {
            System.out.println("El libro buscado no se ha encontrado;");
        }

    }

    public void consultarDetalles(Scanner scanner, List<Libros> biblioteca)
    {
        if(biblioteca.isEmpty())
        {
            System.out.println("Biblioteca vacia.");
        }
        else
        {
            System.out.println("LIBROS:");
            for(Libros libro : biblioteca)
            {
                System.out.println(libro.toStringIdTitulo());
            }
            System.out.println("Ingrese el ID:");
            int idIngresado = scanner.nextInt();
            scanner.nextLine();

            for (Libros libro1 : biblioteca)
            {
                if(libro1.getId() == idIngresado)
                {
                    System.out.println("Detalle del libro: " + libro1.toString());
                }
            }
        }
    }

}
