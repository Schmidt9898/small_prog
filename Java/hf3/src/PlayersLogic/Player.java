package PlayersLogic;

public interface Player {

    public void move(int x,int y);
    public void place(int x,int y);
    public void action();
    public void damage();
    public void die();

}
