using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Functions
{
    class Program
    {
        static void Main(string[] args)
        {
            {/*
                Console.WriteLine("Functions...");

                Say();

                Action F = () => { Console.WriteLine("asd"); };

                List<elem> lista = new List<elem>();

            lista.Sort(delegate (elem elem1, elem elem2) { return elem1.a.CompareTo(elem2.a); });

                F();*/
            }


            Console.WriteLine("helo");
            Functions funcszionsz = new Functions();
            Random rng = new Random();
            int a = rng.Next(10);
            int b = rng.Next(10);
            double r = 5;
            Console.WriteLine( funcszionsz.körker(r) );


            Console.WriteLine(funcszionsz.negyker(a, b));
            int ar = 1000;

            Action Say = () => { Console.WriteLine("saasdasda sd asd awfjnjjkhakhjn lkmklagh "); };
            
            Console.WriteLine(funcszionsz.lear(ar,30,Say));
            /*Console.WriteLine(funcszionsz.lear(ar, 50));
            Console.WriteLine(funcszionsz.lear(ar, 0));
            Console.WriteLine(funcszionsz.lear(ar, -10));
            Console.WriteLine(funcszionsz.lear(ar, 100));
            Console.WriteLine(funcszionsz.lear(ar, 1200));
            */
            

            








            Console.ReadKey();
        }

    }
    

}
