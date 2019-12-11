
import org.junit.Test;

import static org.junit.Assert.*;

public class firstMathlibTest {

    @org.junit.Test
    public void size_of_array() {
        firstMathlib fml=new firstMathlib();

        assertEquals(10,fml.size_of_array());
    }

    @org.junit.Test
    public void add() {
        firstMathlib fml=new firstMathlib();
         int value=fml.add(5,1);
         assertEquals(6,value);
         assertFalse(value<(5));
    }

    @org.junit.Test
    public void subtract() {
        firstMathlib fml=new firstMathlib();
        int value=fml.subtract(5,4);
        assertEquals(1,value);
    }

    @Test
    public void copy() {
        int[] T={0,1,2,3,4,5,6,7,8,9};
        int[] F={0,1,2,3,4,5,6,7,8,9,1,1,1,1};
        firstMathlib fml=new firstMathlib();
        assertTrue( fml.copy_array(T));
        assertFalse( fml.copy_array(F));
        assertArrayEquals(fml.getArray(),T);
    }
}