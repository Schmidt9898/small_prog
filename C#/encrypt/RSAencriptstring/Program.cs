using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;
using System.Xml.Serialization;
using System.IO;

namespace RSAencriptstring
{
    class Program
    {
        static void Main(string[] args)
        {
            //string s=Kodol.generatekeys();
            //System.IO.File.WriteAllText("deletme", s);
            
            Kodol kodol = new Kodol();
            string msg = "hi én vagyok az igen.";
            msg=kodol.Encode(msg,"Warden");
            Console.WriteLine(msg);
            Console.WriteLine("----------");
            msg = kodol.Decode(msg, "Warden");
            Console.WriteLine(msg);
            
            Console.ReadKey();
        }
    }
}
