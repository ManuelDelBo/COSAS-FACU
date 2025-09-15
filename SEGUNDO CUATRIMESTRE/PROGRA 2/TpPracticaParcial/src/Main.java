import aviones.*;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        // 1. Crear aeropuerto
        Aeropuerto aeropuerto = new Aeropuerto();

        // 2. Crear aviones
        Comercial c1 = new Comercial("Boeing 737", "Boeing", 20000, "Jet", 180, 6, "Comida, Bebida");
        Comercial c2 = new Comercial("Airbus A320", "Airbus", 18000, "Jet", 150, 4, "Comida, Bebida");

        Privado p1 = new Privado("Cessna 172", "Cessna", 500, "Hélice", 4, true, "claveWifi123");
        Privado p2 = new Privado("Gulfstream G650", "Gulfstream", 1000, "Jet", 8, false, "wifiVIP");

        Carga ca1 = new Carga("Antonov An-124", "Antonov", 30000, "Jet", 0, 10000, "Electrónica, Vehículos");
        Militar m1 = new Militar("F-16", "Lockheed Martin", 7000, "Jet", 1, SistemaArmas.AIREAIRE, 500);

        // 3. Agregar aviones a hangares
        aeropuerto.agregarAvion("HangarComercial", c1);
        aeropuerto.agregarAvion("HangarComercial", c2);

        aeropuerto.agregarAvion("HangarPrivado", p1);
        aeropuerto.agregarAvion("HangarPrivado", p2);

        aeropuerto.agregarAvion("HangarCarga", ca1);

        aeropuerto.agregarAvion("HangarMilitar", m1);

        // 4. Listar todos los aviones por hangar
        aeropuerto.listarAviones();

        // 5. Despegar todos los aviones de un hangar
        System.out.println("\nIngrese el hangar a despegar aviones:");
        String hangar = scanner.nextLine();
        aeropuerto.despegarHangar(hangar);

        scanner.close();
    }

}
