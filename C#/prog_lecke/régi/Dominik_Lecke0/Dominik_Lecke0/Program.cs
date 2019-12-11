using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dominik_Lecke0
{
    class Program
    {
        static void Main(string[] args)
        {//Itt indul a program.

            //Egy program utasitások egymásutánisága, a számítógép sorrol sorra halad.
            Console.WriteLine("első");   
            Console.WriteLine("második");
            Console.WriteLine("harmadik");

            //Egy programban vannak változók. A változók valamilyen értéket vehetnek fel. lehetnek több típusúak.

            /*
            int Aszam = 1; //egész szám.
            int Bszam = 2;
            double Ctort = 0.000123;
            //float Dtort

            char karakter = 'a';
            string szoveg = "Helló, itt a string változó.";

            Console.WriteLine("Ime az Aszam: " + Aszam);
            Console.WriteLine("Most írj be valamit...");
            Aszam = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(Aszam + " ezt írtad.");

            */

            int a=0, b=0, c=0;

            while (Console.ReadKey().Key != ConsoleKey.Escape)
            {
                Console.WriteLine("Add meg az 'a' szamot.");
                a = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Add meg az 'b' szamot.");
                b = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Add meg az 'c' szamot.");
                c = Convert.ToInt32(Console.ReadLine());
                //(-b +- sqrt(bˇ2-4*a*c))/2*a
                double x1, x2;
                x1 = ((-1) * b + Math.Sqrt(b * b - 4 * a * c)) / (2 * a);
                x2 = ((-1) * b - Math.Sqrt(b * b - 4 * a * c)) / (2 * a);

                Console.WriteLine("x1: " + x1);
                Console.WriteLine("x2: " + x2);
            }
            Console.WriteLine("bezárás..");
            Console.ReadKey();
        }//Itt ér véget.
    }
}
