package com.company;

import java.util.ArrayList;
import java.util.List;

public class LocalPlayer implements PlayerCommunicator, Runnable {

    UserInterface ui = null;
    LocalGame localgame = null;
    int id = -1;
    String name = "none";//TODO
    Boolean isrun = true;
    List<String> inBuffer = new ArrayList<>();


    public LocalPlayer(UserInterface ui_) {
        ui = ui_;
        localgame = new LocalGame();//TODO paraméterezés

        localgame.localplayer = this;
        new Thread(localgame).start();
        localgame.handle("4");

    }


    @Override
    public void run() {

        while (true) {
            synchronized (isrun) {
                if (!isrun) break;
            }

            synchronized (inBuffer) {
                if (inBuffer.size() == 0) {
                    try {
                        inBuffer.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                } else {
                    while (inBuffer.size() > 0) {
                        String msg = inBuffer.remove(0);
                        ui.updateUI(msg);
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
                        }
                    }
                }

            }


        }


    }

    @Override
    public Action GetStep() {

        return ui.GetAction();


    }
    /*0 new player
      1 dead player
      2 player lépett
      3 pls frissítsd a képet
        */

    @Override
    public void UpdateState(String msg) {
        synchronized (inBuffer)
        {
            inBuffer.add(msg);
            inBuffer.notifyAll();
        }
    }


}