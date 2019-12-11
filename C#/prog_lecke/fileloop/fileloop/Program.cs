using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fileloop
{
    class Program
    {
        static void Main(string[] args)
        {
            
            string[] fnev = System.IO.File.ReadAllLines(@"..\..\fnev.txt");
            string[] nnev = System.IO.File.ReadAllLines(@"..\..\nnev.txt");
            string[] csalad = System.IO.File.ReadAllLines(@"..\..\csalad.txt");
            string[] varos = System.IO.File.ReadAllLines(@"..\..\varos.csv");
           /* char c;
            for(int i=0;i<csalad.Length;i++)
            {
                c=csalad[i].First();
                csalad[i] = c+csalad[i].ToLower().Remove(0,1);

                Console.WriteLine(csalad[i]);
            }*/


            
            
            List<Person> emberek = new List<Person>();
            Random rng = new Random();
            bool nem;//false=férfi
            int meret = 1000000;
            for (int i=0;i<meret;i++)
            {
                nem = (rng.Next(2) == 1) ? true : false;
                if (nem)
                {
                    emberek.Add(new Person(nem,csalad,nnev,varos));
                }else
                {
                    emberek.Add(new Person(nem, csalad, fnev, varos));
                }
                


            }

            string[] sorok = new string[meret];
            for (int i = 0; i < meret; i++)
            {
                sorok[i] = emberek[i].ToFstring();
            }
            System.IO.File.WriteAllLines(@"..\..\database2.txt", sorok);

            
          //System.IO.File.WriteAllLines(@"..\..\csalad.txt", csalad);
            
            /*
            string str = "Alma";
            Console.WriteLine(str);
            string str_trim = "   körte   ";
            Console.WriteLine(str_trim);




            Console.WriteLine(str.ToLower());
            Console.WriteLine(str.ToUpper());
            Console.WriteLine(str_trim.Trim());

            Console.WriteLine(str.StartsWith("A"));
            Console.WriteLine(str.EndsWith("ma"));

            string str_replace = "Ez az alma vándorolna,ha nem épp egy alma volna.";
            Console.WriteLine(str_replace);
            Console.WriteLine(str_replace.Replace("alma","körte"));
            Console.WriteLine(str_replace.Remove(str_replace.Length/2));




            string split_str = "Schmidt Dominik";
            string[] splited = split_str.Split(' ');
            Console.WriteLine(splited[0]);
            Console.WriteLine(splited[1]);





    */



            Console.ReadKey();

        }
    }
}
