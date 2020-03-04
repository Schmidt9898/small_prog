using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eretsegi1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Tarsalgo....");
            Athaladas_reader reader = new Athaladas_reader();
            
            Athaladas[] athaladasok = reader.read("ajto.txt");
            Console.WriteLine("1. feladat sikeres olvasás.");

            Console.WriteLine("2. Feladat:");
            // feltételezve hogy mivel a társalgó üres ezért az első ember csak is be léphet
            Console.WriteLine("Az első belépő :"+athaladasok[0].person_id);
            int id = -1;
            foreach(Athaladas a in athaladasok)
            {
                if (a.irany == Irany.ki)
                    id = a.person_id;
            }
            Console.WriteLine("At utolsó kilépő: " + id);
            SortedDictionary<int, int> id_parok = new SortedDictionary<int, int>();
            //List<person> Emberek = new List<person>();
            //List<int> emberids = new List<int>();
            foreach (Athaladas a in athaladasok)
            {
                if(id_parok.ContainsKey(a.person_id))
                {
                    id_parok[a.person_id] += 1;
                }
                else
                {
                    id_parok.Add(a.person_id, 1);
                }
            }

            foreach(var par in id_parok)
            {
                Console.WriteLine(par.Key + " : " + par.Value);
            }





            Console.WriteLine("vége.");
            Console.ReadKey();
        }
    }
}
