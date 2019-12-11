import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import java.util.Random;

public class Passanger extends Thread{
    int passanger_id;
    String name="Bob";
    SpaceCraft myspacecraft;

    //véletlen időt tartózkodik a fedélzeten

    public Passanger(int id,SpaceCraft my)
    {
        this.passanger_id=id;
        this.myspacecraft=my;
        System.out.println(id+"asdasd");
    }
    public Passanger(int id,SpaceCraft my,String name)
    {
        this.passanger_id=id;
        this.myspacecraft=my;
        this.name=name;

    }

    public void setMyspacecraft(SpaceCraft myspacecraft) {
        this.myspacecraft = myspacecraft;
    }

    @Override
    public String toString() {
        return name+"["+passanger_id+"] azonosítójú utas ";
    }

    @Override
    public void run() {

        ((SpaceShip)myspacecraft).Board_the_Station(this);

        try {
          //  Random r=new Random();
            Thread.sleep((int)(Math.random()*40000 + 20000));//valameddig
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        ((SpaceStation)myspacecraft).Leaving_the_Station(this);
    }
}
