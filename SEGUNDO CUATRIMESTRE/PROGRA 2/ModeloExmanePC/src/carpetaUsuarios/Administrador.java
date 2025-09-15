package carpetaUsuarios;

import carpetaLibros.*;

import javax.swing.text.WrappedPlainView;
import java.util.List;
import java.util.Scanner;

public class Administrador extends Usuario{
    private PuestoDeTrabajo puestoDeTrabajo;

    public Administrador() {
    }
    public Administrador(String nombre, String dni, String direccion, PuestoDeTrabajo puestoDeTrabajo) {
        super(nombre, dni, direccion);
        this.puestoDeTrabajo = puestoDeTrabajo;
    }

    public void altaLibro(Scanner scanner, List<Libros> biblioteca)
    {
        System.out.println("Que material desea agregar: 1-Libro Fisico / 2-Ebook / 3-Revista");
        int ingreso = scanner.nextInt();
        scanner.nextLine();

        if(ingreso == 1)
        {
            System.out.println("Ingrese el titulo del libro: ");
            String titulo = scanner.nextLine();
            System.out.println("Ingrese el autor del libro: ");
            String autor = scanner.nextLine();
            System.out.println("Ingrese el año del libro: ");
            String anio = scanner.nextLine();
            System.out.println("Ingrese la cantidad de paginas: ");
            int cantPaginas = scanner.nextInt();
            scanner.nextLine();
            System.out.println("Ingrese el genero: 1-NOVELA, 2-DISTOPIA, 3-CLASICO,4-ROMANCE");
            int generoValor = scanner.nextInt();
            scanner.nextLine();
            GENERO genero = GENERO.NOVELA;
            if(generoValor == 1){
                genero = GENERO.NOVELA;
            } else if (generoValor == 2){
                genero = GENERO.DISTOPIA;
            } else if(generoValor == 3){
                genero = GENERO.CLASICO;
            } else if(generoValor == 4){
                genero = GENERO.ROMANCE;
            }

            Libro libro = new Libro(titulo, autor, anio, TipoMaterial.LIBRO, cantPaginas, genero);

            biblioteca.add(libro);

        } else if (ingreso == 2)
        {
            System.out.println("Ingrese el titulo del ebook: ");
            String titulo = scanner.nextLine();
            System.out.println("Ingrese el autor del ebook: ");
            String autor = scanner.nextLine();
            System.out.println("Ingrese el año del ebook: ");
            String anio = scanner.nextLine();
            System.out.println("Ingrese el tipo de archivo: ");
            String tipoArchivo = scanner.nextLine();

            Ebook ebook = new Ebook(titulo, autor, anio, TipoMaterial.EBOOK, tipoArchivo);

            biblioteca.add(ebook);
        } else if (ingreso == 3)
        {
            System.out.println("Ingrese el titulo de la revista: ");
            String titulo = scanner.nextLine();
            System.out.println("Ingrese el autor de la revista: ");
            String autor = scanner.nextLine();
            System.out.println("Ingrese el año de la revista: ");
            String anio = scanner.nextLine();
            System.out.println("Es tapa dura= 1-SI / 2-NO ");
            int tapaDura = scanner.nextInt();
            scanner.nextLine();
            boolean esTapaDura = false;
            if (tapaDura == 1)
            {
                esTapaDura = true;
            } else if (tapaDura == 2) {
                esTapaDura = false;
            } else
            {
                System.out.println("Valor erroneo");
            }

            Revista revista = new Revista(titulo, autor, anio, TipoMaterial.EBOOK, esTapaDura);

            biblioteca.add(revista);
        } else
        {
            System.out.println("Valor ingresado fuera de renago.");
            return;
        }
    }

    public void bajaLibro(Scanner scanner, List<Libros> biblioteca)
    {
        chequeoVacio(biblioteca);

        mostrarIdTitulo(biblioteca);

        System.out.println("Ingrese el ID del libro que desee eliminar.");
        int idIngresado = scanner.nextInt();
        boolean encontrado = false;
        for(Libros libro1 : biblioteca)
        {
            if(idIngresado == libro1.getId())
            {
                biblioteca.remove(libro1);
                    encontrado = true;
            }
        }
        if(!encontrado)
           {
               System.out.println("Id ingresado erroneo");
           }
        return;
    }

    public void modificarLibro(Scanner scanner, List<Libros> biblioteca)
    {
        mostrarIdTitulo(biblioteca);
        System.out.println("Ingrese el ID del libro que desee modificar:");
        int idIngresado = scanner.nextInt();
        scanner.nextLine();

        for(Libros material : biblioteca)
        {
            if(idIngresado == material.getId())
            {
                if(material.getTipoMaterial() == TipoMaterial.LIBRO)
                {
                    Libro libro = (Libro) material;

                    System.out.println("Modificando LIBRO: " + libro.getTitulo());

                    System.out.println("Titulo: ");
                    libro.setTitulo(scanner.nextLine());

                    System.out.println("Autor: ");
                    libro.setAutor(scanner.nextLine());

                    System.out.println("Año: ");
                    libro.setAño(scanner.nextLine());

                    System.out.println("Cantidad de paginas: ");
                    libro.setCantidadPaginas(scanner.nextInt());
                    scanner.nextLine();

                    System.out.println("Genero: 1-NOVELA, 2-DISTOPIA, 3-CLASICO,4-ROMANCE");
                    int generoIngresado = scanner.nextInt();
                    scanner.nextLine();

                    GENERO genero = GENERO.NOVELA;
                    if(generoIngresado == 1){
                       libro.setGenero(GENERO.NOVELA);
                    } else if (generoIngresado == 2){
                        libro.setGenero(GENERO.DISTOPIA);
                    } else if(generoIngresado == 3){
                        libro.setGenero(GENERO.CLASICO);
                    } else if(generoIngresado == 4){
                        libro.setGenero(GENERO.ROMANCE);
                    }
                } else if (material.getTipoMaterial() == TipoMaterial.EBOOK) {
                    Ebook ebook = (Ebook) material;

                    System.out.println("Modificando EBOOK: " + ebook.getTitulo());

                    System.out.println("Titulo: ");
                    ebook.setTitulo(scanner.nextLine());

                    System.out.println("Autor: ");
                    ebook.setAutor(scanner.nextLine());

                    System.out.println("Año: ");
                    ebook.setAño(scanner.nextLine());

                    System.out.println("Tipo archivo: ");
                    ebook.setTipoArchivo(scanner.nextLine());

                } else if (material.getTipoMaterial() == TipoMaterial.REVISTA) {
                    Revista revista = (Revista) material;

                    System.out.println("Modificando REVISTA: " + revista.getTitulo());

                    System.out.println("Titulo: ");
                    revista.setTitulo(scanner.nextLine());

                    System.out.println("Autor: ");
                    revista.setAutor(scanner.nextLine());

                    System.out.println("Año: ");
                    revista.setAño(scanner.nextLine());

                    System.out.println("Es tapa dura= 1-SI / 2-NO ");
                    int tapaDura = scanner.nextInt();
                    scanner.nextLine();
                    boolean tapaDUraAux = false;
                    if (tapaDura == 1)
                    {
                        revista.setTapDura(true);
                    } else if (tapaDura == 2) {
                        revista.setTapDura(false);
                    } else
                    {
                        System.out.println("Valor erroneo");
                    }

                }
            }
            else
            {
                System.out.println("Id ingresado erroneo.");
            }
        }
    }

    private void mostrarIdTitulo(List<Libros> biblioteca)
    {
        System.out.println("LIBROS DISPONIBLES");
        for(Libros libro : biblioteca)
        {
            System.out.println(libro.toStringIdTitulo());
        }
    }
    private void chequeoVacio(List<Libros> biblioteca)
    {
        if(biblioteca.isEmpty())
        {
            System.out.println("Biblioteca vacia.");
            return;
        }
    }

}
