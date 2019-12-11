using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dominik_megoldas
{
    public class CAR
    {
        string carType;
        string numberplate;
        int tanksize;
        double fuellevel=0;
        double fuelconsume;




        public CAR(string cartype_,int tanksize_,double fuelconsume_)
        {
            carType = cartype_;
            tanksize = tanksize_;
            fuelconsume = fuelconsume_;
            Random random = new Random();
            numberplate = "ASD-"+random.Next(1, 1000);
        }

        public void refill(int fuelin)
        {
            if ((fuellevel+fuelin) >= tanksize)
                fuellevel = tanksize;
            else
                fuellevel += fuelin;
        }





        public bool go(int km)
        {
            if(km < (fuellevel / fuelconsume * 100)) { fuellevel -= ((double)km / 100) * fuelconsume; return true; } else return false;
        }

        public double getfuellevel()
        {
            return fuellevel;
        }

        public string  ToString()
        {
            return carType + " : " + numberplate +"\n fuellevel:"+fuellevel;
        }
        



    }
}
