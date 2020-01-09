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

        public ulong[] primszam(ulong X)
        {
            if (X > 1)
            {
                ulong[] value = new ulong[X];

                value[0] = 2;
                ulong count = 1;
                ulong last = 2;


                for (ulong i = last + 1; i < ulong.MaxValue; i++)
                {
                    bool prim = true;
                    
                    for (ulong j = 2; j < i; j++)
                    {
                        if (i % j == 0)
                        {
                            prim = false;
                            break;
                        }
                    }
                    if (prim)
                    {
                        value[count] = i;
                        count++;
                        if (count == X)
                            break;
                    }
                }
                return value;
            }
            else if (X == 1)
            {
                ulong[] val ={ 2 };
                return val;
            }
            else
            return new ulong[0];
        }


        public ulong[] primszam2(ulong X)
        {
            if (X > 1)
            {
                ulong[] value = new ulong[X];

                value[0] = 2;
                ulong count = 1;
                ulong last = 2;


                for (ulong i = last + 1; i < ulong.MaxValue; i++)
                {
                    bool prim = true;
                    ulong til = i / 2;
                    for (ulong j = 2; j <= til; j++)
                    {
                        if (i % j == 0)
                        {
                            prim = false;
                            break;
                        }
                    }
                    if (prim)
                    {
                        value[count] = i;
                        count++;
                        if (count == X)
                            break;
                    }
                }
                return value;
            }
            else if (X == 1)
            {
                ulong[] val = { 2 };
                return val;
            }
            else
                return new ulong[0];
        }
        public ulong[] primszam3(ulong X)
        {
            if (X > 1)
            {
                ulong[] value = new ulong[X];

                value[0] = 2;
                ulong count = 1;
                ulong last = 2;


                for (ulong i = last + 1; i < ulong.MaxValue; i++)
                {
                    bool prim = true;

                    if (i % 2 != 0)
                    {
                        ulong til = i / 2;
                        for (ulong j = 3; j <= til; j+=2)
                        {
                            if (i % j == 0)
                            {
                                prim = false;
                                break;
                            }
                        }
                        if (prim)
                        {
                            value[count] = i;
                            count++;
                            if (count == X)
                                break;
                        }
                    }
                }
                return value;
            }
            else if (X == 1)
            {
                ulong[] val = { 2 };
                return val;
            }
            else
                return new ulong[0];
        }


    }

}
