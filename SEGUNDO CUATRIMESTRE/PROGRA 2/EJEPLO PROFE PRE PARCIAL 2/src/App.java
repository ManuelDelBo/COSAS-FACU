import manejoJSON.JSONUtiles;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class App {
    public static void main(String[] args) {
        try {
            JSONObject json = new JSONObject(JSONUtiles.leer("prueba.json"));
            JSONObject jTienda = json.getJSONObject("tienda");
            Tienda t = new Tienda();
            t.setNombre(jTienda.getString("nombre"));
            t.setUbicacion(jTienda.getString("ubicacion"));
            JSONArray jProductos = jTienda.getJSONArray("productos");
            List<Producto> productos = new ArrayList<>();
            for (int i = 0 ; i<jProductos.length();i++){
                JSONObject jProducto = jProductos.getJSONObject(i);
                Producto p = cargarProducto(jProducto);
                if (p!=null){
                    productos.add(p);
                }
            }

            t.setProductos(productos);

        } catch (JSONException e) {
            throw new RuntimeException(e);
        }
    }

    public static Producto cargarProducto(JSONObject jProducto) throws JSONException {
        Producto p;


        switch (jProducto.getString("tipo")){
            case "DispositivoMovil":
                p = new DispositivoMovil();
                DispositivoMovil d = (DispositivoMovil) p;
                d.setNombre(jProducto.getString("nombre"));
                d.setPrecio(jProducto.getDouble("precio"));
                d.setSoporta5g(jProducto.getBoolean("soporta5G"));
                d.setSistOperativo(jProducto.getString("sistemaOperativo"));
                return d;
                break;
            case "Portatil":
                p = new Portatil();
                Portatil port = (Portatil) p;
                port.setNombre(jProducto.getString("nombre"));
                port.setPrecio(jProducto.getDouble("precio"));
                port.setTipoAlmacenamiento(jProducto.getString("tipoAlmacenamiento"));
                port.setSistOperativo(jProducto.getString("sistemaOperativoPreinstalado"));
                return port;
                break;
            case "Accesorio":

                break;
            default:

                return null;
                break;
        }

    }


}
