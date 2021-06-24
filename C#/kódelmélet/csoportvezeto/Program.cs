using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace csoportvezeto
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine((uint)Math.Pow(11, 10) % 13);
            int q = 5,n=4,k=2,alpha = 3;
            int[,] G = new int[k, n];
            int[,] H = new int[n - k, n];
            int[] s = new int[n-k];
            int[] e = {0,0,3,0};
            int[] u = {4,3};
            int[] c = new int[n];
            int[] v = new int[n];
            Console.WriteLine("G matrix");
            for (int i=0;i<k;i++)
            {
                for (int j = 0; j < n; j++)
                {
                    G[i, j] = (int)Math.Pow((double)alpha, (double)(i * j)) % q;
                    Console.Write(G[i,j]+" ");
                }
            Console.WriteLine();
            }


            
            Console.WriteLine("H matrix");
            for (int i = 0; i < n-k; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    H[i, j] = (int) ((uint)Math.Pow(alpha,((i+1) * j)) % q);
                    Console.Write(H[i, j] + " ");
                }
                Console.WriteLine();
            }
            Console.WriteLine("C vector");
            for (int j = 0; j < n; j++)
                {
                int sum = 0;
                for (int i = 0; i < k; i++)
                {
                    sum += (G[i, j] * u[i]) % q;
                    
                    
                }
                sum %= q;
                c[j] = sum;
                Console.Write(sum + " ");
            }
                Console.WriteLine();
            Console.WriteLine("V vector");
            for (int i = 0; i < n; i++)
            {
                v[i] = (c[i] + e[i]) % q;
                Console.Write(v[i] + " ");
            }
            Console.WriteLine();

            Console.WriteLine("S vector");
            for (int i = 0; i < n - k; i++)
            {
                int sum = 0;
                for (int j = 0; j < n; j++)
                {
                    sum += (H[i, j] * v[j]) % q;
                }
                sum %= q;
                s[i] = sum;
                Console.Write(sum + " ");
            }
                Console.WriteLine();

            

            int[] X = {4,-1};
            int d = X.Length;
            for(int i=0;i<q;i++)
            {
                int sum = 0;
                for (int j = 0; j < d; j++)
                    sum += (X[j] * (int)Math.Pow(i, d - j-1))%q;
                sum %= q;
                Console.Write(sum + " ");
            }



            Console.ReadKey();
        
        
        
        
        }


       /* static int[][] cs_elem(int n,int q)
        {
            List<int[]> kodok = new List<int[]>();
            int[] e = new int[n];
            for (int i = 0; i < n; i++)
                for (int j=0;j<i;j++)
                    for (int k = 0; k < q; k++)
                    {
                        e[j] = k;
                        kodok.Add(e);
                        Console.WriteLine(e[0]+" "+ e[1] + " " + e[2] + " " + e[3] + " " + e[4] + " " + e[5]);
                    }
            Console.WriteLine(kodok.Count);
            return kodok.ToArray();

        }*/


    }
}
