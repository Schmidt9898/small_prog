using System;

namespace kódelmélet
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rng = new Random();
            int PB = 50;
            Console.WriteLine("Hello World!");

            short[] bits = {1,1,0,1,0};
            int n = 100;
            short[] U = new short[n * bits.Length];
            int ulen = n * bits.Length;
            for (int i = 0; i < bits.Length; i++)
                for (int j = 0; j < n; j++)
                    {
                    U[n * i + j] = bits[i];
                    Console.Write(bits[i]+" ");
                    }
            Console.WriteLine();

            //add zaj
            short[] noise = new short[ulen];
            for(int i=0;i<noise.Length;i++)
            {
                noise[i] = (short) (rng.Next() % 100 >PB?0:1);
            }



            short[] V = new short[ulen];
            for (int i = 0; i < ulen; i++)
            {
                V[i] = (short)((U[i] + noise[i]) % 2);
                Console.Write(V[i] + " ");
            }
            Console.WriteLine();


            //döntés

            for (int i = 0; i < bits.Length; i++) {
                int bit=0;
                for (int j = 0; j < n; j++)
                {
                    bit += V[n * i + j]==0? -1 : 1;
                }
                bit = bit <= 0 ? 0 : 1;
                Console.Write(bit + " ");

            }
            Console.WriteLine();


        }
    }
}
