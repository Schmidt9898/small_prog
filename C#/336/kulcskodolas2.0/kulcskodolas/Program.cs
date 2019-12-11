using Keywithtargetconv;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace kulcskodolas
{
    class Program
    {
        static void Main(string[] args)
        {/*
            Console.OutputEncoding = Encoding.UTF8;
            Console.InputEncoding = Encoding.UTF8;
            */
            while (true)
            {
                string target = "helo ékezetes string";
                
                keywitktargetconv converter = new keywitktargetconv();
                Console.WriteLine(target);
                string key = Console.ReadLine();
                string detarget = converter.keytargetconv(key, target);
                Console.WriteLine(detarget);
                Console.WriteLine("dekódolás!");
                key=Console.ReadLine();
                target = converter.DEkeywithtarget(key, detarget);
                Console.WriteLine(target);
                Console.ReadKey();
            }
            
        }
    }
}
