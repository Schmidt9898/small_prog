package valamik;

import javafx.animation.AnimationTimer;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;


import java.io.*;
import java.net.Socket;
import java.util.LinkedList;

public class TcpClient extends Thread {

    Socket socket=null;
    LinkedList<ActionMSG> Actionsin=new LinkedList<>();
    LinkedList<ActionMSG> Actionsout=new LinkedList<>();
  //  Rectangle node=new Rectangle();

    String addres="localhost";
    int port=0;
    String name="default";
    int id=0;
    Pane pane;

    int x=10,y=10,w=10,h=10;
    int r,g,b;
    int X=0,Y=0;


    public TcpClient(String cim, int port, Scene scene, String name)
    {
this.addres=cim;
this.port=port;
this.pane= (Pane) scene.getRoot();
this.name=name;
//pane.getChildren().add(node);
        r=(int )(Math.random() * 156 + 100);
        g=(int )(Math.random() * 156 + 100);
        b=(int )(Math.random() * 156 + 100);


        AnimationTimer timer = new AnimationTimer() {
            @Override
            public void handle(long now) {
                update();
            }
        };




        scene.setOnKeyPressed(e->
                {
                    switch (e.getCode())
                    {
                        case W:
                            Y=-5;
                            break;
                        case S:
                            Y=5;
                            break;
                        case A:
                            X=-5;
                            break;
                        case D:
                            X=5;
                            break;
                    }
                }

    );
        scene.setOnKeyReleased(e->{
            switch (e.getCode())
            {
                case W:
                    Y=0;
                    break;
                case S:
                    Y=0;
                    break;
                case A:
                    X=0;
                    break;
                case D:
                    X=0;
                    break;
            }


        });


        timer.start();

    }
    private void update()
    {

        if(Y!=0 || X!=0)
        {
            ActionMSG temp=ActionMSG.move_to(0,0,id,name);
            temp.x+=X;
            temp.y+=Y;

            addActionOut(temp);

        }


    }


    public void addActionIn(ActionMSG temp)
    {
        synchronized (Actionsin)
        {
            Actionsin.add(temp);
            Actionsin.notifyAll();
        }
    }

    public void addActionOut(ActionMSG temp) {
        synchronized (Actionsout) {
            Actionsout.add(temp);
        }
        addActionIn(temp);
    }

    public ActionMSG getActionin()
    {
        synchronized (Actionsout)
        {
            return Actionsin.removeFirst();
        }
    }
    public ActionMSG getActionout()
    {
        synchronized (Actionsout)
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
                synchronized (Actionsout) {
                    //wait();
                    //for (int i = 0; i < sockets.size(); i++) {
                       // writer= new BufferedWriter(new OutputStreamWriter( sockets.get(i).getOutputStream()));
                        for(int j=0;j<Actionsout.size();j++)
                        {
                            writer.write(Actionsout.get(j).toString());

                        }
                        writer.flush();

                   // }
                    Actionsout.clear();
                }

                //writer.write(temp.toString());
                writer.flush();
            }
           // socket.close();

        } catch (IOException e) {

            e.printStackTrace(); }

    }


    /**
     * ////////////////////////////////////////////////////
     */
    class TcpClientReader extends Thread {
        TcpClient player;

        public TcpClientReader(TcpClient player) {
            this.player = player;
        }


        @Override
        public void run() {
            try {
                BufferedReader reader = new BufferedReader(player.getInputStream());
                String line = null;

                while (true) {
                   // reader.read();
                    line = reader.readLine();
                    if((line) != null) {
                      ActionMSG temp = ActionMSG.fromline(line);
                        if (temp != null) {
                            //int l = 0;
                           // if ((l = Actionsin.size()) > 0) {
                               // temp = getActionin();
                                switch (temp.type) {
                                    case MOVE_TO:
                                        ActionMSG finalTemp = temp;
                                       // System.out.println(temp.toString());
                                        Platform.runLater(new Runnable() {
                                            @Override
                                            public void run() {
                                                for (int i = 0; i < pane.getChildren().size(); i++) {
                                                    if (pane.getChildren().get(i).getId().equals(finalTemp.sender_id+"")) {
                                                       finalTemp.x+=pane.getChildren().get(i).getTranslateX();
                                                       finalTemp.y+=pane.getChildren().get(i).getTranslateY();
                                                        pane.getChildren().get(i).setTranslateX(finalTemp.x);
                                                        pane.getChildren().get(i).setTranslateY(finalTemp.y);
                                                        break;
                                                    }
                                                }
                                            }
                                        });
                                        break;

                                    case ACTION:
                                        // temp = "ACTION," + sender_name + "," + sender_id + ","
                                        //        + msg;


                                        break;
                                    case SYSTEM:
                                        //   temp = "SYSTEM," + sender_name + "," + sender_id + ","
                                        //          + msg;

                                        if(temp.sender_name.equals("getID"))
                                        {
                                        id=temp.sender_id;
                                        }
                                        addActionOut(ActionMSG.add(x,y,w,h,id,name,"#8800ff"));



                                        break;
                                    case PING:
                                        //  temp = "PING," + sender_name + "," + sender_id + ",";

                                        break;
                                    case ADD:

                                        finalTemp = temp;

                                        Platform.runLater(new Runnable() {
                                            @Override
                                            public void run() {
                                                Rectangle rect = new Rectangle(finalTemp.x, finalTemp.y, finalTemp.w, finalTemp.h);
                                                rect.setFill(Color.valueOf(finalTemp.msg));
                                                rect.setId(finalTemp.sender_id + "");

                                                pane.getChildren().add(rect);
                                            }
                                        });


                                        break;
                                }


                            } else {

                            }


                        }


                    }
              //  }
             //   System.out.println("nem leszjó ez az olvasó");


            } catch (IOException e) {
                System.out.println("olvasó hiba");
                e.printStackTrace();
            }
        }
    }

    private Reader getInputStream() throws IOException {
        return new InputStreamReader(socket.getInputStream());
    }

    class imputmanagger extends Thread
    {
        Pane pane;



    }

}
