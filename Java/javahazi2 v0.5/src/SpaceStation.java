import java.util.LinkedList;

public class SpaceStation implements SpaceCraft {
    private DockingStation[] dockingStations;
    private boolean[] freeDocks;
    private int capacity;
    private int max_carrying;
    private int actual_mass=0;
    //Passanger[] passangers;
    private LinkedList<Passanger> passangers= new LinkedList<Passanger>();
    private LinkedList<Passanger> signed_passangers= new LinkedList<Passanger>();
    private OnboardComputer computer;

    public SpaceStation(int capacity,int max_carrying,int number_of_airlocks,OnboardComputer computer)
    {
        this.capacity=capacity;
        this.max_carrying=max_carrying;
        this.computer=computer;
        this.dockingStations =new DockingStation[number_of_airlocks];
        this.freeDocks=new boolean[number_of_airlocks];
        for(int i=0;i<number_of_airlocks;i++)
        {
            this.dockingStations[i]=new DockingStation("D"+i);
            this.freeDocks[i]=true;
        }

    }

    public void passangerleaving(Passanger passanger)
    {
        synchronized(passangers) {
            passangers.remove(passanger);
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
    public void freeDockbyindex(int idx)
    {
        synchronized (freeDocks) {
            freeDocks[idx] = true;
        }
    }

    public boolean tryDock(SpaceShip ship)
    {
        int idx =getfreedock();
        if(idx!=-1 &&
                ship.getShip_mass()<=(max_carrying-actual_mass) &&
                (capacity-passangers.size())>=ship.getNumberofmembers())
        {
            ship.setDocked(idx);
            freeDocks[idx]=false;
            ship.setDock(dockingStations[idx]);
            return true;

        }
        return false;
    }

    public void Leaving_the_Station(Passanger passanger)
    {

    }

}
