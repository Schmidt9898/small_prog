package PlayersLogic;

public class Clientgui extends Thread {
    TcpClient player;
    public Clientgui(TcpClient player)
    {
        this.player=player;
    }

    @Override
    public void run() {
        try {


            while (true)
            {

                player.manageinput();


            }



        }catch (Exception e){
            System.out.println("gui vezérlés hiba");
        }



    }
}
