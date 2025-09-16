import clases.*;
import enumeradores.DISPONIBILIDAD;
import enumeradores.GENERO;

import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class Main {
    public static void main(String[] args)
    {
        Catalogo catalogo = new Catalogo();

        Pelicula peli1 = new Pelicula("Inception", "Christopher Nolan", "2010", GENERO.CIENCIAFICCION, DISPONIBILIDAD.SOLOSUSCRIPCION, 148);
        Series serie1 = new Series("Friends", "David Crane", "1996", GENERO.COMEDIA, DISPONIBILIDAD.DISPONIBLE, 9, 203);
        Documental documental1 = new Documental("JOJOJO", "Mariano Pavone", "2024", GENERO.TERROR, DISPONIBILIDAD.SOLOSUSCRIPCION, "Antropologia");

        catalogo.añadirMaterial(peli1);
        catalogo.añadirMaterial(serie1);
        catalogo.añadirMaterial(documental1);


    }
}
