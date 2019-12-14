using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Functions
{
    class Functions
    {
        public int buzibb(int r)
        {
            return 0;
        }
        public double körker(double r)
        {
            return 2 * r * pi();
        }
        double pi()
        {
            return 3.1415926535;
        }
        public double negyker(int a, int b)
        {
            return (a + b) * 2;
        }

        public double lear(int ar ,int szazalek ,Action F)
        {
            F();

            if (szazalek > 100)
                return 0;
            if (szazalek < 0)
                return ar;
            double ujar;
            ujar = ar - (ar * (double) szazalek / 100.0);

            return ujar;
        }


    }

}
