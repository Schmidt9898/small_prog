using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace roglecke2
{
    class Program
    {

        static void Main(string[] args)
        {
            /*
            int merete = 1000000;

            int[] a = new int[merete];
            List<double> lista = new List<double>();
            int[] b = { 1, 2, 3 };
            
            for(int i=0;i<100;i++)
            {
                

                lista.Add(Kerulet(i));
            }
           
            for (int i = 0; i < lista.Count; i++)
            {
                Console.WriteLine(lista[i]);
               
            }
            */

            /*









            int domi = 2;
            Console.WriteLine(domi);
            Fv(ref domi);
            Console.WriteLine(domi);

            // Console.WriteLine(b[4]);
            Console.ReadKey();
            */



            /*
            int[] halal = new int[100];
            int kill = 10;
            string neve = "dominik";
            
        
            int halal2 = 1;
            int kill2 = 100;
            string neve2 = "andor";

            */
            /*
            Jateko player = new Jateko("domi234nik");

            player.gyilkolas();

            player.halalozas();

            double kd = player.kd();

            Console.WriteLine(player.ToString());


            List<Jateko> players = new List<Jateko>();

            int meret = 100;
            for (int i = 0; i < meret; i++)
            {
                players.Add(new Jateko("pali" + i));
            }


            for (int i = 0; i < meret; i += 2)
            {
                players[i].gyilkolas();
                players[i].gyilkolas();
                //jakakos.gyilkolas();
            }
            for (int i = 1; i < meret; i += 2)
            {
                players[i].gyilkolas();
                players[i].halalozas();
                players[i].halalozas();
                //jakakos.gyilkolas();
            }

            foreach (Jateko jakakos in players)
            {
                Console.WriteLine(jakakos.ToString());
            }

            */

            /*
            int f = 10;
            Console.WriteLine( factor(f));

            Random rng = new Random();
            int randomn=rng.Next(500, 10000);
            Console.WriteLine(randomn);

            Console.ReadKey();
            */
            /*
            { 
            int valami;
        }
            valami = 2;
            */
            //tomb array
            //static is
            //fv
            //parameter passing
            //class fv
            //class
            //
        }

       

        
static double Kerulet(int r)
{
   return r * r * Math.PI;
}

        static int factor(int c)
        {
            if (c == 1)
                return 1;
            return c*factor(c - 1);
        }


        static void Fv(ref int parameter)
        {
            parameter = 5;
            Console.WriteLine("domi új jegye:"+ parameter);
        }




    }
}
