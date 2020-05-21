package hu.ppke.itk.java.halpa.beadando;

import java.io.IOException;
import java.net.ServerSocket;
import java.util.ArrayList;
import java.util.List;

public class NetworkClient implements MessageHandler, Runnable {
    GameLogic gamelogic = null;
    Boolean isrun = true;

    List<Client> clients = new ArrayList<Client>();
    ServerSocket server = null;
    Thread handeler = null;

    @Override
    public void run() {
        gamelogic = new GameLogic(10, this);//TODO Paraméterezés
        try {


            handeler = new Thread(() -> {
                try {
                    while (!Thread.interrupted()) {
                        synchronized (Client.inbuffer) {
                            if (Client.inbuffer.size() == 0) {
                                Client.inbuffer.wait();
                            } else {
                                String[] temp = Client.getIncome();
                                for (String s : temp) {
                                    if (s.equals("4")) {
                                        gamelogic.New_Player_init("a neve insert here");
                                    } else {
                                        String[] tomb = s.split("_");

                                        Action a;
                                        if (tomb[1].equals("FORWARD"))
                                            a = Action.FORWARD;
                                        else if (tomb[1].equals("TURN_RIGHT"))
                                            a = Action.TURN_RIGHT;
                                        else
                                            a = Action.TURN_LEFT;

                                        gamelogic.updatePlayer(Integer.parseInt(tomb[0]), a);
                                    }
                                }

                            }
                        }
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            });


            server = new ServerSocket(12345);
            while (!Thread.interrupted()) {
                clients.add(new Client(server.accept()));
                String pp = gamelogic.New_Player_init("dont know");
                clients.get(clients.size()-1).send("4_"+pp);
                this.handle("0_"+pp);
            }


        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    @Override
    public void handle(String msg) {
        for (Client c : clients) {
            try {
                c.send(msg);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public void handle(String[] msg) {
        for (Client c : clients) {
            try {
                c.send(msg);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public void handle(Action act) {

    }
}
