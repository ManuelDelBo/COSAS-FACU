import exceptions.TemperaturaInvalidaException;

public class Horno {
    private int temperatura;

    public void setTemperatura(int temp) throws TemperaturaInvalidaException
    {
        if(temp < 0 || temp > 250)
        {
            throw new TemperaturaInvalidaException("Temperatura inválida. Debe estar entre 0 y 250 °C.");
        }
        this.temperatura = temp;
    }
}
