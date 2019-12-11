public class firstMathlib {
    private int[] array = new int[10];

    public int size_of_array()
    {
        return array.length;
    }
    public int add(int a,int b)
    {
        return a+b;
    }
    public int subtract(int a,int b)
    {
        return a-b;
    }
    public boolean copy_array(int[] T)
    {
        if(array.length<T.length)
            return false;
        for(int i=0;i<T.length;i++)
        {
            array[i]=T[i];
        }
        return true;
    }
    public int[] getArray()
    {
        return array;
    }

}
