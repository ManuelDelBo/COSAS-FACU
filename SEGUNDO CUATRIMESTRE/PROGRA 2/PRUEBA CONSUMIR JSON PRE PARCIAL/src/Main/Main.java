package Main;

import ManejoJSON.JSONUtiles;
import clases.*;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {

        try {
            JSONObject json = new JSONObject(JSONUtiles.leer("prueba.json"));
            JSONObject jTienda = json.getJSONObject("tienda");
            Tienda t = new Tienda();
            t.setNombre(jTienda.getString("nombre"));
            t.setUbicacion(jTienda.getString("ubicacion"));

            JSONArray jProductos = jTienda.getJSONArray("productos");
            List<Producto> productos = new ArrayList<>();

            for(int i = 0;i<jProductos.length();i++)
            {
                JSONObject jProducto = jProductos.getJSONObject(i);
                String tipo = jProducto.getString("tipo");

                Producto p = null;

                
                if(tipo.equals("DispositivoMovil") )
                {
                    DispositivoMovil d = new DispositivoMovil();

                    d.setSoporta5G(jProducto.getBoolean("soporta5G"));
                    d.setSistemaOperativo(jProducto.getString("sistemaOperativo"));
                    p = d;
                } else if (tipo.equals("Portatil")) {
                    Portatil por = new Portatil();

                    por.setTipoAlmacenamiento(jProducto.getString("tipoAlmacenamiento"));
                    por.setSistemaOperativoPreinstalado(jProducto.getString("sistemaOperativoPreinstalado"));
                    p = por;
                    
                } else if (tipo.equals("Accesorio")) {
                    Accesorio a = new Accesorio();
                    a.setTipoConexion(jProducto.getString("tipoConexion"));
                    a.setAntiGhosting(jProducto.getBoolean("antiGhosting"));
                    p = a;
                }

                if(p != null)
                {
                    p.setTipo(jProducto.getString("tipo"));
                    p.setNombre(jProducto.getString("nombre"));
                    p.setMarca(jProducto.getString("marca"));
                    p.setPrecio(jProducto.optDouble("precio"));
                    p.setCantidadDisponible(jProducto.getInt("cantidadDisponible"));
                    p.setSeccionTienda(jProducto.getString("seccionTienda"));
                }

                JSONArray jEspecificaciones = jProducto.getJSONArray("especificaciones");
                List<Especificacion> especificaciones = new ArrayList<>();
                for(int j = 0; j<jEspecificaciones.length();j++)
                {
                    JSONObject jEspecificacion = jEspecificaciones.getJSONObject(j);
                    Especificacion e = new Especificacion();

                    e.setNombre(jEspecificacion.getString("nombre"));
                    e.setValor(jEspecificacion.getString("valor"));

                    especificaciones.add(e);
                }
                p.setEspecificacions(especificaciones);

                JSONArray jEmbalajes = jProducto.getJSONArray("embalajesDisponibles");
                List<Embalaje> embalajesDisponibles = new ArrayList<>();

                for(int k = 0; k<jEmbalajes.length();k++)
                {
                    JSONObject jEmbajale = jEmbalajes.getJSONObject(k);
                    Embalaje e = new Embalaje();

                    e.setTipo(jEmbajale.getString("tipo"));
                    e.setResistencia(jEmbajale.getString("resistencia"));
                    e.setDimensiones(jEmbajale.getString("dimensiones"));

                    embalajesDisponibles.add(e);
                }
                p.setEmbalajesDisponibles(embalajesDisponibles);

                productos.add(p);
            }
            t.setProductos(productos);

        } catch (JSONException e) {
            throw new RuntimeException(e);
        }
    }
}
