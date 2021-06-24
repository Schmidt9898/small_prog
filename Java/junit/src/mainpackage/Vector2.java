package mainpackage;

public class Vector2 {

    int x,y;


    public Vector2(int x_,int y_)
    {
        x=x_;y=y_;
    }

    public static Vector2 add(Vector2 a,Vector2 b)
    {
        Vector2 c= new Vector2(0,0);
        c.x=a.x+b.x;
        c.y=a.y+b.y;
        return c;
    }


    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}
