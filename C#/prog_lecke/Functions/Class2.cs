using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Functions
{
    class pont
    {
        float x = 0;
        float y = 0;

        public pont(float x, float y)
        {
            this.x = x; this.y = y;
        }
        public float tavolsag(pont B)

        {
            float tav = 0;

            tav = (float)Math.Sqrt((Math.Pow(x - B.x, 2) + Math.Pow(y - B.y, 2)));

            


                return tav;
        }
    }
    class pontok
    {
        public pont[] asd(string x)
        {
            string[] sorok = System.IO.File.ReadAllLines("file1.txt");
            pont[] value = new pont[sorok.Length];

            float X, Y;
            

            for (int i = 0; i < sorok.Length ; i++)
            {
                string[] temp = sorok[i].Split('|');
                float.TryParse(temp[0], out X);
                float.TryParse(temp[1], out Y);
                value[i] = new pont(X, Y);
            }



                return value;
        }
    }

}
