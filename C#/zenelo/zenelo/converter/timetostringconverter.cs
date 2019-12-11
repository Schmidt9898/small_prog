using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zenelo.converter
{
    class timetostringconverter
    {
        int perc = 0;
        int mp = 0;



        public string timetostring(double value)
        {
            perc = (int)value / 60;
            mp = (int)value - perc * 60;
            return perc.ToString("D2") + ":" + mp.ToString("D2");
        }
    }
    
}
