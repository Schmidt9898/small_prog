package hu.ppke.itk.java.halpa.beadando;

import java.io.*;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Client implements Runnable {
    //Thread Sender = null;
    static List<String> inbuffer = new ArrayList<>();
    int id = -1;
    Socket socket = null;
    Thread Reader = null;

    public Client(Socket socket) {
        this.socket = socket;

    }

    public static String[] getIncome() {
        synchronized (inbuffer) {
            String[] temp = inbuffer.toArray(String[]::new);
            inbuffer.clear();
            return temp;
        }
    }

    public void send(String[] str) throws IOException {
        BufferedWriter cout;
        cout = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
        for (String s : str) {
            cout.write(s);

        }
        cout.flush();
    }
    public void send(String str) throws IOException {
        BufferedWriter cout;
        cout = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            cout.write(str);
        cout.flush();
    }

    @Override
    public void run() {

        Reader = new Thread(() -> {
            BufferedReader cin = null;
            try {
                cin = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            } catch (IOException e) {
                e.printStackTrace();
            }

            while (!Thread.interrupted()) {
                try {
                    String str = cin.readLine();
                    synchronized (inbuffer) {
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
