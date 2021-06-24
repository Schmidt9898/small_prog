package mainpackage;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Vector2Test {

    @Test
    void add() {
        Vector2 a = new Vector2(0,0);
        Vector2 b = new Vector2(1,0);

        Vector2 c = Vector2.add(a,b);

        assertEquals(1,c.getX());
        assertEquals(0,c.getY());



    }


    @Test
    void add2() {
        Vector2 a = new Vector2(0,0);
        Vector2 b = new Vector2(1,0);

        Vector2 c = Vector2.add(a,b);

        assertEquals(1,c.getX());


    }

}