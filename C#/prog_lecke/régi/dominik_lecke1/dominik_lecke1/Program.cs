using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace dominik_lecke1
{
    class Program
    {
        static void Main(string[] args)
        {
            /* int b = 1;



             Console.WriteLine(b);
             b=f(1);
             Console.WriteLine(b);*/
            //////////////////

            List<player> players = new List<player>();

            Random rng = new Random();
            int K=0, D=0;

            for(int i=0;i<2346000;i++)
            {
                K = rng.Next(0, 10000);
                D= rng.Next(1, 10000);
                players.Add(new player("jatekos",K,D));

            }

            double atlag = 0;
            for (int i = 0; i < players.Count; i++)
            {
                atlag += (double) players[i].getkills() / players[i].getdeaths();
            }
            atlag /= players.Count;


            Console.WriteLine("atlag: "+atlag);

           

           


           







            Console.ReadKey();

        }


















        static int f()
        {
           // x = 2;
           // Console.WriteLine("helo from fv: " + 2);
            return 2;
        }
       
    }
}
