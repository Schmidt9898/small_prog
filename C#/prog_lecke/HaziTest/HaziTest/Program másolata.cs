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
            string str = "Haloka beloka.";
            string delete = "alma alma alma alma alma körte alma körte";

            //->
            //ezek a jelek közé írhattok máshova nem!!




            //<-
            if (str[2].Equals('L'))
                Console.WriteLine(str);
            else
                throw new Exception();

            if (!delete.Contains("alma") && delete.Contains("körte"))
            {
                Console.WriteLine(delete);
            }
            else
                throw new Exception();


            


            while (true)
            {
                //->    lépj ki 100 iteráció után


               
                //<-
                while_count++;

                
            //-> 10 szer legyen kiírva hogy "for"
            for()
            //<-
            {
                    Console.WriteLine("for");
                    
            }
                
                string[] stomb = { "Laci", "", "falka", "", "galma" };
                //->
                for ()
                //<-
                {
                    Console.WriteLine(stomb[i]);
                }


                ///if else
                bool ba, bb, bc;
                Random rng = new Random();
                ba = (rng.Next(1)==1) ? true : false;
                bb = (rng.Next(1) == 1) ? true : false;
                bc = (rng.Next(1) == 1) ? true : false;
               
                //Minden lehetséges kombinációt kezelj külön és írd ki a consolra
                //->


                //<-










            






           







    
            Console.ReadKey();
        }
    }
}
