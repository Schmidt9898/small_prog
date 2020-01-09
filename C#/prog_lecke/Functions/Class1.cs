using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Functions
{
    class Class1
    {
        public int[] szam(int X)
        {
            if(X>0)
            int[] value = new int[X];

            value[0] = 2;
            int count = 1;
            int last = 2;
        
                
                for(int i=last;i<int.MaxValue;i++)
                {
                bool prim = true;
                    for(int j=2;j<i;j++)
                    {
                        if(i%j==0)
                        {
                        prim = false;
                        break;
                        }
                    }
                    if(prim)
                        {
                    value[count] = i;
                    count++;
                    if (count == X)
                        break;
                        }
                }
            return value;
        }
    }
}
