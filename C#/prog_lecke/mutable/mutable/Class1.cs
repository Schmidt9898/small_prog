using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mutable
{
    class Class1
    {
        public static void f(String str)
        {
            
            str = "nem "+str;
            Console.WriteLine(str);
        }

        public static void f(ref int str)
        {

            str = 2 + str;
            Console.WriteLine("fv: "+str);
        }
    }
}
