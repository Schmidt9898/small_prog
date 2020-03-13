package com.company;

import org.w3c.dom.ls.LSInput;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Main {

    public static void main(String[] args) {

        try {

            ServerSocket szerver = new ServerSocket(12345);
            Socket client = szerver.accept();
            System.out.println("jött valaki");

            Thread olvaso = new Thread(()->{
                try {
                    while(client.isConnected()) {
                        //System.out.println("waiting");
                        BufferedReader reader = new BufferedReader(new InputStreamReader(client.getInputStream()));
                        String s = reader.readLine();
                        System.out.println(s);//blokkol
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                    System.out.println("hiba az olvaséssal");

                }
                System.out.println("bezárt");

            });
            olvaso.start();
            BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));
            String str = "";
            while (!str.contains( "exit")) {

                str=cin.readLine();
                System.out.println(str);
                writer.write(str+"\n");
                writer.flush();
            }
            client.close();
            szerver.close();

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
