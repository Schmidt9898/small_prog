using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mutable
{
    class Program
    {
        static void Main(string[] args)
        {
            //String str = "semmi";
            int str = 1;
                Console.WriteLine(str);
            Class1.f(ref str);
            Console.WriteLine(str);
            Console.ReadKey();
        }
    }
}
