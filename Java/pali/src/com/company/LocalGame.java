package com.company;

public class LocalGame implements MessageHandler , Runnable {

    GameLogic gamelogic=null;
    LocalPlayer localplayer=null;
    Boolean isrun=true;


    @Override
    public void run() {
        //String msg = gamelogic.New_Player_init("none");
        //localplayer.UpdateState("0_"+msg);
        new Thread(gamelogic).start();

        while (true)
        {
            synchronized (isrun){if(!isrun)break;}

            gamelogic.updatePlayer(localplayer.id,localplayer.GetStep());
            try {
                Thread.sleep(20);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }


        }


    }

    @Override
    public void handle(String msg) {//biztos játékos küldi
        if(msg.equals("4"))
        {
             String s = gamelogic.New_Player_init("none");
             localplayer.UpdateState("4_"+s);
        }
    }

    @Override
    public void handle(Action act) {

    }

    @Override
    public void handle(String[] msg) {//biztos logic küldi

        for (String s:msg) {
            localplayer.UpdateState(s);

        }
    }

    public LocalGame()
    {
        gamelogic=new GameLogic(10,this);//TODO paraméteres

    }
}
