package Main;
import Clases.Universidad;


public class Main {
    public static void main(String[] args) {
        Universidad u = new Universidad();

        u.cargarDesdeJSON("prueba.json");
        System.out.println("Datos cargados exitosamente.");

        u.listarCursos();

    }
}
