import java.util.LinkedList;

public class SpaceStation implements SpaceCraft {
    private SpaceShip [] dockedShips;
    private boolean[] freeDocks;
    private int capacity;
    private int max_carrying;
    private Integer actual_mass=0;
    private Integer actual_capacity=0;
    private Object monitor=new Object();
    private SpaceShip leavingspace=null;
    Integer seatneeded=0;
    //Passanger[] passangers;
    private LinkedList<Passanger> passangers= new LinkedList<Passanger>();
    private LinkedList<Passanger> signed_passangers= new LinkedList<Passanger>();
    private OnboardComputer computer;
/*
    public int getActual_capacity()
    {
        actual_capacity=0;
        synchronized (passangers)
        {

        }
        synchronized ( signed_passangers)
        {

        }

    }
*/
    public SpaceStation(int capacity,int max_carrying,int number_of_airlocks,OnboardComputer computer)
    {
        this.capacity=capacity;
        this.max_carrying=max_carrying;
        this.computer=computer;
        this.dockedShips =new SpaceShip[number_of_airlocks];
        this.freeDocks=new boolean[number_of_airlocks];
        for(int i=0;i<number_of_airlocks;i++)
        {

            this.freeDocks[i]=true;
        }

    }

    public void passangerleaving(Passanger passanger)
    {
        synchronized(signed_passangers) {
            signed_passangers.remove(passanger);
        }
        synchronized (actual_capacity)
        {
            actual_capacity--;
        }
    }

    public void passangerariving(Passanger passanger)
    {
        synchronized(passangers) {
            passangers.add(passanger);
        }

    }

    public int getfreedock()
    {
        for(int i=0;i<freeDocks.length;i++)
        {
            if(freeDocks[i])
            return i;
        }

        return -1;
    }
    public void freeDockbyindex(int idx,SpaceShip ship)
    {
        freeDocks[idx] = true;
        dockedShips[idx]=null;
        actual_mass-=ship.getShip_mass();


    }

    public boolean tryDock(SpaceShip ship)
    {
        int idx =getfreedock();
        if(idx!=-1 &&
                ship.getShip_mass()<=(max_carrying-actual_mass) &&
                (capacity-actual_capacity)>=ship.getNumberofmembers())
        {
            ship.setDocked(idx);
            freeDocks[idx]=false;
            dockedShips[idx]=ship;
            actual_capacity+=ship.getNumberofmembers();
            actual_mass+=ship.getShip_mass();
            //ship.setDock(dockingStations[idx]);
            Main.Log(ship.toString()+" dokkolt a "+idx+ "dokkolóra");
            return true;

        }
        return false;
    }


    public void Leaving_the_Station(Passanger passanger)
    {
        synchronized (passangers)
        {
            synchronized ( signed_passangers)
            {
                passangers.remove(passanger);
                signed_passangers.add(passanger);
                seatneeded++;
            }
        }
        while(true)
        {
            synchronized (monitor)
            {
                try {
                    monitor.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                synchronized (dockedShips) {

                    for (int i = 0; i < dockedShips.length; i++) {
                        if (dockedShips[i]!=null && dockedShips[i].freeseat()) {
                            leavingspace=dockedShips[i];
                            break;
                        }
                    }
                }

            }
            synchronized (leavingspace)
            {
                if(leavingspace!=null && leavingspace.freeseat())
                {
                    passangerleaving(passanger);
                    leavingspace.getin(passanger);
                    break;

                }
            }

        }





        /*
        while(true) {
            int shipid = -1;
            synchronized (dockedShips) {

                for (int i = 0; i < dockedShips.length; i++) {
                    if (dockedShips[i]!=null && dockedShips[i].freeseat()) {
                    shipid=i;
                    break;
                    }
                }
            }
            if(shipid!=-1)
            {
                synchronized (dockedShips[shipid])
                {
                    if(dockedShips[shipid].getin(passanger))
                    {
                        passangerleaving(passanger);
                       // Main.Log(passanger+" elhagyta az állomást és felment a"+dockedShips[shipid]);
                        break;
                    }else
                    {
                        synchronized (dockedShips)
                        {
                            try {
                                dockedShips.wait();
                            } catch (InterruptedException e) {
                                e.printStackTrace();
                            }
                        }
                    }
                }
            }

        }*/
        //wait for ship

    }
    public void thereisfreeplace()
    {
        synchronized (monitor){
        monitor.notifyAll();}
    }
    public boolean needFreeship()
    {
        if(seatneeded>50) {
            seatneeded-=50;
            return true;
        }
        else
            return false;

    }
    public void candepart()
    {
        if(actual_capacity<=200) {
            for (int i = 0; i < dockedShips.length; i++) {
                if(dockedShips[i]!=null && dockedShips[i].forceleave())
                {

                    break;
                }

            }
        }


    }
    @Override
    public String toString()
    {
     return "ISS állapota: Tömeg: "+actual_mass+
             ", lélekszám: "+actual_capacity+
             ", haza akar menni: "+signed_passangers.size()+" fő ";
    }




}
