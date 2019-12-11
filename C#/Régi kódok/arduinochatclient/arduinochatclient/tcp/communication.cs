using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arduinochatclient
{
    public static class communication
    {
       // public static int i = 0;
       // public static bool szabad = true;
        public static string textbe = null;
        public static List<sor> sorok = new List<sor>();
        public static string textki = "";
        public static long i = 0;
        public static int szalak = 0;
        public static bool szabad = true;
        public static System.Object objektum = new System.Object();
    }
    public static class Userdata
    {
        public static string nev = "nevtelen";
        public static String sajt_cim = "192.168.1.66";
        public static String cel_cim = "84.2.160.254";
        public static int port = 12345;
    }
}
