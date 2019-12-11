import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import java.util.LinkedList;
import java.util.Random;

public class SpaceShip extends Thread implements SpaceCraft {
    private int ship_id;
    private String shipname="Falcon";
    private int ship_mass;
    private Shipduty shipduty;
    private ShipState shipState=ShipState.mow;
    Object monitor=new Object();
    public ShipState getShipState() {
        return shipState;
    }



    //public boolean Hasarrivals() {
      //  return hasarrivals;
    //}

    //volatile private boolean hasarrivals;
    private int ship_capacity;
    private OnboardComputer computer;
    private Integer docked=-1;
   //  DockingStation dock=null;
    private LinkedList<Passanger> passangers= new LinkedList<Passanger>();


    public SpaceShip(int id,int mass,int capacity,OnboardComputer computer,Shipduty shipduty,int id_start,String name,LinkedList<String> nevek) {
        this.ship_id = id;
        this.ship_mass = mass;
        this.ship_capacity = capacity;
        this.computer=computer;
        this.shipduty=shipduty;
        this.shipname=name;
        //this.hasarrivals=true;
        //Random r=new Random();

        String randomname="";

            for (int i = 0; i < capacity; i++) {
               if(nevek.size()>0)
                    randomname=nevek.get((int)(Math.random() * nevek.size()));
                else
                    randomname="Passanger";
                passangers.add(new Passanger(id_start + i, this,randomname));

            }
            for (int i = 0; i < capacity; i++) {
                passangers.get(i).setDaemon(true);
                passangers.get(i).start();

            }



    }
    public SpaceShip(int id,OnboardComputer computer,Shipduty shipduty,int id_start,String name) {
     //   Random r=new Random();
        this.ship_id = id;
        this.ship_mass = (int)(Math.random()*900 +100);
        this.ship_capacity = (int)(Math.random()*90 +10);
        this.computer=computer;
        this.shipduty=shipduty;
        this.shipname=name;
        //this.hasarrivals=true;




        for (int i = 0; i < this.ship_capacity; i++) {
           /* if(nevek.size()>0)
                randomname=nevek.get((int)(Math.random() * nevek.size()));
            else*/

            passangers.add(new Passanger(id_start + i, this,"Passanger"));

        }
        for (int i = 0; i < this.ship_capacity; i++) {
            passangers.get(i).setDaemon(true);
            passangers.get(i).start();

        }
    }
    public SpaceShip(int id,int mass,int capacity,OnboardComputer computer,Shipduty shipduty,ShipState shipState,int id_start,String name) {
        this.ship_id = id;
        this.ship_mass = mass;
        this.ship_capacity = capacity;
        this.computer=computer;
        this.shipduty=shipduty;
        this.shipState=shipState;
        this.shipname=name;
    }


    public void passangerleaving(Passanger passanger)
    {
        synchronized(passangers) {
            passangers.remove(passanger);
            if (passangers.size()>0)
                passangers.notifyAll();
            else
            {
                synchronized (monitor){
                    monitor.notifyAll();
                    shipState=ShipState.fill;}
            }
        }
    }

    public void passangerariving(Passanger passanger)
    {
        synchronized(passangers) {
            passangers.add(passanger);
            if(passangers.size()==ship_capacity)
            {
                synchronized (monitor)
                {
                    monitor.notifyAll();
                    shipState=ShipState.leave;

                }
            }

        }

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
        Main.Log(this.toString_more()+" elindult.");
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        computer.dockinginitiate(this);
        //siker akkor várjuk meg amíg leszálnak és felszálnak
        //computer.swapping(this);
        //synchronized (docked){
        //docked.notifyAll();}
      /* synchronized (passangers) {
            while (passangers.size() > 0) {
                try {
                    passangers.wait();
                } catch (Exception e) {
                    Main.Log("passanger size exception");
                    e.printStackTrace();
                }
            }
        }*/

        switch (shipduty)
        {
            case mustfill :
                synchronized (monitor)
                {
                    while(shipState==ShipState.fill)
                    {
                        try {
                            computer.thereisfreeplace();
                            monitor.wait();

                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    ///////////////////////
                    computer.leaveStation(this,docked);

                }
            break;

            case dont_need_to_fill:

                synchronized (monitor) {
                    while (shipState != ShipState.leave) {
                        try {
                            computer.thereisfreeplace();
                            monitor.wait();

                        } catch (Exception e) {
                            e.printStackTrace();
                        }


                }


                }
                computer.leaveStation(this,docked);
                break;
            case dont_fill:
                synchronized (monitor) {
                    while (shipState==ShipState.mow) {
                        try {
                            monitor.wait();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                computer.leaveStation(this,docked);
                }
                break;
        }
                //if(true) {//feltételre kicserélni

                //}




       // if(shipduty==Shipduty.dont_fill)
       // computer.leaveStation(this,docked);

        try {
            Thread.sleep(10000);
        } catch (Exception e) {
            Main.Log("sleep 1000 exception");
            e.printStackTrace();
        }
        Main.Log(this.toString_more()+" belépett a légkörbe. -szál vége.");
        //vége
    }

    public void Board_the_Station(Passanger passanger)
    {
        synchronized (docked) {
            while (docked == -1) {
                try {
                    //System.out.println(passanger.toString()+ "várakozik a docknál");
                    docked.wait();
                } catch (Exception e) {
                    Main.Log("Board station docked exception");
                    e.printStackTrace();

                }

            }
        }
       // System.out.println("átmenjek e? "+passanger.toString());
        synchronized (docked)
        {
            try {
               // System.out.println("átkel "+passanger.toString());
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
        synchronized (docked) {
            docked.notifyAll();
            docked = idx;

        }

    }
    public boolean freeseat()
    {
        if(shipState==ShipState.fill)
        {
            return true;
        }

        return false;
    }
    public void getin(Passanger passanger) {

        try {
            Thread.sleep(500);
            Main.Log(passanger + " átszált a " + this + " ra a ["+this.docked+"] dockon.");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        passangerariving(passanger);


    }
    public boolean forceleave()
    {
        synchronized (monitor)
        {
            if(shipState==ShipState.fill && shipduty!=Shipduty.mustfill) {
                shipState = ShipState.leave;
                monitor.notifyAll();
                return true;
            }
            else
                return false;
        }
    }

    @Override
    public String toString() {
        return shipname+ship_id+" szamú űrhajó ";
    }
    public String toString_more() {
        return shipname+ship_id+" szamú űrhajó ["+this.getNumberofmembers()+"] utassal és ["+this.ship_mass+"] tömeggel";
    }
}

