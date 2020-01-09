using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Functions
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            Functions fv = new Functions();
            


           var watch = System.Diagnostics.Stopwatch.StartNew();
            // Thread.Sleep(1000);

            ulong [] primek = fv.primszam(10000);



            watch.Stop();
            
            Console.WriteLine("idő miliszekundban: "+watch.ElapsedMilliseconds);
            Console.WriteLine("idő tickben: "+watch.ElapsedTicks);
            */
            /* foreach (int i in primek)
             {
                 Console.WriteLine(i);
             }
             */

            /*


            Cint a = new Cint(5);
            Cint b = new Cint(5, 2);

            Console.WriteLine(a);
            Console.WriteLine(b);
            Console.WriteLine(a+b);
            Console.WriteLine(a*b);
            b = new Cint(0, 1);
            a = b * b;
            Console.WriteLine(a);
            Console.WriteLine(a*b);


    */

            Kordi_kezelo k = new Kordi_kezelo();
              k.kordi_rng(1000,1000,5000000,"file2.txt");
            XY[] tomb = k.kordi_olvas("file1.txt");
            foreach(XY i in tomb)
            {
                Console.WriteLine(i.ToString());
            }

            /*
            pontok r = new pontok();
            pont[] point = r.asd("file.txt");
            pont origo = new pont(0, 0);
            float s = origo.tavolsag(point[0]);
            Console.WriteLine(s);
            foreach(pont i in point)
            {
                Console.WriteLine(origo.tavolsag(i));
            }
            */







                Console.ReadKey();
        }  
        

    }
    

}
