using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fileloop
{
    class Person
    {
        bool nem;
        string first_name,last_name;
        string varos;
        int post;
        static Random rng = new Random();
        public Person(string fname, string lname)
        {
            first_name = fname;
            last_name = lname;
        }
        public Person(bool nem_,string[] csalad,string[] nev,string[] varos)
        {
            
            nem=nem_;
            first_name = csalad[rng.Next(0, csalad.Length)];
            last_name = nev[rng.Next(0, nev.Length)];
            this.varos=varos[rng.Next(0, varos.Length)];

        }

        public string ToString()
        {
            return first_name + " " + last_name;
        }
           public string ToFstring()
        {
            return ((nem)?"1":"0")+","+first_name + " " + last_name+","+varos;
        }
    }

   

}
