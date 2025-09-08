public class Cuenta {
    int id;
    String nombre;
    double balance;


    public Cuenta() {
    }
    public Cuenta(int id, String nombre, double balance) {
        this.id = id;
        this.nombre = nombre;
        this.balance = balance;
    }
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public String getNombre() {
        return nombre;
    }
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    public double getBalance() {
        return balance;
    }
    public void setBalance(double balance) {
        this.balance = balance;
    }

    public double credito(double deposito)
    {
        System.out.println("Balnace inicial " + balance);
        balance = balance + deposito;
        System.out.println("Balnace tras deposito " + balance);
        return balance;
    }

    public double debito(double extraccion)
    {

        if(balance < extraccion)
        {
            System.out.println("dinero en cuenta insuficiente para realizar extraccion.");
            return balance;
        }
        else
        {
            System.out.println("Balnace inicial " + balance);
            balance = balance - extraccion;
            System.out.println("Balnace tras extaccion " + balance);
            return balance;
        }

    }

    public void imprimir()
    {
        System.out.println("DATOS DE CUENTA: id " + id + ", nombre " + nombre + ", balance " + balance);
    }
}
