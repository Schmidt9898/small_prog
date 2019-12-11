using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace miditoheader
{
    class Program
    {
        //  List<String> bass = new List<string>();
        static List<String> dallam = new List<string>();
        static String path = @"C:\Users\Schmidt László\Desktop\undertale.txt";
      //  public static string[] notes = File.ReadAllLines("tunes.txt");
        static void Main(string[] args)
        {
            path = args[0];
            Console.WriteLine(path);
            Console.ReadKey();
            Console.WriteLine("Converting.");
            string[] file = File.ReadAllLines(path);
            
            String[] pipe=null;
            foreach (string line in file)
            {
                if (line.Length > 3 && pipe==null)
                {
                    pipe = new String[line.Length - 3];
                    char notehight = line[0];
                    for(int i=2;i< line.Length-1;i++)
                    {

                        pipe[i - 2] = chattotune.totune(notehight,line[i]);
                    }
                }else if( line.Length > 3 && pipe != null)
                    {
                    char notehight = line[0];
                    for (int i = 2; i < line.Length - 1; i++)
                    {
                        if (!pipe[i - 2].Contains("0,"))
                            continue;
                        pipe[i - 2] = chattotune.totune(notehight, line[i]);
                    }
                }
                else
                {
                    if (pipe != null)
                    {
                        dallam.AddRange(pipe);
                        pipe = null;
                    }
                }
                

                
            }

            File.WriteAllLines(path+"2.txt", dallam);
            Console.WriteLine("Complette.");
            Console.ReadKey();
        }
        



    }
}
