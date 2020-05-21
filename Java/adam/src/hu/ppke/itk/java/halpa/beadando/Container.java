package hu.ppke.itk.java.halpa.beadando;

import java.util.ArrayList;
import java.util.List;

public class Container {

    List<String> lista = new ArrayList<String>();

    public synchronized String Getstr()
    {

        while (lista.size()<=0) {
            try {
                this.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
            return lista.remove(0);
    }
    public synchronized void Addstr(String s)
    {
        lista.add(s);
        this.notifyAll();
    }


}
