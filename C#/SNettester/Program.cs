using System;
using SNetwork;

namespace SNettester
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            
           // Object a = new SNetPacket();
            float i = 214;
            double j = 7;
            testclass t = new testclass();

            Type selected = i.GetType();
            Console.WriteLine(selected);
            Console.WriteLine(t.GetType().ToString());
            Console.WriteLine(TypeCode.String.ToString());
            Console.ReadKey();
        }
    }
}
