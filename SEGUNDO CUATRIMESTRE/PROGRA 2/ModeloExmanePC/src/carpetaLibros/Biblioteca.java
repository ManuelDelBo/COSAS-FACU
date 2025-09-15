package carpetaLibros;
import java.util.ArrayList;
import java.util.List;


public class Biblioteca {
    List<Libros> biblioteca = new ArrayList();

    //CONSTRUCTORES
    public Biblioteca(List<Libros> biblioteca) {
        this.biblioteca = biblioteca;
    }
    public Biblioteca() {
    }

    //METODOS
    public void agregarMaterial(Libros libro)
    {
        biblioteca.add(libro);
    }
    public void mostrarLibrosDisponibles()
    {

        System.out.println("Libros disponibles:");
        for(Libros libro : biblioteca)
        {
            if(libro.isDisponible())
            {
                System.out.println(libro.toStringIdTitulo());
            }
        }


    }

}
