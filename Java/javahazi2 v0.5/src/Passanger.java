import sun.reflect.generics.reflectiveObjects.NotImplementedException;

public class Passanger extends Thread{
    int passanger_id;
    SpaceCraft myspacecraft;

    //véletlen időt tartózkodik a fedélzeten

    public Passanger(int id,SpaceCraft my)
    {
        this.passanger_id=id;
        this.myspacecraft=my;
    }

    public void setMyspacecraft(SpaceCraft myspacecraft) {
        this.myspacecraft = myspacecraft;
    }

    @Override
    public String toString() {
        return passanger_id+" azonosítójú utas";
    }

    @Override
    public void run() {
       // Main.Log(this.toString()+" megkezdte a kirándulást.");
        ((SpaceShip)myspacecraft).Board_the_Station(this);

        try {
            Thread.sleep(100);//valameddig
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        ((SpaceStation)myspacecraft).Leaving_the_Station(this);
    }
}
