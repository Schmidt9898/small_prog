using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace usingfile
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("Usingfile..");
            string[] data = System.IO.File.ReadAllLines(@"..\..\database2.txt");
            List<Person> emberek = new List<Person>();
            for(int i=0;i<data.Length;i++)
            {
                //  Console.WriteLine(data[i]);
                emberek.Add(new Person(data[i]));
            }


            int nökszama = 0;
            int ferfiszam = 0;
            foreach(Person ember in emberek)
            {
                if (ember.neme == nem.ferfi)
                    ferfiszam++;
                else
                    nökszama++;
            }
           
            Console.WriteLine("Nők: " + nökszama);

            int schmidtszám = 0;
            foreach(Person ember in emberek)
            {
                if (ember.csalad.Equals("Schmidt"))
                    {
                    schmidtszám++;
                    if (schmidtszám > 100)
                        
                           
                        Console.WriteLine(ember.ToString());
                     
                    if (schmidtszám == 200)  break;

                }
            }
            Console.WriteLine("Schmidtek: " + schmidtszám);

           











            Console.ReadKey();
        }
    }
}
