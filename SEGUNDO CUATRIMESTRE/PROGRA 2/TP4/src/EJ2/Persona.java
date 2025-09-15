package EJ2;

public class Persona {
    public static int contador;
    private int id;
    private String nombre;
    private int edad;
    private String DNI;
    private Sexo sexo;
    private double peso;
    private double altura;

    //CONSTRUCTORES
    public Persona() {
        this.id = contador++;
        this.nombre = "";
        this.edad = 0;
        this.DNI = generaDNI();
        this.sexo = Sexo.H;
        this.peso = 0;
        this.altura = 0.0;
    }
    public Persona(String nombre, int edad, Sexo sexo) {
        this.id = contador++;
        this.nombre = nombre;
        this.edad = edad;
        this.DNI = "";
        this.sexo = sexo;
        this.peso = 0;
        this.altura = 0.0;
    }
    public Persona(String nombre, int edad, String DNI, Sexo sexo, double peso, double altura) {
        this.id = contador++;
        this.nombre = nombre;
        this.edad = edad;
        this.DNI = generaDNI();
        this.sexo = sexo;
        this.peso = peso;
        this.altura = altura;
    }

    //SETTERS


    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public void setSexo(Sexo sexo) {
        this.sexo = sexo;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    //METODOS
    public int calcularIMC()
    {
        double imc = (peso/(altura*altura));
        if(imc<20)
        {
            System.out.println("Infrapeso");
            return -1;
        } else if (imc>=20 && imc<=25) {
            System.out.println("Peso ideal");
            return 0;
        } else
        {
            System.out.println("Sobrepeso");
            return 1;
        }
    }

    public boolean esMayorDeEdad()
    {
        if (edad>=18)
        {
            return true;
        } else
        {
            return false;
        }
    }

    public Sexo comprobarSexo(Sexo sexo)
    {
        if(this.sexo.equals(sexo))
        {
            return sexo;
        }
        else
        {
            return Sexo.H;
        }
    }

    @Override
    public String toString() {
        return "Persona{" +
                "id=" + id +
                ", nombre='" + nombre + '\'' +
                ", edad=" + edad +
                ", DNI='" + DNI + '\'' +
                ", sexo=" + sexo +
                ", peso=" + peso +
                ", altura=" + altura +
                '}';
    }

    public String generaDNI()
    {
        int numero = (int) (Math.random() * 100000000);
        String letras = "TRWAGMYFPDXBNJZSQVHLCKE";
        char letra = letras.charAt(numero % 23);
        return String.format("%08d%c", numero, letra);
    }

    public String getDNI() {
        return DNI;
    }
}

