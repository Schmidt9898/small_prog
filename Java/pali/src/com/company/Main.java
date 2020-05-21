package com.company;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException, InterruptedException {
        System.out.println("Start.");

       /* PlayerCommunicator com = new LocalPlayer();
        UserInterface ui = new GameTextui();
        MessageHandler mh = new LocalGame();

        GameLogic gamelogic = new GameLogic(10);*/
/*

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Add meg a méretet?pls");
        int s = Integer.parseInt(reader.readLine());
        Game g = new Game(s);
        int myid = g.New_Player_init("laci");
        //System.out.println("Ellenfelek száma?");
        //s = Integer.parseInt(reader.readLine());
        //for()
        String str = "";
        System.out.println("add meg a lépést");
        while (!(str = reader.readLine()).contains( "esc"))
        {
            String resoult = "";
            if(str.equals("0"))
            {
                resoult =g.Update(myid,Action.TURN_LEFT);
            }else if(str.equals("1")){
                resoult =g.Update(myid,Action.FORWARD);
            }else if(str.equals("2")){
                resoult =g.Update(myid,Action.TURN_RIGHT);
            }

            //TODO AI

            g.PrintGrid();

            if(resoult.equals("dead"))
            {
                System.out.println("You are a loser hahaha");
                break;
            }








            System.out.println("add meg a lépést");
        }
*/

        UserInterface ui = new GameTextui();
        ((GameTextui)ui).init_grid();
        Thread one =  new Thread((GameTextui)ui);
        PlayerCommunicator pcom= new LocalPlayer(ui);
        Thread two = new Thread((LocalPlayer)pcom);

        one.start();
        two.start();

        one.join();
        two.join();






        System.out.println("End!");
    }
}
