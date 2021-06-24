import java.util.ArrayList;
import java.util.List;

public abstract class Software {
String name;
}
interface ITeleitheto{
    void Telepit();
}
class UtilitySftware extends Software implements ITeleitheto
{

    @Override
    public void Telepit() {
        System.out.println("A "+name+" szoftver települ!");
    }
}
class VideoGame extends Software implements ITeleitheto
{

    @Override
    public void Telepit() {
        System.out.println("A "+name+" szoftver települ!");
    }
}
class SmallApplications extends Software implements ITeleitheto
{

    @Override
    public void Telepit() {
        System.out.println("A "+name+" szoftver települ!");
    }
}


class Virtual_Lib
{
    public List<Software> lib=new ArrayList<Software>();

    void felvitel(Software s)
    {
        lib.add(s);
        System.out.println("A "+s.name+" szoftver hozzáadásra került!");

    }
    void torles(Software s)
    {
        lib.remove(s);
        System.out.println("A "+s.name+" szoftver törlésre került!");
    }
}

