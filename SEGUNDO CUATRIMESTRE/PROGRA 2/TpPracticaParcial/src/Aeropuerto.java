import aviones.Avion;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Aeropuerto {
    static public String NOMBRE = "aeropuerto internacional Astor Piazzolla";
    static public String CODIGO = "MDQ";
    static public String DIRECCION = "Autovía 2 Km 398.5, Mar del Plata, Provincia de Buenos Aires";
    static public int CAPACIDAD = 30;

    private Map<String, List<Avion>> hangares = new HashMap<>();

    public Aeropuerto()
    {
        hangares.put("HangarComercial", new ArrayList<>());
        hangares.put("HangarPrivado", new ArrayList<>());
        hangares.put("HangarCarga", new ArrayList<>());
        hangares.put("HangarMlitar", new ArrayList<>());
    }
    public Map<String, List<Avion>> getHangares() {
        return hangares;
    }
    public void agregarAvion(String hangar, Avion avion)
    {
        int totalAviones = 0;

        for(List<Avion> listaAviones : hangares.values())
        {
            totalAviones += listaAviones.size();
        }
        if (totalAviones >= CAPACIDAD)
        {
            System.out.println("No se pueden agregar mas aviones, capacidad maxima alcanzada.");
            return;
        }

        List<Avion> listaAviones = hangares.get(hangar);

        if(listaAviones != null)
        {
            listaAviones.add(avion);
            System.out.println("Avión agregado al " + hangar);
        }else {
            System.out.println("Hangar inexistente: " + hangar);
        }
    }

    public void despegarHangar(String hangar) {
        List<Avion> listaAviones = hangares.get(hangar);
        if (listaAviones == null) {
            System.out.println("Hangar inexistente: " + hangar);
            return;
        }

        if (listaAviones.isEmpty()) {
            System.out.println("No hay aviones en el " + hangar + " para despegar.");
            return;
        }

        System.out.println("Despegando aviones del " + hangar + "...");
        for (Avion a : listaAviones) {
            a.despegar();
            System.out.println("Avión " + a.getNombreDeModelo() + " despegó.");
        }
    }

    public void listarAviones() {
        for (String hangar : hangares.keySet()) {
            System.out.println("=== " + hangar + " ===");
            List<Avion> lista = hangares.get(hangar);
            if (lista.isEmpty()) {
                System.out.println("No hay aviones en este hangar.");
            } else {
                for (Avion a : lista) {
                    System.out.println("ID: " + a.getId() + " - Modelo: " + a.getNombreDeModelo() + " - Marca: " + a.getMarca());
                }
            }
        }
    }
}




