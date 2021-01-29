using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;
using System.Xml.Serialization;
using System.Xml;
using System.IO;

namespace RSAencriptstring
{
    class Kodol
    {
        
        private string password = "gSWLfEXV5smb8kEyMZWvqa/NukbKg9LuhndmwzXpOHU=";
        private RSACryptoServiceProvider rcp;
        XmlSerializer xs;
        SHA256 hash = SHA256.Create();
        
        public Kodol()
        {
            this.revertkey();
        }

        //public bool setpass(string new_pass, string old_pass)
        //{
        //    if(!ispassgood(old_pass))
        //        return false;
        //}
        private bool ispassgood(string pass)
        {
            byte[] data = hash.ComputeHash(Encoding.UTF8.GetBytes(pass));

            string trypass = Convert.ToBase64String(data);

            return trypass.Equals(password);
        }


        public string Encode(string msg, string pass)
        {
            if (!ispassgood(pass))
                return "Wrong password.";
            var data = Encoding.Unicode.GetBytes(msg);

            var encoder = new RSACryptoServiceProvider();
            encoder.ImportParameters(rcp.ExportParameters(false));

            var coded = encoder.Encrypt(data, false);
            return Convert.ToBase64String(coded);
        }
        public string Decode(string msg, string pass)
        {
            if (!ispassgood(pass))
                return "Wrong password.";
            var data = Convert.FromBase64String(msg);
            return Encoding.Unicode.GetString(rcp.Decrypt(data, false));

        }
        public static string generatekeys()
        {
            string keys = "";

            var temp_privider = new RSACryptoServiceProvider(1024);

            RSAParameters new_keys = temp_privider.ExportParameters(true);
            string keyprint = "";

            keyprint += arraytostring(new_keys.Exponent, "exponent") + "\n";
            keyprint += arraytostring(new_keys.Modulus, "modulus") + "\n";
            keyprint += arraytostring(new_keys.P, "p") + "\n";
            keyprint += arraytostring(new_keys.Q, "q") + "\n";
            keyprint += arraytostring(new_keys.DP, "dp") + "\n";
            keyprint += arraytostring(new_keys.DQ, "dq") + "\n";
            keyprint += arraytostring(new_keys.InverseQ, "iq") + "\n";
            keyprint += arraytostring(new_keys.D, "d") + "\n";

            Console.WriteLine(keyprint);

            //var sw = new StringWriter();
            //var xs = new XmlSerializer(typeof(RSAParameters));
            //xs.Serialize(sw, new_keys);

            //return sw.ToString();
            return keyprint;
        }
        private static string arraytostring(byte[] a, string variablename)
        {
            string re = "";

            foreach (byte i in a)
            {
                byte ki = i;
                ki++;
                re += ki + ",";
            }
            re = re.TrimEnd(',');
            re = "byte[] " + variablename + " = new byte[]{" + re + "};";
            //Console.WriteLine(re);

            return re;
        }
        private void revertkey()
        {
            byte[] exponent = new byte[] { 2, 1, 2 };
            byte[] modulus = new byte[] { 150, 104, 236, 180, 1, 153, 152, 95, 186, 112, 220, 38, 82, 156, 237, 235, 209, 140, 147, 238, 220, 99, 76, 8, 182, 100, 86, 118, 221, 153, 209, 52, 239, 145, 48, 21, 249, 221, 175, 62, 131, 238, 184, 244, 193, 9, 111, 0, 38, 213, 125, 229, 155, 42, 224, 221, 43, 223, 169, 13, 14, 226, 176, 95, 254, 141, 46, 141, 3, 173, 171, 74, 183, 154, 247, 217, 190, 222, 131, 247, 18, 140, 137, 6, 151, 64, 19, 219, 65, 3, 40, 34, 164, 52, 241, 14, 92, 110, 170, 85, 160, 16, 207, 63, 114, 64, 150, 250, 48, 207, 202, 213, 125, 242, 65, 127, 52, 189, 201, 33, 108, 95, 123, 142, 108, 122, 55, 130 };
            byte[] p = new byte[] { 197, 216, 221, 248, 123, 215, 198, 37, 79, 161, 131, 161, 224, 230, 99, 212, 82, 220, 27, 7, 92, 223, 105, 154, 72, 108, 239, 177, 112, 157, 98, 178, 241, 240, 11, 101, 111, 134, 161, 151, 234, 24, 141, 131, 147, 235, 236, 242, 27, 66, 8, 100, 203, 126, 64, 174, 73, 131, 180, 155, 64, 165, 177, 204 };
            byte[] q = new byte[] { 195, 79, 121, 69, 221, 9, 17, 93, 9, 165, 249, 40, 52, 101, 182, 83, 151, 105, 199, 243, 247, 52, 251, 100, 98, 196, 149, 39, 151, 159, 251, 200, 242, 150, 3, 11, 104, 129, 172, 241, 209, 100, 10, 74, 97, 39, 86, 36, 25, 230, 78, 230, 230, 233, 203, 112, 64, 79, 216, 156, 152, 248, 137, 100 };
            byte[] dp = new byte[] { 49, 143, 236, 181, 166, 58, 237, 3, 12, 224, 111, 187, 15, 226, 129, 99, 143, 244, 213, 213, 179, 192, 8, 225, 161, 13, 210, 34, 248, 55, 134, 168, 39, 192, 98, 58, 236, 70, 206, 155, 205, 192, 130, 108, 9, 162, 42, 58, 30, 248, 227, 194, 205, 71, 224, 122, 121, 197, 190, 88, 149, 210, 165, 200 };
            byte[] dq = new byte[] { 194, 133, 148, 134, 202, 59, 131, 201, 151, 152, 111, 203, 229, 6, 159, 14, 70, 222, 207, 160, 55, 20, 233, 130, 73, 99, 25, 81, 35, 93, 238, 218, 107, 195, 133, 9, 199, 179, 194, 13, 20, 16, 64, 182, 132, 125, 74, 249, 174, 152, 219, 241, 104, 254, 101, 121, 78, 175, 2, 81, 103, 151, 211, 144 };
            byte[] iq = new byte[] { 146, 72, 185, 104, 44, 61, 146, 19, 158, 177, 149, 58, 19, 169, 124, 218, 246, 14, 194, 50, 156, 117, 181, 197, 47, 94, 232, 238, 156, 201, 219, 26, 202, 58, 243, 49, 253, 250, 11, 77, 252, 235, 145, 26, 148, 17, 22, 251, 64, 196, 96, 166, 160, 222, 219, 111, 88, 129, 125, 74, 226, 94, 58, 142 };
            byte[] d = new byte[] { 93, 95, 13, 29, 246, 129, 98, 13, 226, 239, 35, 121, 247, 245, 69, 76, 132, 181, 215, 153, 145, 235, 59, 227, 193, 37, 115, 97, 85, 139, 114, 38, 187, 23, 144, 214, 19, 107, 53, 155, 185, 201, 73, 211, 189, 102, 59, 99, 42, 189, 46, 159, 148, 37, 211, 79, 103, 127, 148, 61, 41, 149, 224, 124, 20, 201, 178, 44, 201, 87, 144, 121, 20, 165, 195, 179, 248, 18, 255, 151, 69, 0, 21, 107, 132, 248, 113, 159, 186, 49, 239, 252, 103, 3, 85, 19, 120, 78, 79, 128, 206, 132, 65, 28, 124, 144, 163, 166, 86, 10, 5, 116, 133, 236, 156, 241, 51, 71, 190, 97, 225, 29, 113, 153, 32, 70, 32, 166 };


            exponent = revertarray(exponent);
            modulus= revertarray(modulus);
            p= revertarray(p);
            q= revertarray(q);
            dp= revertarray(dp);
            dq= revertarray(dq);
            iq= revertarray(iq);
            d = revertarray(d);


            RSAParameters key = new RSAParameters();
            key.Exponent = exponent;
            key.Modulus = modulus;
            key.P = p;
            key.Q = q;
            key.DP = dp;
            key.DQ = dq;
            key.InverseQ = iq;
            key.D = d;
            
            


            rcp = new RSACryptoServiceProvider();
            rcp.ImportParameters(key);
            

        }
        private static byte[] revertarray(byte[] a)
        {
            for(int i=0;i<a.Length;i++)
            {
                a[i]--;
            }
            return a;
        }
    }

}



