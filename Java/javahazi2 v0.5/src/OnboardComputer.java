import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import java.util.LinkedList;

public class OnboardComputer extends Thread {
    SpaceStation space_station;
    //LinkedList<SpaceShip> spaceships;

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
        throw new NotImplementedException();

    }

    public void dockinginitiate(SpaceShip spaceShip)
    {
        synchronized (space_station)
        {
            while(!space_station.tryDock(spaceShip))
            {
                try {
                    space_station.wait();
                } catch (Exception e) {
                    Main.Log("docking initiate wait exception");
                    e.printStackTrace();
                }

            }

        }
    }
    public void Enter_the_Station(Passanger passanger,SpaceShip ship)
    {
        ship.passangerleaving(passanger);
        space_station.passangerariving(passanger);
        passanger.setMyspacecraft(space_station);
        Main.Log(passanger.toString()+" áthalad az "+ship.dock.toString()+ "és felment az állomásra");


    }

    public void leaveStation(SpaceShip ship,int idx)
    {

        space_station.freeDockbyindex(idx);
        space_station.notifyAll();
        Main.Log(ship.toString()+" elhagyta az állomást");
    }


}
