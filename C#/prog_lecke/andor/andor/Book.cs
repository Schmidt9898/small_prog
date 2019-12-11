using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace andor
{
    class Book
    {
        string író;
        string megjelenés;
        string cím;
        string műfaj;
        int ára;
        List<string> kölcsön = new List<string>();




        public Book(string író, string megjelenés, string cím, string műfaj, int ára)
        {
            this.író = író; this.megjelenés = megjelenés; this.cím = cím; this.műfaj = műfaj; this.ára = ára;
        }
        public Book(string író, string cím, string műfaj, int ára)
        {
            this.író = író; this.cím = cím; this.műfaj = műfaj; this.ára = ára;
        }

        public string ToString()
        {
            string Jani = "";
            Jani = író +" " + cím +" " + ára + "Forint";
            



            return Jani;
        }

        public void kölcsönöz(string name)
        {
            foreach(string elem in kölcsön)
            {
                if(elem.Equals(name))
                {
                    return;
                }
            }



            kölcsön.Add(name);
        }




    }
}
