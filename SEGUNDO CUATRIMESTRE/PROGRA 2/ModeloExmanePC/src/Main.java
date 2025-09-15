import carpetaLibros.*;

public class Main {
    public static void main(String[] args)
    {
        Biblioteca biblioteca = new Biblioteca();

        biblioteca.agregarMaterial(new Libro("Orgullo y Prejuicio", "Jane Austen", "1813", TipoMaterial.LIBRO, 279, GENERO.ROMANCE));
        biblioteca.agregarMaterial(new Ebook("El Hobbit", "J.R.R. Tolkien", "1937", TipoMaterial.EBOOK, "PDF"));
        biblioteca.agregarMaterial(new Revista("National Geographic", "Varios Autores", "2023", TipoMaterial.REVISTA, true));
    }
}
