package exceptions;

public class EdadInvalidaException extends Exception{
    public EdadInvalidaException() {
        super("Edad inválida. Debe estar entre 0 y 120.");
    }
}
