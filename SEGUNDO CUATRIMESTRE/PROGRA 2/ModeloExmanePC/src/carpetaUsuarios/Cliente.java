package carpetaUsuarios;
import carpetaLibros.Libros;
import carpetaLibros.TipoMaterial;
import java.util.List;

public class Cliente extends Usuario implements Prestamos{

    //CONSTRUCTORES
    public Cliente(String nombre, String dni, String direccion) {
        super(nombre, dni, direccion);
    }

    public Cliente() {
    }

    //METODOS
    @Override
    public void pedirPrestado(int id, List<Libros> biblioteca)
    {
        if(biblioteca.isEmpty())
        {
            System.out.println("No hay libros disponibles.");
            return;
        }
        else
        {
            for(Libros material : biblioteca)
            {
                if(material.getTipoMaterial() != TipoMaterial.EBOOK && material.getId() == id)
                {
                    if(material.isDisponible())
                    {
                        material.setDisponible(false);
                        System.out.println("Has pedido prestado: " + material.getTitulo());
                    }
                    else {
                        System.out.println("El material ya esta prestado.");
                    }
                    return;
                }

            }
            System.out.println("Id erroneo.");
        }
    }

    @Override
    public void devolver(int id, List<Libros> biblioteca) {
        if(biblioteca.isEmpty())
        {
            System.out.println("No hay material disponible.");
        }
        else
        {
            for(Libros material : biblioteca)
            {
                if (material.getId() == id && material.getTipoMaterial() != TipoMaterial.EBOOK)
                {
                    if(!material.isDisponible())
                    {
                        material.setDisponible(true);
                        System.out.println("Libro " + material.getTitulo() + " devuelto");
                    }
                    else
                    {
                        System.out.println("EL libro no estaba prestado.");
                    }
                }
                else
                {
                    System.out.println("Id erroneo.");
                }
            }
        }
    }


}
