import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

public class Main {

    public static void main(String[] args) {
        System.out.println("Hello World!");

        try {
            Constant cons=new Constant(3);
            Differentiable e=new Expression(cons, new Function("arcth", new Identity()), "^");
            BufferedWriter c=new BufferedWriter(new OutputStreamWriter(System.out));
            System.out.println(e.toString());
            e.diff();
            System.out.println("asdasd");
        }catch (Exception ex){}

    }
}
