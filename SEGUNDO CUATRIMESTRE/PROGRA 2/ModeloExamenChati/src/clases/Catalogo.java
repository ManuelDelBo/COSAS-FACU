package clases;

import enumeradores.GENERO;

import java.util.*;

public class Catalogo {
    ArrayList<Material> catalogo = new ArrayList<>();

    public void buscar(String titulo)
    {
        for(Material m : catalogo)
        {
            if(m.getTitulo().equals(titulo))
            {
                System.out.println("Material encontrado: Titulo: " + m.getTitulo() + " Estado: " + m.disponibilidad);
                return;
            }
        }
        System.out.println("No hay ningun material con ese titulo.");
        return;

    }

    public void consultarDetalles(String titulo)
    {
        for(Material m : catalogo)
        {
            if(m.getTitulo().equalsIgnoreCase(titulo))
            {
                System.out.println("Detalle del material buscado: " + m.toString());
                return;
            }
        }
        System.out.println("No se encontrò nuncun material con este titulo.");
    }

    public void añadirMaterial(Material m)
    {
        catalogo.add(m);
    }

    public void eliminarMaterial(int id)
    {
        ListIterator<Material> iterator = catalogo.listIterator();
        while (iterator.hasNext())
        {
            Material m = iterator.next();
            if(m.getId() == id)
            {
                iterator.remove();
                System.out.println("Material eliminado correctamente.");
                return;
            }
        }
        System.out.println("Material no encontrado.");
    }

    public void modificar(String titulo, Scanner scanner)
    {
        ListIterator<Material> iterator = catalogo.listIterator();
        while (iterator.hasNext())
        {
            Material m = iterator.next();
            if(m.getTitulo().equalsIgnoreCase(titulo))
            {
                if(m instanceof Pelicula)
                {
                    Pelicula pelicula = (Pelicula) m;

                    System.out.println("Ingrese nuevo titulo: ");
                    pelicula.setTitulo(scanner.nextLine());

                    System.out.println("Ingrese nuevo año: ");
                    pelicula.setAño(scanner.nextLine());

                    System.out.println("Ingrese nuevo director: ");
                    pelicula.setDirector(scanner.nextLine());

                    System.out.println("Ingrese nueva duracion: ");
                    ((Pelicula) pelicula).setDuracionMinutos(scanner.nextInt());
                    scanner.nextLine();

                } else if (m instanceof Series) {
                    Series serie = (Series) m;

                    System.out.println("Ingrese nuevo titulo: ");
                    serie.setTitulo(scanner.nextLine());

                    System.out.println("Ingrese nuevo año: ");
                    serie.setAño(scanner.nextLine());

                    System.out.println("Ingrese nuevo director: ");
                    serie.setDirector(scanner.nextLine());

                    System.out.println("Ingrese nueva cantidad de episodios: ");
                    serie.setCantidadEpisodios(scanner.nextInt());
                    scanner.nextLine();

                    System.out.println("Ingrese nueva cantidad de temporadas: ");
                    serie.setCantidadTemporadas(scanner.nextInt());
                    scanner.nextLine();
                } else if (m instanceof Documental) {
                    Documental docu = (Documental) m;

                    System.out.println("Ingrese nuevo titulo: ");
                    docu.setTitulo(scanner.nextLine());

                    System.out.println("Ingrese nuevo año: ");
                    docu.setAño(scanner.nextLine());

                    System.out.println("Ingrese nuevo director: ");
                    docu.setDirector(scanner.nextLine());

                    System.out.println("Ingrese nueva tematica: ");
                    docu.setTematica(scanner.nextLine());
                }
                return;
            }
        }
        System.out.println("Material no encontrado.");
    }

    public void ordenarPorTitulo()
    {
        catalogo.sort(Comparator.comparing(Material::getTitulo));
    }

    public void ordenarPorId()
    {
        catalogo.sort(Comparator.comparing(Material::getId));
    }

    public void filtrarPorGenero(GENERO genero)
    {
        ArrayList<Material> listaGeneros = new ArrayList<>();

        for(Material m : catalogo)
        {
            if(m.getGenero() == genero)
            {
                listaGeneros.add(m);
            }
        }
        System.out.println("Lista genero: " + genero + listaGeneros.toString());
    }
}


