package hu.ppke.itk.java.halpa.beadando;

import java.util.Random;

public class Adam implements Runnable{
    //private String str="";
    private Container C=null;
    private static int count=1;
   // private static Object monitor=new Object();
    private int id;
    private static Random rng=new Random();

    public Adam(Container c)
    {
        C=c;
        id=count;
        count++;
    }


    private void addf()
    {
        C.Addstr("Laci");
    }
    private void printf()
    {
        System.out.println(C.Getstr());
    }



    @Override
    public void run() {
        System.out.println("thread:"+id);
        while (!Thread.interrupted())
        {
            if(id%2==0) {
                addf();
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }else {
                printf();

            }

        }
        System.out.println(id+" ...vége");



    }



}
