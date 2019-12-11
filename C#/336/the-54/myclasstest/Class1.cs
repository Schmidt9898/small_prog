using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace myclasstest
{
    [Serializable]
    public class Class1
    {
        public string a = "nem jó valami";
        public Action action=null;
        public string aa
        {
            get { return a; }
            set { a = value; }
        }
        public void Timewait()
        {
            Console.WriteLine(a);//ha az a kódolva van akkor még nem jó?


        }
    }
}
