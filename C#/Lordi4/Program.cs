using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lordi4
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines("text.txt");
            string s_output = "";
            foreach (string sor in lines)
            {
                try
                {
                    if (sor.Contains("#"))
                    {
                        s_output += sor.Split('#')[1] + "\n";

                    }
                }
                catch (Exception)
                {

                }

            }
            Console.WriteLine(s_output);
            Console.ReadKey();
        }
    }
}
