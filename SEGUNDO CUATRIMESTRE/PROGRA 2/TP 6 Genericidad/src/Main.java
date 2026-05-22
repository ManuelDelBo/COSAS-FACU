import exceptions.AlamacenVacioException;
import exceptions.ElementoNoEncontradoException;

public class Main {
    public static void main(String[] args) {


       // ALMACEN NUMEROS
       Almacenamiento<Integer> almacenamientoNumeros = new Almacenamiento<Integer>();

       almacenamientoNumeros.agregarEnAlmacen(100);
       almacenamientoNumeros.agregarEnAlmacen(254);
       almacenamientoNumeros.agregarEnAlmacen(54);
       almacenamientoNumeros.agregarEnAlmacen(912);
       almacenamientoNumeros.agregarEnAlmacen(1000);

        try {
            almacenamientoNumeros.mostrarEnAlmacen();
        } catch (AlamacenVacioException e) {
            System.out.println(e.getMessage());
        }

        try {
            almacenamientoNumeros.eliminarDeAlmacen(1000000);
        } catch (ElementoNoEncontradoException e) {
            System.out.println(e.getMessage());
        } catch (AlamacenVacioException e) {
            System.out.println(e.getMessage());
        }

        try {
            almacenamientoNumeros.mostrarEnAlmacen();
        } catch (AlamacenVacioException e) {
            System.out.println(e.getMessage());
        }

        try {
            almacenamientoNumeros.buscarEnAlmacen(912);
        } catch (ElementoNoEncontradoException e) {
            System.out.println(e.getMessage());
        } catch (AlamacenVacioException e) {
            System.out.println(e.getMessage());
        }

        // ALMACEN NOMBRES
        Almacenamiento<String> almacenamientoNombres = new Almacenamiento<String>();


        almacenamientoNombres.agregarEnAlmacen("Julio");
        almacenamientoNombres.agregarEnAlmacen("Hugo");
        almacenamientoNombres.agregarEnAlmacen("Alexis");
        almacenamientoNombres.agregarEnAlmacen("Maria");


        try {
            almacenamientoNombres.mostrarEnAlmacen();
        } catch (AlamacenVacioException e) {
            System.out.println(e.getMessage());
        }

        try {
            almacenamientoNombres.eliminarDeAlmacen("Alexis");
        } catch (ElementoNoEncontradoException e) {
            System.out.println(e.getMessage());
        } catch (AlamacenVacioException e) {
            System.out.println(e.getMessage());
        }

        try {
            almacenamientoNombres.mostrarEnAlmacen();
        } catch (AlamacenVacioException e) {
            System.out.println(e.getMessage());
        }

        try {
            almacenamientoNombres.buscarEnAlmacen("Maria");
        } catch (ElementoNoEncontradoException e) {
            System.out.println(e.getMessage());
        } catch (AlamacenVacioException e) {
            System.out.println(e.getMessage());
        }

    }
}
