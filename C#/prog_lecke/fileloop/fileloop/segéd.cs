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
            
            string[] sorok = System.IO.File.ReadAllLines(@"names.txt");


            List<Person> emberek = new List<Person>();

            foreach(string sor in sorok)
           {
               Console.WriteLine(sor);
           }


            for (int i=0;i<1000;i++)
            {
                emberek.Add(new Person(sorok));
            }
            List<string> ujlista = new List<string>();
            foreach (Person person in emberek)
            {
                Console.WriteLine(person.ToString());
                ujlista.Add(person.ToString());

            }

            System.IO.File.WriteAllLines(@"ujfile.txt", ujlista);
            //System.IO.File.AppendAllLines(@"ujfile.txt", ujlista);
            


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

            Console.ReadKey();

        }
    }
}
