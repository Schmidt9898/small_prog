using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MinimumEditDistance;
using FuzzyString;

namespace levenstein
{
    class Program
    {
        static void Main(string[] args)
        {
            string a, b;
            int l;
            List<FuzzyStringComparisonOptions> lista = new List<FuzzyStringComparisonOptions>();
           // lista.Add(FuzzyStringComparisonOptions.UseHammingDistance);
            lista.Add(FuzzyStringComparisonOptions.UseLongestCommonSubstring);

            while (true)
            {
                Console.WriteLine("ADJA MEG AZ a-t:");
                a=Console.ReadLine();
                Console.WriteLine("ADJA MEG AZ b-t:");
                b = Console.ReadLine();
                l=Levenshtein.CalculateDistance(a, b, 1);
                
                Console.WriteLine("Levenshtein Távolsága:" + l);
                //target mindig hosszabb??
                if (ComparisonMetrics.ApproximatelyEquals(a, b, lista, FuzzyStringComparisonTolerance.Weak))
                    Console.WriteLine("szerinte jó");
                else
                    Console.WriteLine("szerinte rosz");

            }
        }
    }
}
