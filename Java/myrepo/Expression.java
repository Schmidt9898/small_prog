public class Expression implements Differentiable {

    Differentiable mezo1,mezo2;
    String operandus;
    public Expression(Differentiable mezo1_, Differentiable mezo2_, String op_) throws UnknownOperatorException
    {

        switch (op_) {
            case "+":
            case "-":
            case "*":
            case "/":
            case "^":
                mezo1=mezo1_;
                mezo2=mezo2_;
                operandus=op_;
                break;
            default:
                throw new UnknownOperatorException();
        }

    }
    public boolean isOne()
    {
        if(mezo1.getClass()==Identity.class && mezo2.getClass()==Identity.class && !operandus.equals("^"))
        return true;
        else if(mezo1.getClass()==Expression.class && mezo2.getClass()==Expression.class)
        {
            if(mezo1.isOne() && mezo2.isOne())
                return true;
        }
        return false;
    }

    @Override
    public Differentiable diff() throws UnknownFunctionException, UnknownOperatorException {
        switch (operandus)
        {
            case "+"://(f+g)'=f'+g'
                return new Expression(mezo1.diff(),mezo2.diff(),"+");
            case "-": //(f-g)'=f'-g'
                return new Expression(mezo1.diff(),mezo2.diff(),"-");
            case "*"://(f·g)′=f′·g+f·g′
                return new Expression(
                        new Expression(mezo1.diff(),mezo2,"*"),
                        new Expression(mezo1,mezo2.diff(),"*"),"+");
            case "/"://  (f/g)'=(f'*g-f*g')/g^2 
                return new Expression(
                        new Expression(
                        new Expression(mezo1.diff(),mezo2,"*"),
                        new Expression(mezo1,mezo2.diff(),"*"),"-"),
                        new Expression(mezo2,new Constant(2),"^"),"/");
            case "^": //(f^g)'=f^g(g'*ln(f)+g/f*f')
                return new Expression(
                        new Expression(mezo1   //f^g
                        ,mezo2,
                        "^"),
                new Expression( //(g'*ln(f)+g/f*f')
                           new Expression(mezo2.diff(),new Function("ln",mezo1),"*")         //  g'*ln(f)
                        , new Expression(
                        new Expression(mezo2,mezo1,"/"),mezo1.diff(),"*") //g/f*f'
                        , "+")
                ,"*");
               // return new Expression(mezo2,new Expression(mezo1,new Expression(mezo2,new Constant(1),"-"),"^"),"*");
            default:
                throw new UnknownOperatorException("'"+operandus+"' ezt nem ismerem");
        }
    }
    @Override
    public String toString()
    {
        StringBuilder str=new StringBuilder();
        switch (operandus)
        {
            case "+":
            case "-":
                if(mezo1.isZero())
                {
                    if(mezo2.isZero())
                    {
                        return "";

                    }else
                        return mezo2.toString();
                }
                else
                {
                    if(mezo2.isZero())
                    {
                        return mezo1.toString();

                    }else
                        return mezo1.toString()+operandus+mezo2.toString();
                }

            case "^":
            case "*":
                if(mezo1.isOne()&&mezo2.isOne())
                    return "1.0";
                if(mezo1.isZero()||mezo2.isZero())
                    return "0.0";

                if((mezo1).isOne())
                {}  // str.append(mezo1.toString());
                else if(mezo1.getClass()==Identity.class)
                    str.append(mezo1.toString());
                else if(mezo1.getClass()==Expression.class) {
                    if(((mezo1)).isOne())
                    {}else
                        str.append("(" + mezo1.toString() + ")");
                }
                else str.append(mezo1.toString());
                if(mezo2.getClass()==Constant.class && (mezo2).isOne())
                {

                }
                else if(mezo2.getClass()==Identity.class)
                {
                    if(str.length()>0)
                        str.append(operandus+mezo2.toString());
                    else
                        str.append(mezo2.toString());
                }
                else if(mezo2.getClass()==Expression.class)
                {
                    if(((mezo2)).isOne())
                    {}else {
                        //str.append("(" + mezo1.toString() + ")");
                        if (str.length() > 0)
                            str.append(operandus + "(" + mezo2.toString() + ")");
                        else
                            str.append(mezo2.toString());//itt volt
                    }
                }
                else {
                    if(str.length()>0)
                        str.append(operandus+mezo2.toString());
                    else
                        str.append(mezo2.toString());
                }
                return str.toString();

            case "/":
                if(mezo1.isOne()&&mezo2.isOne())
                    return "1.0";
                if(mezo1.isZero()||mezo2.isZero())
                    return "0.0";

                if((mezo1).isOne())
                {}  // str.append(mezo1.toString());
                else if(mezo1.getClass()==Identity.class)
                    str.append(mezo1.toString());
                else if(mezo1.getClass()==Expression.class) {
                    if(((mezo1)).isOne())
                    {}else
                        str.append("(" + mezo1.toString() + ")");
                }
                else str.append(mezo1.toString());
                if(mezo2.getClass()==Constant.class && (mezo2).isOne())
                {

                }
                else if(mezo2.getClass()==Identity.class)
                {
                    if(str.length()>0)
                        str.append(operandus+mezo2.toString());
                    else
                        str.append(mezo2.toString());
                }
                else if(mezo2.getClass()==Expression.class)
                {
                    if(((mezo2)).isOne())
                    {}else {
                        //str.append("(" + mezo1.toString() + ")");
                        if (str.length() > 0)
                            str.append(operandus + "(" + mezo2.toString() + ")");
                        else
                            str.append(mezo2.toString());//itt volt
                    }
                }
                else {
                    if(str.length()>0)
                        str.append(operandus+mezo2.toString());
                    else
                        str.append(mezo2.toString());
                }
                return str.toString();
            default:
                return "(baj van)";

        }
    }

    @Override
    public boolean isZero() {
        if(mezo1.isZero() && mezo2.isZero())
            return true;
        return false;
    }
}
