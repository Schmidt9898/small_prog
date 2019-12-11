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
        string a = "helo from class";
        public Action action=null;
        public string aa
        {
            get { return a; }
            set { a = value; }
        }
    }
}
