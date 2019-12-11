using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arduinochatclient
{
    class soregyseg_converter
    {
        
        public List<sor> to(Stream forras)
        {
            //var stream = new MemoryStream();
          //  var writer = new StreamWriter(forras);
         
            var reader = new StreamReader(forras);
            //writer.Write(forras);
            //writer.Flush();
            forras.Position = 0;
            List<sor> lista = new List<sor>();
            string szoveg = "";
            
            string nev = "";
           while(!reader.EndOfStream)
            {
                reader.Read();
                {
                    nev = "";
                    while((char)reader.Read() != '|')
                    {
                        nev += (char)reader.Read();
                    }
                }
                reader.Read();
                {
                    szoveg = "";
                    while ((char)reader.Read() != '#')
                    {
                        szoveg += (char)reader.Read();
                    }
                }
                lista.Add(new sor(nev, szoveg));

            }

            return lista;
        }

    }
    public struct sor
    {
        public string nev;
        public string szoveg;
       public sor(string nev_, string szoveg_)
        {
            nev = nev_;
            szoveg = szoveg_;
        }
    }
}
