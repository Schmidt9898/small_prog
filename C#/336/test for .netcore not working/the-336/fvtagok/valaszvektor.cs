using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace the_336.fvtagok
{
    class valaszvektor
    {
        Dictionary<string, string> lista= new Dictionary<string, string>();

        public valaszvektor(Stream sorce)
        {
            filetodictionary(lista, sorce);
        }

        public void filetodictionary(Dictionary<string, string> lista, Stream sorce)
        {
            //beolvasást megírni!!
        }
    }
}
