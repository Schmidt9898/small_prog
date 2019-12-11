using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace andor
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "Alma";
            Console.WriteLine(str);
            string str_Jani = str.ToUpper();
            Console.WriteLine(str_Jani);
            Console.WriteLine(str.ToLower());
            string str_trim = "                                   dio        ";
            Console.WriteLine(str_trim.Trim());


            string korte = "Lacika nagyon okos mert Lacika magában beszél Lacikával mert ő Lacika";
            Console.WriteLine(korte.Replace("Lacika", "Andor"));
            Console.WriteLine(korte.Remove(10));

            Console.WriteLine(str.EndsWith("a"));
            string name = "Staar Andor";
            string[] pali = name.Split('a');
            Console.WriteLine(pali[0]);
            Console.WriteLine(pali[1]);



            string[] nevek=System.IO.File.ReadAllLines(@"names.txt");
            int sanyi = 0;
            foreach (string sor in nevek)
            {
               if(sor.Contains("A") || sor.Contains("a"))
                {
                    sanyi++;
                }
            }

            Console.WriteLine(sanyi);




            Console.ReadKey();
        }
        

     
    }
}
