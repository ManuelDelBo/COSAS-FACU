import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        List<Producto> productos = cargarProductos();

        //EJ 1
        System.out.println("EJ 1 -------------------------------------------------------");

        List<Producto> electroMasMil = productos.stream()
                .filter(x -> x.getCategoria().equals("Electrónica") && x.getPrecio() >= 1000)
                .sorted(Comparator.comparing(Producto::getPrecio).reversed())
                .toList();
        electroMasMil.stream()
                .forEach(p -> System.out.println(p.getNombre() + " - $" + p.getPrecio()));

        //EJ 2
        System.out.println("EJ 2 -------------------------------------------------------");

        Double promedioHogar = productos.stream()
                .filter(p -> p.getStock() > 0)
                .mapToDouble(Producto::getPrecio)
                .average()
                .orElse(0);

        System.out.println("Precio promedio prodcutos Hogar en Stock: " + promedioHogar);

        //EJ 3
        System.out.println("EJ 3 -------------------------------------------------------");

        Map<String, Producto> masCaro = productos.stream()
                .collect(Collectors.groupingBy(
                        Producto::getCategoria,
                        Collectors.collectingAndThen(
                                Collectors.maxBy(Comparator.comparing(Producto::getPrecio)),
                                Optional::get
                        )
                ));

        masCaro.forEach((categoria, producto) -> {
            System.out.println("Categoria: " + categoria + "/ Producto mas caro: "
                    + producto.getNombre() + " $" + producto.getPrecio());
        });

        //EJ 4
        System.out.println("EJ 4 -------------------------------------------------------");

        Optional<String> deortesMasDiez = productos.stream()
                .filter(p -> p.getCategoria().equals("Deportes") && p.getStock() >= 10)
                .findFirst()
                .map(Producto::getNombre)
                .map(String::toLowerCase);

        System.out.println(deortesMasDiez.orElse("Producto Inexistente"));

        //EJ 5
        System.out.println("EJ 5 -------------------------------------------------------");

        Optional<Producto> masBarato = productos.stream()
                .min(Comparator.comparing(
                        p -> p.getStock() * p.getPrecio()
                ));
        Producto resultado = masBarato.orElseThrow();

        System.out.println("Producto mas barato en promedio por stock: " + resultado.getNombre() + " $" + resultado.getStock() * resultado.getPrecio());

        //EJ 6
        System.out.println("EJ 6 -------------------------------------------------------");

        List<String> nombresStock = productos.stream()
                .filter(p -> p.getStock() > 0 && p.getNombre().length() >= 5)
                .map(Producto::getNombre)
                .sorted()
                .toList();

        System.out.println(nombresStock);

        //EJ 7
        System.out.println("EJ 7 -------------------------------------------------------");

        double precioPromedio = productos.stream()
                .mapToDouble(Producto::getPrecio)
                .average()
                .orElse(0);

        int totalStock = productos.stream()
                .filter(p -> p.getPrecio() > precioPromedio)
                .mapToInt(Producto::getStock)
                .sum();

        System.out.println("Stock total de productos con precio meyor al promedio ($" + precioPromedio
        + "): " + totalStock);

        //EJ 8
        System.out.println("EJ 8 -------------------------------------------------------");

        Map<String, Integer> stockXCategoraias = productos.stream()
                .collect(Collectors.groupingBy(Producto::getCategoria))
                .entrySet().stream()
                .filter(e -> e.getValue().size() >= 3)
                .collect(Collectors.toMap(
                        Map.Entry::getKey,
                        e -> e.getValue().stream()
                                .mapToInt(Producto::getStock)
                                .sum()
                ));
        stockXCategoraias.forEach((categoria, stock) ->
                System.out.println(categoria + " -> " + stock)
        );

        //EJ 9
        System.out.println("EJ 9 -------------------------------------------------------");
        List<Producto> listaDescuentos = productos.stream()
                .filter(p -> p.getStock() >= 20)
                .peek(p -> p.setPrecio(p.getPrecio() * 0.85))
                .toList();

        listaDescuentos.forEach(p ->
                System.out.println("Producto con descuento (15%): " + p.getNombre() + " $" + p.getPrecio()));

        //EJ 10
        System.out.println("EJ 10 -------------------------------------------------------");

        double gananciaTotal = productos.stream()
                .mapToDouble(p -> {
                    double costo;

                    if(p.getCategoria().equals("Electrónica")) {
                        costo = p.getPrecio() * 0.65;
                    } else {
                        costo = p.getPrecio() * 0.45;
                    }

                    return (p.getPrecio() - costo) * p.getStock();
                })
                .sum();

        System.out.println("Ganancia total: $" + gananciaTotal);


    }
    public static List<Producto> cargarProductos() {
        return List.of(
                new Producto("Laptop", 1500, "Electrónica", 5),
                new Producto("Smartphone", 800, "Electrónica", 10),
                new Producto("Televisor", 1200, "Electrónica", 3),
                new Producto("Heladera", 2000, "Hogar", 2),
                new Producto("Microondas", 500, "Hogar", 8),
                new Producto("Silla", 150, "Muebles", 12),
                new Producto("Mesa", 300, "Muebles", 7),
                new Producto("Zapatillas", 100, "Deportes", 15),
                new Producto("Pelota", 50, "Deportes", 20),
                new Producto("Bicicleta", 500, "Deportes", 5),
                new Producto("Libro", 30, "Librería", 50),
                new Producto("Cuaderno", 10, "Librería", 100),
                new Producto("Lámpara", 80, "Hogar", 30),
                new Producto("Cafetera", 250, "Hogar", 6),
                new Producto("Auriculares", 120, "Electrónica", 14),
                new Producto("Teclado", 90, "Electrónica", 9),
                new Producto("Mouse", 60, "Electrónica", 18),
                new Producto("Monitor", 700, "Electrónica", 4),
                new Producto("Cama", 800, "Muebles", 2),
                new Producto("Sofá", 1000, "Muebles", 3),
                new Producto("Espejo", 120, "Hogar", 12),
                new Producto("Ventilador", 150, "Hogar", 7),
                new Producto("Patines", 180, "Deportes", 5),
                new Producto("Raqueta", 220, "Deportes", 6),
                new Producto("Taza", 15, "Hogar", 40)
        );
    }
}
