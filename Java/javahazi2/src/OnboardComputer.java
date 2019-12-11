import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import java.util.LinkedList;

public class OnboardComputer extends Thread {
    SpaceStation space_station;
    LinkedList<SpaceShip> shipswaits= new LinkedList<>();

    Object monitor=new Object();
    public OnboardComputer(SpaceStation station){
     this.space_station=station;
    }
    public OnboardComputer(){

    }
    public void setStation(SpaceStation station)
    {
        this.space_station=station;
    }

    @Override
    public String toString() {
        return "Én a számítógép vagyok.";
    }

    @Override
    public void run() {
        Thread waitingwatcher=new Thread(new Runnable() {
            @Override
            public void run() {
                while(true)
                {
                    synchronized (monitor)
                    {
                        if(shipswaits.size()>10)
                        {
                            Main.StopCape_canaveral();
                            Main.Log("-------felküldés Tiltása-----");
                        }
                        else if(shipswaits.size()<5){
                            Main.StartCape_canaveral();
                            Main.Log("-------felküldés Engedélyezése-----");
                        }

                        if(Main.optimalization && shipswaits.size()>0)
                        {
                            space_station.candepart();
                        }

                        try {
                            monitor.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }
        });
        waitingwatcher.setDaemon(true);
        waitingwatcher.start();

        while(true)
        {
            if(space_station.needFreeship())
                Main.sendfreeship(this);
            try {
                Thread.sleep(5000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            Main.Log( space_station.toString()+"["+shipswaits.size()+"] hajó várakozik.");
        }

    }


    public void thereisfreeplace()
    {
        space_station.thereisfreeplace();
    }


    public void dockinginitiate(SpaceShip spaceShip)
    {
        synchronized (space_station)
        {
            while(!space_station.tryDock(spaceShip))
            {
                try {
                    synchronized (monitor)
                    {
                        if(!shipswaits.contains(spaceShip))
                        {
                            shipswaits.add(spaceShip);
                            monitor.notifyAll();
                        }

                    }
                    space_station.wait();
                } catch (Exception e) {
                    Main.Log("docking initiate wait exception");
                    e.printStackTrace();
                }

            }
            synchronized (monitor)
            {
                shipswaits.remove(spaceShip);
                monitor.notifyAll();
            }
            //Main.Log(spaceShip.toString()+" dokkolt.");

        }
    }
    public void Enter_the_Station(Passanger passanger,SpaceShip ship)
    {
        ship.passangerleaving(passanger);
        space_station.passangerariving(passanger);
        passanger.setMyspacecraft(space_station);
        Main.Log(passanger.toString()+" felment az állomásra");


    }

    public void leaveStation(SpaceShip ship,int idx)
    {

        synchronized (space_station)
        {
            space_station.freeDockbyindex(idx,ship);

            space_station.notifyAll();

        }
         Main.Log(ship.toString()+" elhagyta az állomás "+idx+" dokját");
    }


}
