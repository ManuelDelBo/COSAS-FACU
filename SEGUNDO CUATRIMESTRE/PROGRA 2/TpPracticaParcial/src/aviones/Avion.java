package aviones;

public abstract class Avion {
    public static int contador;
    private int id;
    private String nombreDeModelo;
    private String marca;
    private int capacidadCombustible;
    private String tipoDeMotor;
    private int cantidadDeAsientos;

    public Avion(String nombreDeModelo, String marca, int capacidadCombustible, String tipoDeMotor, int cantidadDeAsientos) {
        this.id = contador++;
        this.nombreDeModelo = nombreDeModelo;
        this.marca = marca;
        this.capacidadCombustible = capacidadCombustible;
        this.tipoDeMotor = tipoDeMotor;
        this.cantidadDeAsientos = cantidadDeAsientos;
    }

    public Avion() {
    }

    public int getId() {
        return id;
    }

    public String getNombreDeModelo() {
        return nombreDeModelo;
    }

    public void setNombreDeModelo(String nombreDeModelo) {
        this.nombreDeModelo = nombreDeModelo;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public int getCapacidadCombustible() {
        return capacidadCombustible;
    }

    public void setCapacidadCombustible(int capacidadCombustible) {
        this.capacidadCombustible = capacidadCombustible;
    }

    public String getTipoDeMotor() {
        return tipoDeMotor;
    }

    public void setTipoDeMotor(String tipoDeMotor) {
        this.tipoDeMotor = tipoDeMotor;
    }

    public int getCantidadDeAsientos() {
        return cantidadDeAsientos;
    }

    public void setCantidadDeAsientos(int cantidadDeAsientos) {
        this.cantidadDeAsientos = cantidadDeAsientos;
    }

    //METODOS

    public abstract void despegar();
    public abstract void aterrizar();
    public abstract void volando();
}
