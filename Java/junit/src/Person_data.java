import java.util.ArrayList;
import java.util.List;

class Person_container{
    public IPerson person;
    List<IPerson> friends=new ArrayList<IPerson>();
    Boolean isFriendWith(String friendName)
    {
        for (IPerson f : friends) {
            if(f.getName().equals(friendName))
                return true;
        }
        return false;
    }
}
public class Person_data{

    List<Person_container> peoples=new ArrayList<>();
Boolean isFriendWith(String name, String friendName)
    {
        for (Person_container p : peoples) {
            if(p.person.getName().equals(name)) {
                if (p.isFriendWith(friendName))
                    return true;
            break;
            }
        }
        return false;
    }

}
