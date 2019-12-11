using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;

using System.IO;

namespace helo2._0
{
    class Program
    {
        
        static void Main(string[] args)
        {
            WebClient client = new WebClient();
           Console.Write( client.DownloadString("https://drive.google.com/uc?id=1bxlZCfz4xFm8oiVa4YUghpGJuM1SVYJS&export=download"));
            
            //StreamReader reader = new StreamReader(stream);
           //while (!reader.EndOfStream)
               /// Console.WriteLine(reader.ReadLine());
            Console.ReadKey();
        }
    }
}
