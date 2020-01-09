using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Functions
{
    class Cint
    {
        int r=0, i=0;

        public Cint(int r_)
        {
            r = r_;
        }
        public Cint(int r_,int i_)
        {
            r = r_;
            i = i_;
        }

        public static Cint operator +(Cint a,Cint b)
        {
            return a.add(b);
        }
        public static Cint operator *(Cint a, Cint b)
        {
            return a.multi(b);
        }
        public Cint add(Cint x)
        {
            return new Cint(r+x.r,i+x.i);
        }
        public Cint multi(Cint x)
        {
            int R, I;
            R = r * x.r - i * x.i;
            I = r * x.i + x.r * i;
            return new Cint(R, I);
        }
        override
        public string ToString()
        {
            if (i == 0)
                return r.ToString();
            return r + "+" + i + "i";
        }
        
    }
}
