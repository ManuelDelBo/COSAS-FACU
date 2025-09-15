package carpetaUsuarios;

import carpetaLibros.Libros;

import java.util.List;

public interface Prestamos {
    public void pedirPrestado(int id, List<Libros> biblioteca);
    public void devolver(int id, List<Libros> biblioteca);

}
