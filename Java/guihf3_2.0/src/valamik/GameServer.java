package valamik;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;

public class GameServer extends Thread {
    ServerSocket serversocket;
    LinkedList<Socket> sockets=new LinkedList<>();
    LinkedList<ActionMSG> Actionsin=new LinkedList<>();
    LinkedList<ActionMSG> Actionsout=new LinkedList<>();
    LinkedList<Darab> darabok=new LinkedList<>();
    //Pane vaszon=new Pane();

    public GameServer(int port,LinkedList<ActionMSG> Actionsin_,LinkedList<ActionMSG> Actionsout_) throws IOException {
        Actionsin=Actionsin_;
        Actionsout=Actionsout_;
        serversocket=new ServerSocket(port);


        darabok.add(new Darab(-1,"fal",300,0,10,200,"#003300"));
        darabok.add(new Darab(-1,"fal",20,300,100,10,"#003300"));
        darabok.add(new Darab(-1,"fal",500,204,450,10,"#003300"));
        darabok.add(new Darab(-1,"fal",120,10,10,300,"#003300"));
        darabok.add(new Darab(-1,"fal",20,230,40,50,"#003300"));
        darabok.add(new Darab(-1,"fal",200,60,200,20,"#003300"));
        darabok.add(new Darab(-1,"fal",400,110,70,10,"#003300"));


    }

    Darab getDarab(int id)
    {
        Darab temp=null;
        synchronized (darabok) {
            for (int i = 0; i < darabok.size(); i++) {
                if ((temp = darabok.get(i)).Id == id) {
                    return temp;
                }
            }
        }
        return null;
    }
    void addDarab(Darab darab)
    {

        synchronized (darabok)
        {
            darabok.add(darab);
        }
    }

    //Darab Intercept()
    @Override
    public void run() {
       // boolean fogad=true;
int playerid=1;
        Writer writer= new Writer(Actionsout,sockets);
        //writer.start();
int szam=0;
        while(szam<2)
        {

            try {
                 Socket temp= serversocket.accept();
                 sockets.add(temp);
                 BufferedWriter IDwriter = new BufferedWriter (new OutputStreamWriter(temp.getOutputStream()));

                 IDwriter.write(ActionMSG.System("getID",playerid,"getID",0,0,0,0).toString());
                 IDwriter.flush();
                 playerid++;

                new Reader(Actionsin,
                        new BufferedReader(new InputStreamReader(temp.getInputStream()))
                ).start();




                szam++;
                //fogad=false;


            } catch (IOException e) {
            }



        }


        ActionMSG Atemp;
        for(int i=0;i<darabok.size();i++)
        {
            Atemp=ActionMSG.add(
                    darabok.get(i).x,
                    darabok.get(i).y,
                    darabok.get(i).w,
                    darabok.get(i).h,
                    darabok.get(i).Id,
                    darabok.get(i).name,
                    darabok.get(i).color
            );


            Actionsout.add(Atemp);
        }


        GameMaster gameMaster=new GameMaster(Actionsin,Actionsout,darabok);
        gameMaster.setDaemon(true);
        gameMaster.start();
        writer.start();
        try {
            writer.join();
            gameMaster.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }



    class Writer extends Thread{
        LinkedList<ActionMSG> Actionsout;
        BufferedWriter writer;
        LinkedList<Socket> sockets;

        public Writer(LinkedList<ActionMSG> Actionsout_,LinkedList<Socket> sockets_)
        {
            sockets=sockets_;
            Actionsout=Actionsout_;
           // writer=writer_;
        }


        @Override
        public void run() {
            try {

                while(true) {
                    synchronized (sockets) {
                        synchronized (Actionsout) {
                            //wait();
                            for (int i = 0; i < sockets.size(); i++) {
                                writer= new BufferedWriter(new OutputStreamWriter( sockets.get(i).getOutputStream()));
                             //  writer.write(ActionMSG.add(100,100,20,20,13,"asdasd").toString());
                                for(int j=0;j<Actionsout.size();j++)
                                {
                                    writer.write(Actionsout.get(j).toString());
                                   // System.out.println(Actionsout.get(j).toString());
                                }
                                writer.flush();

                            }
                            Actionsout.clear();
                        }
                    }
                }
            }catch (Exception e){
                System.out.println("server író biba");
            }

        }
    }
    class Reader extends  Thread{
        LinkedList<ActionMSG> Actionsin;
        BufferedReader reader;


        public Reader(LinkedList<ActionMSG> Actionsin_,BufferedReader reader_)
        {
            Actionsin=Actionsin_;
            reader=reader_;
        }


        @Override
        public void run() {
            ActionMSG temp;
            try {
                while (true)
                {
                    while ((temp = ActionMSG.fromline(reader.readLine()))!=null)
                    {
                       /* if(temp.type==Msg_type.SYSTEM && temp.msg=="GETID")
                        {

                        }*/
                        synchronized (Actionsin)
                        {
                            Actionsin.add(temp);
                            Actionsin.notifyAll();
                        }
                    }

                }
            }catch (Exception e)
            {
                System.out.println("server olvas hiba");
                this.toString();
            }
        }
    }
    class GameMaster extends Thread {
        LinkedList<ActionMSG> Actionsin;
        LinkedList<ActionMSG> Actionsout;
        LinkedList<Darab> darabok=new LinkedList<>();
        public GameMaster(LinkedList<ActionMSG> Actionsin_, LinkedList<ActionMSG> Actionsout_,    LinkedList<Darab> darabok_) {
            Actionsin = Actionsin_;
            Actionsout = Actionsout_;
            darabok=darabok_;

        }

        @Override
        public void run() {
            try {
                while (true) {
                    ActionMSG temp = null;
                    synchronized (Actionsin) {
                        if (Actionsin.size() == 0)
                            Actionsin.wait();
                        else
                        {
                         temp=Actionsin.removeFirst();




                        }
                    }
                    if(temp!=null)
                    {
                                //do things
                        switch (temp.type)
                        {
                            case ADD:
                                       temp.x=(int )(Math.random() * 400 +100);
                                       temp.y=(int )(Math.random() * 200 +100);
                                Darab ujdarab=new Darab(temp.sender_id,temp.sender_name,
                                        temp.x,
                                        temp.y,
                                        temp.w,
                                        temp.h,
                                        temp.msg);
                                addDarab(ujdarab);
                                synchronized (Actionsout)
                                {
                                    Actionsout.add(temp);
                                    Actionsout.notifyAll();
                                }
                                break;
                            case MOVE_TO:
                                int     newx=getDarab(temp.sender_id).x,
                                        newy=getDarab(temp.sender_id).y;


                                getDarab(temp.sender_id).x+=temp.x;
                                getDarab(temp.sender_id).y+=temp.y;

                                if(collision(temp.sender_id)==-1)
                                {

                                    getDarab(temp.sender_id).x=newx;
                                    getDarab(temp.sender_id).y=newy;
                                    break;
                                }

                                synchronized (Actionsout)
                                {
                                    Actionsout.add(temp);
                                    Actionsout.notifyAll();
                                }
                                break;
                        }

                    }

                }
            }catch (Exception e){
                System.out.println("Gamemaster hiba");
            }
        }
    }



    int collision(int id)
    {
        Darab A = getDarab(id);
        Darab B;



for(int i=0;i<darabok.size();i++)
{
    B=darabok.get(i);
    if(A==B)
        continue;

    if(     A.x>=B.x && A.x<=(B.x+B.w) &&
        A.y>=B.y && A.y<=(B.y+B.h))
{
    return B.Id;
}
    if(     (A.x+A.w)>=B.x && (A.x+A.w)<=(B.x+B.w) &&
            A.y>=B.y && A.y<=(B.y+B.h))
    {
        return B.Id;
    }


    if(     A.x>=B.x && A.x<=(B.x+B.w) &&
            (A.y+A.h)>=B.y && (A.y+A.h)<=(B.y+B.h))
    {
        return B.Id;
    }

    if(     (A.x+A.w)>=B.x && (A.x+A.w)<=(B.x+B.w) &&
            (A.y+A.h)>=B.y && (A.y+A.h)<=(B.y+B.h))
    {
        return B.Id;
    }


}


        return -2;
    }

}

