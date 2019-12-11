public class Identity implements Differentiable {
    public Identity()
    {

    }
    @Override
    public Differentiable diff() throws UnknownFunctionException, UnknownOperatorException {
        return new Constant(1);
    }
    @Override
    public String toString()
    {
        return "x";
    }


}
