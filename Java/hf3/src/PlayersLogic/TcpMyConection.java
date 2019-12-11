package PlayersLogic;


import java.io.*;
import java.net.Socket;
import java.util.LinkedList;

import static sun.java2d.cmm.ColorTransform.In;

public class TcpMyConection extends Thread{
    LinkedList<ActionMSG> Actions=new LinkedList<>();
    Object Monitor=new Object();
    String addres="localhost";
    int port=0;
    public TcpMyConection(String ipaddres,int port)
    {
        this.addres=ipaddres;
        this.port=port;
    }

    public void addActoin(ActionMSG actionMSG)
    {
        synchronized (Monitor) {
            Actions.add(actionMSG);
            Monitor.notifyAll();
        }
    }

    public  LinkedList<ActionMSG> getActions()
    {
        return Actions;
    }

    @Override
    public void run() {
        Socket socket=null;
        BufferedReader reader=null;
        BufferedWriter writer=null;

        try { socket=new Socket(addres,port);
        reader=new BufferedReader(new InputStreamReader(socket.getInputStream()));
        writer=new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));

        } catch (IOException e) { e.printStackTrace(); }


            Thread readerthread = new Thread(new Runnable() {
                @Override
                public void run() {

                    try{
                        String line=null;
                    while (true)
                    {

                        while((line=reader.readLine())!=null)
                        {

                        }


                    }}catch (Exception e){
                        System.out.println("olvasó szál bezárult");
                    }


                }
            });












    }
}
