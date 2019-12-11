using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace byteconverter
{
    class Program
    {
        static void Main(string[] args)
        {
            NAudio.Wave.Mp3FileReader tomb = new NAudio.Wave.Mp3FileReader(@"C:\Users\Schmidt László\Music\Tenacious D - We Are The D.mp3");
            
            using (System.IO.StreamWriter file =
           new System.IO.StreamWriter(@"C:\Users\Schmidt László\Desktop\bite.txt", true))
            {
                int i = -1;
                while((i=tomb.ReadByte())!=-1)
                {
                    file.Write((byte)i);
                    Console.Write((byte)i);
                }

                
            }
        }
    }
}
