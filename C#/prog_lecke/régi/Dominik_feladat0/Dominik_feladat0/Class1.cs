using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dominik_feladat0
{
    abstract class Class1
    {
        public static void test(int a, int b, int c, int d, int e)
        {
            if(a<=0 || b<=0)
            {
                Console.WriteLine("Hiba: Nem pozitív bemenet.");
                Console.WriteLine("a "+a);
                Console.WriteLine("b " + b);
                return;
            }

            int cc = 0, dd = 0, ee = 0;

            if(a<b)
                cc = b - a;
            else
                cc = a - b;

            
            dd = 1;
            for(int i=cc;i!=0;i--)
            {
                dd *= cc;
            }

            ee = dd - 3;

            if(cc!=c)
            {
                Console.WriteLine("Hibás kivonás c ben.");
    //            return;
            }
            if(dd!=d)
            {
                Console.WriteLine("Hibás faktoriális d ben.");
       //         return;
            }
            if(ee!=e)
            {
                Console.WriteLine("Hibás e értéke.");
        //        return;
            }

            Console.WriteLine("cc: "+cc+" = c "+c);
            Console.WriteLine("dd: " + dd + " = d " + d);
            Console.WriteLine("ee: " + ee + " = e " + e);

            Console.WriteLine("Valódi osztói igy kell, hogy kinézzen:");

            for (int i=1;i<=ee;i++)
            {
                if((ee%i)==0)
                {
                    Console.WriteLine(i);
                }
            }
            
        }
    }
}
