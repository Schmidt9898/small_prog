using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Functions
{
    class XY
    {
        //public string name = "senki";
        public float x = 0;
        public float y = 0;
        public XY(float x_,float y_)
        {
            //name = n;
            x = x_;
            y = y_;
        }
        override
            public string ToString()
        {
            return x + "|" + y;
        }
    }
    class Kordi_kezelo
    {
        Random rng = new Random();
        public XY[] kordi_olvas(string ut)
        {
            string[] sorok = System.IO.File.ReadAllLines(ut);
            XY[] val = new XY[sorok.Length];
            for (int i= 0; i < sorok.Length;i++)
            {
                string[] tort = sorok[i].Split('|');
                float x, y;
                float.TryParse(tort[0], out x);
                float.TryParse(tort[1], out y);
                XY temp = new XY(x,y);
                val[i] = temp;
            }
            return val;
        }

        public void kordi_rng(float w,float h,long count, string utnev)
        {
            string[] val = new string[count];
            for (int i = 0; i < count; i++)
            {
                float x = (float)rng.NextDouble() * w - (w / 2);
                float y = (float)rng.NextDouble() * h - (h / 2);


               
                val[i]= new XY(x, y).ToString();
            }


            System.IO.File.WriteAllLines(utnev, val);
        }



    }
}
