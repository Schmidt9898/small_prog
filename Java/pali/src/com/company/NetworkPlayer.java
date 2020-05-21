package com.company;

import java.io.*;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class NetworkPlayer implements PlayerCommunicator, Runnable {

    UserInterface ui = null;
    public String name = "none";//TODO
    Boolean isrun = true;
    //List<String> inBuffer = new ArrayList<>();
    Object Monitor = new Object();

    int id=-1;

    String ip = "localhost";
    int port = 12345;
    Socket socket = null;
    BufferedWriter cout = null;


    public NetworkPlayer(UserInterface ui_, String ip, int port) {
        ui = ui_;
        this.ip = ip;
        this.port = port;
    }

    @Override
    public void run() {

        BufferedReader cin = null;
        try {
            socket = new Socket(ip, port);

            cout = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            cin = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        } catch (IOException e) {
            e.printStackTrace();
        }

        Thread sender = new Thread(()->{

            try {
                cout.write("4\n");
                cout.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }


            while (!Thread.interrupted())
            {
                try {

                    Action tosend = ui.GetAction();

                    String temp = id+"_";
                    switch (tosend)
                    {
                        case FORWARD:
                            temp+="FORWARD";
                            break;
                        case TURN_LEFT:
                            temp+="TURN_LEFT";
                            break;
                        case TURN_RIGHT:
                            temp+="TURN_RIGHT";
                            break;
                    }

                    cout.write(temp+"\n");
                    cout.flush();

                    Thread.sleep(100);
                } catch (InterruptedException | IOException e) {
                    e.printStackTrace();
                }
            }
        });
        sender.setDaemon(true);
        sender.start();


        while (true) {
            synchronized (isrun) {
                if (!isrun) break;
            }

            synchronized (Monitor) {
                String msg = null;
                try {
                    msg = cin.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }

                String[] tomb = msg.split("_"); // 2_nema_id_x_y
                switch (tomb[0]) {
                    case "0":
                    case "2":
                    case "3":
                        ui.updateUI(msg);

                        break;
                    case "1":
                        if (Integer.parseInt(tomb[2]) == id)
                            ui.updateUI("1");
                        break;
                    case "4":
                        id=Integer.parseInt(tomb[2]);
                        //ui.updateUI("0_"+tomb[1]+"_"+tomb[2]+"_"+tomb[3]+"_"+tomb[4]);
                        break;
                }
            }
        }
    }






@Override
public Action GetStep(){
        return null;
        }

@Override
public void UpdateState(String msg){

        }
        }
