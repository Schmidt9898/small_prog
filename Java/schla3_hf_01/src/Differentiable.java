public interface Differentiable {

public String toString();
public Differentiable diff() throws UnknownFunctionException, UnknownOperatorException;
}
