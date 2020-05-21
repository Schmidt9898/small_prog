package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class GameTextui implements UserInterface, Runnable {

    int[][] Grid = null;
    int size=10; // TODO paraméterezés
    public Action mynextstep=Action.FORWARD;

    Boolean isrun=true;

    @Override
    public synchronized Action GetAction() {
        return mynextstep;
    }

    @Override
    public void run() {
        System.out.println("Helló faszkalap");

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        Thread reader_thread = new Thread(()->{
           while(!Thread.interrupted())
           {
               try {
                   String str = reader.readLine().toLowerCase();
                   synchronized (mynextstep) {
                       if (str.contains("a")) {
                           mynextstep = Action.TURN_LEFT;
                       } else if (str.contains("d")) {
                           mynextstep = Action.TURN_LEFT;
                       } else {
                          // mynextstep = Action.FORWARD;
                       }
                   }
               } catch (IOException e) {
                   e.printStackTrace();
               }
           }
        });
        reader_thread.start();//TODO check



        while(true)
        {
            synchronized (isrun){if(!isrun)break;}


            //TODO találd ki
            //TODO start




        }
    }

    void printgrid()
    {
        //Print grid
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(Grid[i][j]+" ");

            }
            System.out.println("");
        }
    }
    void init_grid()
    {
        Grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                Grid[i][j] = 0;
            }
        }
    }


    @Override
    public void updateUI(String msg) {


        //System.out.println(msg);
        /*változás 0->1  , 0->2
         *halál
         * méret
         * most printelj
         */

        String[] tomb = msg.split("_");// 2_nema_id_x_y kivéve 1 esetén
        switch (tomb[0])
        {



            case "1"://meghaltam

                System.out.println("A rohadt életbe , te kemper szar");

                break;
            case "2":
            case "0":
                int recipient_id=Integer.parseInt(tomb[2]);
                int x=Integer.parseInt(tomb[3]),y=Integer.parseInt(tomb[4]);
                Grid[x][y]=recipient_id;
                break;
            case "3":
                printgrid();
                break;
        }




    }
}
