using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gfalgebra
{
    class GFI
    {
        public uint q = 2;
        public uint dec = 0;
        public uint[] vector;
        public uint len = 0;


        public GFI(uint szam,uint len)
        {
            this.len = len;
            dec = szam;
            
        }

        public static uint[] ToBinary(uint dec,uint len)
        {
            uint[] ans = new uint[len];
            uint idx = 0;
            uint osto = (uint)Math.Pow(2, len-1); 
            while(dec!=0)
            {
                if(dec>=osto)
                {
                    dec %= osto;
                    osto /= 2;
                    ans[idx] = 1;
                }else
                {
                    osto /= 2;
                    ans[idx] = 0;
                }
                idx++;
            }
            return ans;
        }
        void normal()
        {
            for(int i=0;i<vector.Length;i++)
            {
                vector[i] %= 2;
            }
        }

    }
}
