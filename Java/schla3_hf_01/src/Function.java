public class Function implements Differentiable {

    Differentiable argumentum;
    String fg;
    @Override
    public Differentiable diff() throws UnknownFunctionException, UnknownOperatorException {

        switch(fg)
        {
            case "cos":
                return  new Expression(
                        new Expression(new Constant(-1),new Function("sin",argumentum),"*"),argumentum.diff()
                        ,"*");
            case "sin":
                return new Expression(new Function("cos",argumentum),argumentum.diff(),"*");

            case "tg":
                return  new Expression(
                        new Expression(new Constant(1),
                        new Expression(new Function("cos",argumentum),new Constant(2),"^")
                        ,"/"),
                        argumentum.diff()
                        ,"*");

            case "ctg":
               return new Expression(
                        new Expression(new Constant(-1),
                                new Expression(new Function("sin",argumentum),new Constant(2),"^")
                                ,"/"),
                        argumentum.diff()
                        ,"*");
            case "ch":
                return new Expression(new Function("sh",argumentum),argumentum.diff(),"*");
            case "sh":
                return new Expression(new Function("ch",argumentum),argumentum.diff(),"*");
            case "th":
               return new Expression(
                        new Expression(new Constant(1),
                                new Expression(new Function("ch",argumentum),new Constant(2),"^")
                                ,"/"),
                        argumentum.diff()
                        ,"*");
            case "cth":
                return new Expression(
                        new Expression(new Constant(-1),
                                new Expression(new Function("sh",argumentum),new Constant(2),"^")
                                ,"/"),
                        argumentum.diff()
                        ,"*");
            case "ln":
                return  new Expression(new Expression(new Constant(1),argumentum,"/"),argumentum.diff(),"*");
            case "exp":
                return new Expression(new Function("exp",argumentum),argumentum.diff(),"*");
            case "arccos":
                return new Expression(
                        new Expression( new Constant(-1),
                                new Expression(
                                        new Expression(
                                                new Constant(1),new Expression(
                                                argumentum,new Constant(2),"^")
                                                ,"-")
                                        ,new Constant((double)1/2)
                                        ,"^"),"/"),
                        argumentum.diff()
                        ,"*");
            case "arcsin":
                return new Expression( new Expression(new Constant(1),
                        new Expression(new Expression(new Constant(1),new Expression(argumentum,new Constant(2),"^"),"-"),new Constant((double)1/2),"^"),"/")
                        ,argumentum.diff(),
                        "*");
            case "arctg":
                return new Expression(new Expression(new Constant(1), new Expression(new Constant(1),new Expression(argumentum,new Constant(2),"^"),"+"),"/"),argumentum.diff(),"*");
            case "arcctg":
                return new Expression(new Expression(new Constant(-1), new Expression(new Constant(1),new Expression(argumentum,new Constant(2),"^"),"+"),"/"),argumentum.diff(),"*");
            case "arch":
                return
                        new Expression( new Expression(new Constant(1),
                                new Expression(
                                        new Expression(
                                                new Expression(argumentum,new Constant(2),"^"),new Constant(1),"-"),new Constant((double)1/2),"^"),"/"),argumentum.diff(),"*");

            case "arsh":

                return
                        new Expression( new Expression(new Constant(1),
                                new Expression(
                                        new Expression(
                                                new Expression(argumentum,new Constant(2),"^"),new Constant(1),"+"),new Constant((double)1/2),"^"),"/"),argumentum.diff(),"*");
            case "arth":
                return
                        new Expression( new Expression(new Constant(1),
                                new Expression(
                                        new Expression(
                                                new Constant(1),new Expression(argumentum,new Constant(2),"^"),"-"),new Constant(1),"^"),"/"),argumentum.diff(),"*");
            case "arcth": return
                    new Expression( new Expression(new Constant(1),
                            new Expression(
                                    new Expression(
                                            new Constant(1),new Expression(argumentum,new Constant(2),"^"),"-"),new Constant(1),"^"),"/"),argumentum.diff(),"*");
            default:
                return null;


        }
    }
    public Function(String fg_,Differentiable diff_) throws UnknownFunctionException
    {
        switch (fg_)
        {
            case "cos":
            case "sin":
            case "tg":
            case "ctg":
            case "ch":
            case "sh":
            case "th":
            case "cth":
            case "ln" :
            case "exp" :
            case "arccos":
            case "arcsin":
            case "arctg":
            case "arcctg":
            case "arch" :
            case "arsh":
            case "arth":
            case "arcth":
                fg=fg_;
                argumentum=diff_;
                break;
                default:
                    throw new UnknownFunctionException("gond van");
        }


                }
    @Override
    public String toString()
    {
        return fg+"("+argumentum.toString()+")";
    }
}
