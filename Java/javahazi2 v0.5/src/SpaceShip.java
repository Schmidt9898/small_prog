import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import java.util.LinkedList;

public class SpaceShip extends Thread implements SpaceCraft {
    private int ship_id;
    private int ship_mass;

    public boolean Hasarrivals() {
        return hasarrivals;
    }

    volatile private boolean hasarrivals;
    private int ship_capacity;
    private OnboardComputer computer;
    private Integer docked=-1;
     DockingStation dock=null;
    private LinkedList<Passanger> passangers= new LinkedList<Passanger>();


    public SpaceShip(int id,int mass,int capacity,OnboardComputer computer) {
        this.ship_id = id;
        this.ship_mass = mass;
        this.ship_capacity = capacity;
        this.computer=computer;
        //this.hasarrivals=true;
        for(int i=0;i<capacity;i++)
        {
            passangers.add(new Passanger(i,this));

        }
        for(int i=0;i<capacity;i++)
        {
            passangers.get(i).setDaemon(true);
            passangers.get(i).start();

        }


    }

    public void passangerleaving(Passanger passanger)
    {
        synchronized(passangers) {
            passangers.remove(passanger);
            if (passangers.size()>0)
                passangers.notifyAll();
        }
    }

    public void passangerariving(Passanger passanger)
    {
        synchronized(passangers) {
            passangers.add(passanger);
        }
    }

    public DockingStation getDock() {
        return dock;
    }

    public void setDock(DockingStation dock) {
        this.dock = dock;
    }

    public int getNumberofmembers()
    {
        return passangers.size();//tardsd rajta a szemed
    }

    public int getShip_mass() {
        return ship_mass;
    }

    public int getShip_capacity() {
        return ship_capacity;
    }


    @Override
    public void run() {
        //eljut az állomásig és vár a dokkolásra
        computer.dockinginitiate(this);
        //siker akkor várjuk meg amíg leszálnak és felszálnak
        //computer.swapping(this);
        docked.notifyAll();

        if(passangers.size()>0)
        {
            try {
                passangers.wait();
            } catch (Exception e) {
                Main.Log("passanger size exception");
                e.printStackTrace();
            }
        }

        computer.leaveStation(this,docked);

        try {
            Thread.sleep(1000);
        } catch (Exception e) {
            Main.Log("sleep 1000 exception");
            e.printStackTrace();
        }
        //vége
    }

    public void Board_the_Station(Passanger passanger)
    {
        synchronized (docked) {
            if (docked == -1) {
                try {
                    docked.wait();
                } catch (Exception e) {
                    Main.Log("Board station docked exception");
                    e.printStackTrace();

                }

            }
        }
        synchronized (dock)
        {
            try {
                Thread.sleep(500);
            } catch (Exception e) {
                Main.Log("Board station sleep docked exception");
                e.printStackTrace();

            }
            computer.Enter_the_Station(passanger,this);
        }


    }

    public void setDocked(int idx)
    {
        this.docked=idx;
    }


}
