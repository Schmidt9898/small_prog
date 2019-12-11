package PlayersLogic;

import javafx.application.Platform;
import javafx.scene.layout.Pane;

import javax.xml.ws.Action;
import java.io.*;
import java.net.Socket;
import java.util.LinkedList;

public class TcpClient extends Thread {

    Socket socket=null;
    LinkedList<ActionMSG> Actionsin=new LinkedList<>();
    LinkedList<ActionMSG> Actionsout=new LinkedList<>();

    String addres="localhost";
    int port=0;
    String name="default";
    int id=0;
    Pane pane;


    public TcpClient(String cim, int port, Pane pane, String name)
    {
this.addres=cim;
this.port=port;
this.pane=pane;
this.name=name;
    }
    public InputStreamReader getInputStream() throws IOException {
        return new InputStreamReader(socket.getInputStream());
    }

    public void manageinput()
    {
        ActionMSG temp=null;
        synchronized (Monitor)
        {
            int l=0;

            if((l=Actionsin.size())>0)
            {

                    temp= getActionin();

                    switch (temp.type)
                    {
                        case MOVE_TO:
                            temp="MOVE_TO,"+sender_name+","+sender_id+","

                                    +x+","
                                    +y+","
                            ;
                            ActionMSG finalTemp = temp;
                            Platform.runLater(new Runnable() {@Override public void run() {
                                for(int i=0;i<pane.getChildren().size();i++)
                                {
                                if(finalTemp.sender_id==pane.getChildren().get(i).getId())
                                {
                                    pane.getChildren().get(i).setTranslateX(finalTemp.x);
                                    pane.getChildren().get(i).setTranslateY(finalTemp.y);
                                }


                                }
                            }});



                            break;

                        case ACTION:
                            temp="ACTION,"+sender_name+","+sender_id+","
                                    +msg;


                            break;
                        case SYSTEM:
                            temp="SYSTEM,"+sender_name+","+sender_id+","
                                    +msg;

                            break;
                        case PING:
                            temp="PING,"+sender_name+","+sender_id+",";

                            break;
                        case ADD:
                            temp="ACTION,"+sender_name+","+sender_id+","

                                    +x+","
                                    +y+","
                                    +h+","
                                    +w+",";
                            break;
                    }







            }else {
                try {
                    Monitor.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }


        }
    }


    public void addActionIn(ActionMSG temp)
    {
        synchronized (Monitor)
        {
            Actionsin.add(temp);
            Monitor.notifyAll();
        }
    }

    public void addActionOut(ActionMSG temp) {
        synchronized (Monitor2) {
            Actionsout.add(temp);
        }
        addActionIn(temp);
    }

    public ActionMSG getActionin()
    {
        synchronized (Monitor)
        {
            return Actionsin.removeFirst();
        }
    }
    public ActionMSG getActionout()
    {
        synchronized (Monitor2)
        {
            return Actionsout.removeFirst();
        }
    }



    @Override
    public void run() {
        try { socket = new Socket(addres,port);

            TcpClientReader reader=
            new TcpClientReader(this);
            reader.setDaemon(true);
            reader.start();//reader szál elindítása

            BufferedWriter writer=new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));

            ActionMSG temp=null;
            while(true)
            {
                temp=getActionout();
                writer.write(temp.toString());
                writer.flush();
            }
           // socket.close();

        } catch (IOException e) {

            e.printStackTrace(); }





    }


}
