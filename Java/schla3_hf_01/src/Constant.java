public class Constant implements Differentiable {
    double konstans;
    public Constant(double constant)
    {
        konstans=constant;
    }
    @Override
    public Differentiable diff() throws UnknownFunctionException, UnknownOperatorException {
        return new Constant(0);
    }

    @Override
    public String toString()
    {
        if(konstans<0)
            return "("+String.valueOf(konstans)+")";
        return String.valueOf(konstans);
    }

}
