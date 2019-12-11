package valamik;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.layout.Pane;

import java.io.IOException;
import java.net.Socket;
import java.util.LinkedList;

/**
 * Ez Indídja a szervert.
 */
public class Game  {


    public static void main(String[] args)
    {
        //Pane asztal;
        // Socket socket=null;
        LinkedList<ActionMSG> Actionsin=new LinkedList<>();
        LinkedList<ActionMSG> Actionsout=new LinkedList<>();
       // LinkedList<Darab> darabok=new LinkedList<>();
        //Object Monitor=new Object();
        //Object Monitor2=new Object();
        String addres="localhost";
        int port=19982;
        String name="game";
        int id=-1;

        //teszt
      //  for(int i=0;i<100;i++) {
        // Actionsout.add(ActionMSG.add(100, 100, 20, 20, 13, "asdasd"));
       // }







        try {
            GameServer gameServer=new GameServer(port,Actionsin,Actionsout);
            gameServer.start();

        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("nem jó a main");
        }
    }



}
