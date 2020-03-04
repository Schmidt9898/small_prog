using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eretsegi1
{
    enum Irany { be,ki}
    class Athaladas
    {
        public int ora, perc;
        public int person_id =-1;
        public Irany irany;
        public Athaladas(string sor)
        {
            string[] temp = sor.Split(' ');
            int.TryParse(temp[0], out ora);
            int.TryParse(temp[1], out perc);
            int.TryParse(temp[2], out person_id);
            irany = (temp[3].Contains("be")) ? Irany.be : Irany.ki;
        }

    }
    class person
    {
        public int id = -1;
        public int athaladas_szama = 0;
        int bejott = -1;
        int kiment = -1;
        bool bent_van = false;

        public person(int id)
        {
            this.id = id;

        }
        public void athalad()
        {
            athaladas_szama++;
        }
        public int perckonv(int ora,int perc)
        {
            return ora * 60 + perc;
        }
        public int[] orakonv(int perc)
        {
            int[] temp = { 0, 0 };
            temp[0] = perc / 60;
            temp[1] = perc - temp[0];
            return temp;
        }


    }
    class Athaladas_reader
    {
        public Athaladas[] read(string path)
        {
            string[] temp=System.IO.File.ReadAllLines(path);
            Athaladas[] value = new Athaladas[temp.Length];

            for(int i=0;i<temp.Length;i++)
            {
                value[i] = new Athaladas(temp[i]);
            }

            return value;
        }
        
    }


}
