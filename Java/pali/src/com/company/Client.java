package com.company;

import java.io.*;
import java.net.Socket;
import java.security.PrivilegedExceptionAction;
import java.util.ArrayList;
import java.util.List;

public class Client implements Runnable{
    int id=-1;
    Socket socket = null;
    Thread Reader=null;
    //Thread Sender = null;
    static List<String> inbuffer = new ArrayList<>();

    public Client(Socket socket)
    {
        this.socket = socket;

    }

    public static String[] getIncome()
    {
        synchronized (inbuffer) {
            String[] temp = inbuffer.toArray(String[]::new);
            inbuffer.clear();
            return temp;
        }
    }

    public void send(String[] str) throws IOException {
        BufferedWriter cout;
        cout = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
        for (String s: str) {
            cout.write(s);

        }
        cout.flush();
    }

    @Override
    public void run() {

        Reader = new Thread(()->{
            BufferedReader cin=null;
            try {
                cin = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            } catch (IOException e) {
                e.printStackTrace();
            }

            while (!Thread.interrupted())
            {
                try {
               String str = cin.readLine();
               synchronized (inbuffer)
               {
                   inbuffer.add(str);
                   inbuffer.notifyAll();
               }


                } catch (IOException e) {
                    e.printStackTrace();
                }


            }


        });
        Reader.setDaemon(true);
        Reader.start();


    }
}
