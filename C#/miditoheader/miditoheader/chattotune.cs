using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace miditoheader
{
    class chattotune
    {

        static public String totune(char hight,char tune)
        {
            if (tune.Equals('-'))
                return "0,";

            string tune_ = "";
            if (char.IsUpper(tune))
                tune_ = tune + "s";
            else
                tune_ = tune + "";

            tune_ = tune_.ToUpper()+hight;
            /*
            foreach(string line in Program.notes)
            {
                if (line.Contains(hight) && line.Contains(tune))
                {

                }
            }*/




            return "NOTE_"+tune_+",";
        }
    }

}
