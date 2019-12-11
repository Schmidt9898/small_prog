using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HaziTest
{
    class Program
    {
        static void Main(string[] args)
        {

            Szamologep szml = new Szamologep();

            int[] eredmeny = {
                szml.oszead(2, 3),
            szml.szoroz(2, 3),
            szml.kivon(2, 3),
            szml.negyzet(2),
            szml.oszt(10, 2)
                };

            int[] megoldas = {5,6,-1, 4,5};
            
            for(int i=0;i<eredmeny.Length;i++)
            {
                if (megoldas[i] == eredmeny[i])
                {
                    Console.WriteLine(megoldas[i] + " helyes.");
                }
                else
                {
                    Console.WriteLine(megoldas[i] + " hibás.");
                }
            }


            Console.ReadKey();
        }
    }
}
