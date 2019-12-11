using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace dominik_lecke1
{
    class player
    {
       public string name;
       int kills=0, deaths=0;
        
        public player(string name_)
        {
            name = name_;
        }
        public player(string name_, int k_,int d_)
        {
            name = name_;
            kills = k_;
            deaths = d_;
        }
        public player()
        {
            name = "none";
        }

        public void kill()
        {
            kills++;
        }

        public int getkills()
        {
            return kills;
        }
        public int getdeaths()
        {
            return deaths;
        }
    }
}
