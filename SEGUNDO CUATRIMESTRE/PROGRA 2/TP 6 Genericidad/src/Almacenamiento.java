import exceptions.AlamacenVacioException;
import exceptions.ElementoNoEncontradoException;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Almacenamiento<T>{
    private List<T> Almacen;

    public Almacenamiento() {
        this.Almacen = new ArrayList<>();
    }

    public void agregarEnAlmacen(T elemento)
    {
        Almacen.add(elemento);
    }

    public void eliminarDeAlmacen(T elemento) throws ElementoNoEncontradoException, AlamacenVacioException
    {
        if (Almacen.isEmpty())
        {
            throw new AlamacenVacioException("No se puede eliminar elementos ya que el Almacen se encuentra vacio.");
        }
        Iterator<T> iterator = Almacen.iterator();
        while (iterator.hasNext())
        {
            T aux = iterator.next();
            if(aux.equals(elemento))
            {
                iterator.remove();
                return;
            }
        }
        throw new ElementoNoEncontradoException("El elemento " + elemento + " no fue encontrado en el almacen.");
    }

    public void buscarEnAlmacen(T elemento) throws ElementoNoEncontradoException, AlamacenVacioException
    {
        if(Almacen.isEmpty())
        {
            throw new AlamacenVacioException("No se puede buscar: el almacén está vacío.");
        }
        int pos = 0;
        Iterator<T> iterator = Almacen.iterator();
        while (iterator.hasNext())
        {
            T aux = iterator.next();
            if (aux.equals(elemento))
            {
                System.out.println("Elemento " + elemento + " encontrado en posicion " + pos);
                return;
            }
            pos++;
        }
        throw new ElementoNoEncontradoException("El elemento " + elemento + " no fue encontrado en el almacen");
    }

    public void mostrarEnAlmacen() throws AlamacenVacioException
    {
        if(Almacen.isEmpty())
        {
            throw new AlamacenVacioException("Almacen vacio, no se puede mostrar.");
        }
        int pos = 0;
        for(T elemento : Almacen)
        {
            System.out.println(pos + ": " + elemento);
            pos++;
        }
    }
}
