package hu.ppke.itk.java.halpa.beadando;

public class Main {

    public static void main(String[] args) throws InterruptedException {
	// write your code here
        System.out.println("Start..");
        Container C=new Container();

        Thread t1 = new Thread(new Adam(C));
        Thread t2 = new Thread(new Adam(C));
        t1.start();
        t2.start();


        //System.out.println("valami vége");

        t1.join();
        t2.join();
        //System.out.println("End...");
    }
}
