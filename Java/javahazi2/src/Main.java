import java.io.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.LinkedList;
import java.util.Random;

public class Main {
    static boolean Launch=false;

    static DateFormat df = new SimpleDateFormat("HH:mm:ss");
    static boolean optimalization=true;


    public static void main(String[] args) {


        Shipduty shipduty;
        if(optimalization)
            shipduty=Shipduty.dont_need_to_fill;
        else
            shipduty=Shipduty.dont_fill;



        System.out.println("SpaceX szimuláció!");
        OnboardComputer Center_Computer=new OnboardComputer();
        SpaceStation ISS=new SpaceStation(250,2500,5,Center_Computer);
        Center_Computer.setStation(ISS);
        Center_Computer.setDaemon(true);
        Center_Computer.start();

        int starter_id=1;

        LinkedList<String> shipnames=new LinkedList<String>();
        try {
            BufferedReader reader = new BufferedReader(new FileReader("src\\shipnames.txt"));
            String line;
            while ((line=reader.readLine())!=null)
            {
                shipnames.add(line);
            }


        } catch (Exception e) {
            e.printStackTrace();
        }

        //Random r=new Random();
        //shipnames[ (int)(Math.random() * shipnames.size())];
        String randomshipname;
        /*for(int i=0;i<;i++)
        {
            if(shipnames.size()>0)
                randomshipname=shipnames.get((int)(Math.random() * shipnames.size()));
            else
                 randomshipname="Falcon";

            SpaceShip ship=new SpaceShip(i,Center_Computer,Shipduty.dont_fill,starter_id*100,randomshipname,nevek);
            ship.setDaemon(true);
            ship.start();
            starter_id++;
        }*/
        while(true)
        {

            try {
                Thread.sleep((int)(Math.random()*5000 + 5000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            if(Launch) {
                if (shipnames.size() > 0)
                    randomshipname = shipnames.get((int) (Math.random() * shipnames.size()));
                else
                    randomshipname = "dragon";

                SpaceShip ship = new SpaceShip(starter_id, Center_Computer, shipduty, starter_id * 100, randomshipname);
                ship.setDaemon(true);
                ship.start();
                starter_id++;
            }
        }

    }
    public static void Log(String msg) {
        Calendar calobj = Calendar.getInstance();
        System.out.print(df.format(calobj.getTime()));
        System.out.println(" "+msg);//késöbb szinkronizálni
    }



        public static void StopCape_canaveral()
    {
        Launch=false;
    }
    public static void StartCape_canaveral()
    {
        Launch=true;
    }
    public static void sendfreeship(OnboardComputer computer)
    {

        SpaceShip ship = new SpaceShip(000007,(int) (Math.random() * 900+100),50,computer,Shipduty.mustfill,ShipState.fill,0,"Falcon");
        ship.setDaemon(true);
        ship.start();
        Log("Falcon üres hajó elküldve. "+ship.toString());

    }
}

