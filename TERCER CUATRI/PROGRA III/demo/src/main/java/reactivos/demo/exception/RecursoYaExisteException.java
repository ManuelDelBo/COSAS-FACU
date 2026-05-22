package reactivos.demo.exception;

public class RecursoYaExisteException extends RuntimeException{
    public RecursoYaExisteException(String message) {
        super(message);
    }
}
