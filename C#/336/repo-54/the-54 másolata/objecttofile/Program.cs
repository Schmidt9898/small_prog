using myclasstest;
using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace objecttofile
{
    class Program
    {
        static Class1 a = null;
        static void Main(string[] args)
        {
            a = new Class1();
            //byte b = unchecked((byte)(253));
            //Console.Write(b.ToString());
            //Console.ReadKey();
            ByteArrayToFile(@"C:\Users\Schmidt László\Desktop\file.aa", ObjectToByteArray(a));

        }


        static byte[] ObjectToByteArray(object obj)
        {
            if (obj == null)
                return null;
            BinaryFormatter bf = new BinaryFormatter();

            using (MemoryStream ms = new MemoryStream())
            {

                bf.Serialize(ms, obj);
                return ms.ToArray();
            }
        }

        public static bool ByteArrayToFile(string fileName, byte[] byteArray)
        {
            int h = byteArray.GetLength(0);
            //Console.WriteLine(h);
            //Console.ReadKey();
            for (int i = 0; i < h; i++)
            {
                //Console.WriteLine(byteArray[i]);
                byteArray[i] = unchecked((byte)(byteArray[i] + 1));
                //Console.WriteLine(byteArray[i]);
                //Console.ReadKey();
            }


            try
            {
                using (var fs = new FileStream(fileName, FileMode.Create, FileAccess.Write))
                {
                    fs.Write(byteArray, 0, byteArray.Length);
                    return true;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception caught in process: {0}", ex);
                return false;
            }
        }
    }
}
