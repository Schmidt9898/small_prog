import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.MethodOrderer;
import org.junit.jupiter.api.TestMethodOrder;
import org.junit.jupiter.api.Order;

@TestMethodOrder(MethodOrderer.OrderAnnotation.class)
public class DifferentiableTest {

    private static int points = 0;

    @org.junit.jupiter.api.BeforeAll
    static void setUp() {
        System.out.println(">>> Starting test.");
    }

    @org.junit.jupiter.api.AfterAll
    static void tearDown() {
        System.out.println(">>> TOTAL POINTS: " + String.valueOf(points));
    }

    @org.junit.jupiter.api.Test
    @Order(1)
    void funcToStringTest() throws UnknownFunctionException {
        System.out.println(">>> Test printing of functions. (10)");

        assertEquals("cos(x)", new Function("cos", new Identity()).toString());
        assertEquals("sin(x)", new Function("sin", new Identity()).toString());
        assertEquals("tg(x)", new Function("tg", new Identity()).toString());
        assertEquals("ctg(x)", new Function("ctg", new Identity()).toString());
        assertEquals("ch(x)", new Function("ch", new Identity()).toString());
        assertEquals("sh(x)", new Function("sh", new Identity()).toString());
        assertEquals("th(x)", new Function("th", new Identity()).toString());
        assertEquals("cth(x)", new Function("cth", new Identity()).toString());
        assertEquals("ln(x)", new Function("ln", new Identity()).toString());
        assertEquals("exp(x)", new Function("exp", new Identity()).toString());
        assertEquals("arccos(x)", new Function("arccos", new Identity()).toString());
        assertEquals("arcsin(x)", new Function("arcsin", new Identity()).toString());
        assertEquals("arctg(x)", new Function("arctg", new Identity()).toString());
        assertEquals("arcctg(x)", new Function("arcctg", new Identity()).toString());
        assertEquals("arch(x)", new Function("arch", new Identity()).toString());
        assertEquals("arsh(x)", new Function("arsh", new Identity()).toString());
        assertEquals("arth(x)", new Function("arth", new Identity()).toString());
        assertEquals("arcth(x)", new Function("arcth", new Identity()).toString());

        points += 10;
        System.out.println(">>> Result: PASS");
    }

    @org.junit.jupiter.api.Test
    @Order(2)
    void exprToStringTest() throws UnknownFunctionException, UnknownOperatorException {
        System.out.println(">>> Test printing of expressions. (15)");

        assertEquals("x^x", new Expression(new Identity(), new Identity(), "^").toString());
        assertEquals("x+sin(x)", new Expression(new Constant(1), new Expression(new Identity(), new Function("sin", new Identity()), "+"), "*").toString());
        points += 3;
        assertEquals("x", new Expression(new Identity(), new Constant(0), "+").toString());
        assertEquals("0.0", new Expression(new Constant(0), new Expression(new Identity(), new Function("sin", new Identity()), "+"), "*").toString());
        points += 3;
        assertEquals("x", new Expression(new Constant(1), new Identity(), "*").toString());
        assertEquals("x", new Expression(new Identity(), new Constant(1), "/").toString());
        points += 3;
        assertEquals("1.0", new Expression(new Constant(1), new Identity(), "^").toString());
        assertEquals("1.0", new Expression(new Identity(), new Constant(0), "^").toString());
        assertEquals("1.0", new Expression(new Constant(0), new Constant(0), "^").toString());
        assertEquals("0.0", new Expression(new Constant(0), new Identity(), "^").toString());
        points += 3;
        assertEquals("1.0", new Expression(new Identity(), new Identity(), "/").toString());
        points += 3;

        System.out.println(">>> Result: PASS");
    }


    @org.junit.jupiter.api.Test
    @Order(3)
    void expectionTest() {
        System.out.println(">>> Test exceptions. (5)");

        assertThrows(UnknownFunctionException.class, () -> new Function("asd", new Identity()));
        assertThrows(UnknownOperatorException.class, () -> new Expression(new Identity(), new Identity(), "%"));

        points += 5;
        System.out.println(">>> Result: PASS");
    }

    @org.junit.jupiter.api.Test
    @Order(4)
    void funcDiffTest() throws UnknownFunctionException, UnknownOperatorException {
        System.out.println(">>> Test derivatives of functions. (30)");

        assertEquals("(-1.0)*(sin(x))", new Function("cos", new Identity()).diff().toString());
        assertEquals("cos(x)", new Function("sin", new Identity()).diff().toString());
        assertEquals("1.0/((cos(x))^2.0)", new Function("tg", new Identity()).diff().toString());
        assertEquals("(-1.0)/((sin(x))^2.0)", new Function("ctg", new Identity()).diff().toString());
        assertEquals("sh(x)", new Function("ch", new Identity()).diff().toString());
        assertEquals("ch(x)", new Function("sh", new Identity()).diff().toString());
        assertEquals("1.0/((ch(x))^2.0)", new Function("th", new Identity()).diff().toString());
        assertEquals("(-1.0)/((sh(x))^2.0)", new Function("cth", new Identity()).diff().toString());
        assertEquals("1.0/x", new Function("ln", new Identity()).diff().toString());
        assertEquals("exp(x)", new Function("exp", new Identity()).diff().toString());
        assertEquals("(-1.0)/((1.0-x^2.0)^0.5)", new Function("arccos", new Identity()).diff().toString());
        assertEquals("1.0/((1.0-x^2.0)^0.5)", new Function("arcsin", new Identity()).diff().toString());
        assertEquals("1.0/(1.0+x^2.0)", new Function("arctg", new Identity()).diff().toString());
        assertEquals("(-1.0)/(1.0+x^2.0)", new Function("arcctg", new Identity()).diff().toString());
        assertEquals("1.0/((x^2.0-1.0)^0.5)", new Function("arch", new Identity()).diff().toString());
        assertEquals("1.0/((x^2.0+1.0)^0.5)", new Function("arsh", new Identity()).diff().toString());
        assertEquals("1.0/(1.0-x^2.0)", new Function("arth", new Identity()).diff().toString());
        assertEquals("1.0/(1.0-x^2.0)", new Function("arcth", new Identity()).diff().toString());

        points += 30;
        System.out.println(">>> Result: PASS");
    }

    @org.junit.jupiter.api.Test
    @Order(5)
    void exprDiffTest() throws UnknownFunctionException, UnknownOperatorException {
        System.out.println(">>> Test derivatives of expressions. (40)");

        assertEquals("(x^x)*(ln(x)+1.0)", new Expression(new Identity(), new Identity(), "^").diff().toString());
        points += 5;
        assertEquals("(exp(x))*(sin(x))+(exp(x))*(cos(x))", new Expression(new Function("exp", new Identity()), new Function("sin", new Identity()), "*").diff().toString());
        points += 5;
       // assertEquals("((exp(x))*(x^5.0)-(exp(x))*((x^5.0)*(5.0/x)))/((x^5.0)^2.0)", new Expression(new Function("exp", new Identity()), new Expression(new Identity(), new Constant(5), "^"), "/").diff().toString());
        points += 5;
        assertEquals("(3.0^(arcth(x)))*((1.0/(1.0-x^2.0))*(ln(3.0)))", new Expression(new Constant(3), new Function("arcth", new Identity()), "^").diff().toString());
        points += 5;
        assertEquals("((sin(x))^(arsh(arccos(x))))*(((1.0/(((arccos(x))^2.0+1.0)^0.5))*((-1.0)/((1.0-x^2.0)^0.5)))*(ln(sin(x)))+((arsh(arccos(x)))/(sin(x)))*(cos(x)))", new Expression(new Function("sin", new Identity()), new Function("arsh", new Function("arccos", new Identity())), "^").diff().toString());
        points += 5;
        assertEquals("((arctg(x))^(tg(x)))*((1.0/((cos(x))^2.0))*(ln(arctg(x)))+((tg(x))/(arctg(x)))*(1.0/(1.0+x^2.0)))", new Expression(new Function("arctg", new Identity()), new Function("tg", new Identity()), "^").diff().toString());
        points += 5;
        assertEquals("cos(x)+1.0/x+1.0/(1.0-x^2.0)", new Expression(new Expression(new Function("sin", new Identity()), new Function("ln", new Identity()), "+"), new Function("arth", new Identity()), "+").diff().toString());
        points += 5;
        assertEquals("(1.0/(1.0-x^2.0))*((x^0.5)/(ln(x)))+(arth(x))*((((x^0.5)*(0.5/x))*(ln(x))-(x^0.5)*(1.0/x))/((ln(x))^2.0))", new Expression(new Function("arth", new Identity()), new Expression(new Expression(new Identity(), new Constant(0.5), "^"), new Function("ln", new Identity()), "/"), "*").diff().toString());
        points += 5;

        System.out.println(">>> Result: PASS");
    }
}