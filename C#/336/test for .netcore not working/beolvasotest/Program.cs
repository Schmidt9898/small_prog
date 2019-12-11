using myclass;
using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace beolvasotest
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("na próba");

            byte[] tomb = File.ReadAllBytes(@"C:\Users\Schmidt László\Desktop\file.aa");

            int h = tomb.GetLength(0);
            
            for (int i = 0; i < h; i++)
            {
                //Console.WriteLine(byteArray[i]);
                tomb[i] = unchecked((byte)(tomb[i] - 1));
                //Console.WriteLine(byteArray[i]);
                //Console.ReadKey();
            }
            Class1 b= (Class1) ByteArrayToObject( tomb);
            Console.WriteLine("beolvasva");
            Console.WriteLine(b.aa);
            Console.ReadKey();
        }
        private static Object ByteArrayToObject(byte[] arrBytes)
        {
            MemoryStream memStream = new MemoryStream();
            BinaryFormatter binForm = new BinaryFormatter();
            memStream.Write(arrBytes, 0, arrBytes.Length);
            memStream.Seek(0, SeekOrigin.Begin);
            Object obj = (Object)binForm.Deserialize(memStream);
            return obj;
        }
    }
}
