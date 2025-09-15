package Ej1;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;
import java.util.Scanner;

public class Inventario {
    private List<Libro> Libros = new ArrayList<>();

    public Inventario(List<Libro> libros) {
        Libros = libros;
    }

    public Inventario() {
    }

    public void addLibro(Scanner scanner)
    {
        System.out.println("Ingrese el titulo del libro: ");
        String titulo = scanner.nextLine();

        System.out.println("Ingrese el autor: ");
        String autor = scanner.nextLine();

        System.out.println("Ingrese el precio: ");
        Double precio = scanner.nextDouble();
        scanner.nextLine();

        System.out.println("Ingrese fecha de publicación (yyyy-MM-dd): ");
        String fechaPublicacion = scanner.nextLine();
        LocalDate fecha = LocalDate.parse(fechaPublicacion);

        Libro nuevoLibro = new Libro(titulo, autor, precio, fecha);

        Libros.add(nuevoLibro);

        System.out.println("Libro añadido correctamente.");
    }

    public void mostrarLibros()
    {
        if(Libros.isEmpty())
        {
            System.out.println("La lista esta vacia, no hay libros que mostrar.");
            return;
        } else
        {
            ListIterator<Libro> iterador = Libros.listIterator();
            while (iterador.hasNext())
            {
                Libro libro = iterador.next();
                System.out.println(libro.toString());
            }
        }
    }

    public void eliminarLibro(Scanner scanner)
    {
        if (Libros.isEmpty()) {
            System.out.println("La lista está vacía, no hay libros que eliminar.");
            return;
        }
        System.out.println("Lista de libros:");
        ListIterator<Libro> iterador = Libros.listIterator();
        while (iterador.hasNext())
        {
            Libro libro = iterador.next();
            System.out.println(libro.toStringIdTitulo());
        }
        System.out.println("Ingrese el id del libro a eliminar: ");
        int eleccion = scanner.nextInt();
        scanner.nextLine();

        boolean eliminado = false;

        iterador = Libros.listIterator();
        while (iterador.hasNext())
        {
            Libro libro = iterador.next();
            if(libro.getId() == eleccion)
            {
                iterador.remove();
                eliminado = true;
                System.out.println("Libro id: " + eleccion + " eliminado correctamente");
                break;
            } else
            {
                System.out.println("No se encontro el libro buscado. ");
            }
        }
    }

    public void buscarXTitulo(Scanner scanner)
    {
        System.out.println("Ingrese el titulo del libro que desea buscar: ");
        String tituloIngresado = scanner.nextLine();

        if (Libros.isEmpty())
        {
            System.out.println("El inventario esta vacio, no hay libros");
            return;
        }
        ListIterator<Libro> iterator = Libros.listIterator();
        boolean encontrado = false;
        while (iterator.hasNext())
        {
            Libro libro = iterator.next();
            if(libro.getTitulo().equals(tituloIngresado))
            {
                System.out.println("Libro encontrado: ");
                System.out.println(libro.toString());

                encontrado = true;
                break;
            }
        }
        if(!encontrado)
        {
            System.out.println("Titulo erroneo, no se encontrò ningun titulo con el nombre: " + tituloIngresado);
        }
    }

    public void actualizarPrecio(Scanner scanner)
    {
        if(Libros.isEmpty())
        {
            System.out.println("No hay libros en el inventario.");
            return;
        }
        ListIterator<Libro> iterador = Libros.listIterator();
        while (iterador.hasNext())
        {
            Libro libro = iterador.next();
            System.out.println("ID: " + libro.getId() + " - " + "Titulo: " + libro.getTitulo() + " - " + " Precio: " + libro.getPrecio());
        }
        System.out.println("Ingrese el ID del libro que desea actualizar el precio: ");
        int idIngresado = scanner.nextInt();
        scanner.nextLine();

        boolean encontrado = false;
        iterador = Libros.listIterator();
        while(iterador.hasNext())
        {
            Libro libro = iterador.next();
            if(libro.getId() == idIngresado)
            {
                System.out.println("ingrese el nuevo precio del libro (precio anterior $" + libro.getPrecio() + "): ");
                double precioNuevo = scanner.nextDouble();
                scanner.nextLine();

                libro.setPrecio(precioNuevo);
                System.out.println("Precio acutalizado correctamente, nuevo precio: $" + libro.getPrecio());
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
        {
            System.out.println("El id ingresado es incorrecto.");
        }
    }
    public void precioTotal()
    {
        if (Libros.isEmpty())
        {
            System.out.println("Inventario vacio.");
            return;
        }
        double total = 0;
        ListIterator<Libro> iterator = Libros.listIterator();
        while (iterator.hasNext())
        {
            Libro libro = iterator.next();
            total += libro.getPrecio();
        }
        System.out.println("EL precio total de todos los libros es: $" + total);

    }

    public void totalLibros()
    {
        if(Libros.isEmpty())
        {
            System.out.println("El inventario està vacio.");
        }

        int contador = 0;
        ListIterator<Libro> iterator = Libros.listIterator();

        while (iterator.hasNext())
        {
            contador++;
        }

        System.out.println("La cantidad de libros en el inventario es " + contador);
    }

    public void masCaro()
    {
        if(Libros.isEmpty())
        {
            System.out.println("El inventario està vacio.");
            return;
        }
        ListIterator<Libro> iterator = Libros.listIterator();

        Libro libroCaro = iterator.next();
        double caro = libroCaro.getPrecio();
        while (iterator.hasNext())
        {
            Libro libro = iterator.next();
            if (caro < libro.getPrecio())
            {
                caro = libro.getPrecio();
                libroCaro = libro;
            }
        }
        System.out.println("El libro mas caro es " + libroCaro.getTitulo() + " - Precio: $" + libroCaro.getPrecio());
    }

    public void masBarato()
    {
        if(Libros.isEmpty())
        {
            System.out.println("El inventario està vacio.");
            return;
        }
        ListIterator<Libro> iterator = Libros.listIterator();

        Libro libroBarato = iterator.next();
        double barato = libroBarato.getPrecio();
        while (iterator.hasNext())
        {
            Libro libro = iterator.next();
            if (barato > libro.getPrecio())
            {
                barato = libro.getPrecio();
                libroBarato = libro;
            }
        }
        System.out.println("El libro mas caro es " + libroBarato.getTitulo() + " - Precio: $" + libroBarato.getPrecio());
    }

}
