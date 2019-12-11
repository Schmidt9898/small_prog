package PlayersLogic;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class TcpClientReader extends Thread {
    TcpClient player;

    public TcpClientReader(TcpClient player) {
        this.player = player;
    }


    @Override
    public void run() {
        try {
            BufferedReader reader = new BufferedReader(player.getInputStream());
            String line = null;

            while ((line = reader.readLine()) != null) {
                ActionMSG temp = ActionMSG.fromline(line);
                if (temp != null)
                    player.addActionIn(temp);


            }
            System.out.println("nem leszjó ez az olvasó");


        } catch (IOException e) {
            System.out.println("olvasó hiba");
            e.printStackTrace();
        }
    }
}
