using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2byte
{
    class Program
    {
        static void Main(string[] args)
        {
            //string asd = "aaaaaaaaaaaaaaaa";

            byte[] a = new byte[] { 98, 1, 98, 1, 98, 1, 98, 1, 98, 1, 98, 1, 98, 1, 98, 1, 98, 1, 98, 1, 98, 1, 98, 1, 98, 1, 98, 1, 98, 1, 98, 1};//Encoding.Unicode.GetBytes(asd);
            foreach(byte i in a)
            {
                Console.Write((i-1)+",");
            }
            //Console.WriteLine(a);
            Console.ReadKey();
        }
    }
}
