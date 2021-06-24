package com.company;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class client {
    public static void main(String[] args) {
        try {


            Socket client = new Socket("localhost",12345);
            System.out.println("connected");

            Thread olvaso = new Thread(() -> {
                try {
                    while (true) {
                        //System.out.println("waiting");
                        BufferedReader reader = new BufferedReader(new InputStreamReader(client.getInputStream()));
                        String s = reader.readLine();
                        System.out.println(s);
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                    System.out.println("hiba az olvaséssal");

                }

            });
            olvaso.start();
            BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
            String str = "";
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));
            while (!str.contains( "exit")) {

                str=cin.readLine();
                System.out.println(str);
                writer.write(str+"\n");
                writer.flush();
            }
            client.close();
            //szerver.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
