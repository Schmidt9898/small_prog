public class Main {

    public static void main(String[] args) {
        System.out.println("SpaceX szimuláció!");
        OnboardComputer Center_Computer=new OnboardComputer();
        SpaceStation ISS=new SpaceStation(250,2500,5,Center_Computer);
        Center_Computer.setStation(ISS);
        for(int i=0;i<10;i++)
        {
            SpaceShip ship=new SpaceShip(i,20,30,Center_Computer);
            ship.setDaemon(true);
            ship.start();
        }
        while(true)
        {
            try {
                Thread.sleep(10000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }
    public static void Log(String msg)
    {
        System.out.println(msg);//késöbb szinkronizálni
    }
}

