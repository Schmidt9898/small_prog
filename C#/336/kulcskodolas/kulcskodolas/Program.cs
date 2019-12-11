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
        {
            while(true)
            {
                string target = "Ez egy hosszú szöveg a javából.";
                
                keywitktargetconv converter = new keywitktargetconv();
                Console.WriteLine(target);
                string key = Console.ReadLine();
                string detarget = converter.keytargetconv(key, target);
                Console.WriteLine(detarget);
                Console.WriteLine("dekódolás!");
                Console.WriteLine(converter.DEkeywithtarget(key, detarget));
                Console.ReadKey();
            }
            
        }
    }
}
