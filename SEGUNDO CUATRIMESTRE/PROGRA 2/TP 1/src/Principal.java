import java.util.Scanner;

public class Principal {
    public static void main(String[] args) {
        /*
        Empleado emp1 = new Empleado("23456345", "Carlos", "Gutierrez", 25000);
        Empleado emp2 = new Empleado("34234123", "Ana", "Sánchez", 27500);

        emp1.imprimir();
        emp2.imprimir();

        emp1.aumentarSalario(15);
        emp1.calcularSalarioAnual();

         */
        /*

        Cuenta cuenta1 = new Cuenta(1, "Jorge Drexler", 15000);

        cuenta1.credito(2500);
        cuenta1.debito(1500);
        cuenta1.debito(30000);
        cuenta1.imprimir();

         */

        /*

        Libro libro1 = new Libro("El Quijote", "Miguel de Cervantes", 500, 10);
        Libro libro2 = new Libro("Cien Años de Soledad", "Gabriel García Márquez", 700, 5);


        libro1.imprimir();
        libro2.imprimir();

        libro1.venderCopias(3);
        libro1.imprimir();

        libro2.venderCopias(8);
        libro2.incrementarDisponibles(5);

        libro2.imprimir();

         */

        Scanner scanner = new Scanner(System.in);

        System.out.print("Ingrese identificador: ");
        int id = scanner.nextInt();
        scanner.nextLine(); // limpiar el buffer

        System.out.print("Ingrese descripción: ");
        String descripcion = scanner.nextLine();

        System.out.print("Ingrese cantidad: ");
        int cantidad = scanner.nextInt();

        System.out.print("Ingrese precio unitario: ");
        double precio = scanner.nextDouble();

        ItemVenta item1 = new ItemVenta(id, descripcion, cantidad, precio);

        item1.imprimir();

        System.out.println("Ingrese una nueva cantidad del item " + item1.getDescripcion());
        int nuevaCantidad = scanner.nextInt();

        item1.setCantidad(nuevaCantidad);

        System.out.println("Ingrese el nuevo precio del item " + item1.getDescripcion());
        int nuevoPrecio = scanner.nextInt();

        item1.setPrecioUnitario(nuevoPrecio);

        item1.calcularPrecioTotal();




    }
}
