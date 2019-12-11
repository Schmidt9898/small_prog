using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dominik_feladat1
{
    class Program
    {
        static void Main(string[] args)
        {
            int tele = int.MaxValue;

            CAR car1 = new CAR("4karika", 50, 2.3);
            CAR car2 = new CAR("Paci", 45, 10);
            CAR car3 = new CAR("Bömbi", 70, 3.4);
            CAR car4 = new CAR("Cica", 55, 1.7);

            Console.WriteLine("Teszt start!\n Car 1");
            
            car1.refill(tele);
            if(car1.go(20))
            {
                Console.WriteLine(car1.ToString());
                Console.WriteLine("SIKER Megtett 20 kilómétert.");
            }
            else
            {
                Console.WriteLine(car1.ToString());
                Console.WriteLine("hiba");
            }

            Console.WriteLine("Car 2");
            car2.refill(10);
            car2.refill(0);
            if (car2.getfuellevel()==10)
            {
                Console.WriteLine(car2.ToString());
                Console.WriteLine("SIKER refill jól működik.");
            }
            else
            {
                Console.WriteLine(car2.ToString());
                Console.WriteLine("hiba");
            }


            Console.WriteLine("Car 3");
            car3.refill(1);

            if (!car3.go(9999))
            {
                Console.WriteLine(car3.ToString());
                Console.WriteLine("SIKER nem tud menni 9999 kilómétert 1 literből.");
            }
            else
            {
                Console.WriteLine(car3.ToString());
                Console.WriteLine("hiba");
            }


            Console.WriteLine("Car 4");
            car4.refill(20);
            car4.go(100);
            if (car2.getfuellevel() < 20)
            {
                Console.WriteLine(car4.ToString());
                Console.WriteLine("SIKER tud menni és fogy az üzemanyag.");
            }
            else
            {
                Console.WriteLine(car4.ToString());
                Console.WriteLine("hiba");
            }

            Console.ReadKey();

        }


    }
}
