using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace proglecke1
{
    class Program
    {
        static void Main(string[] args)
        {
            //indul
            Console.WriteLine("Helo világ");
            /*
            int egesz = (int)2.6;
            double tört = 2.6;

            string str="xpeke";
            string str2 = " egy meleg.  ez egy másik fasz";*/
            /*
            int a=10, b=5, c=0;

            c = a + b;
            c = 0;
            c = c+1;
            c += 1;
            c++;
            c -=- 1;
            *//*
            bool c,a=true,b=true;

            c = !a;
            c = !(!a && !b);*/
              /*
               * a || b  c
               * 0    0  0
               * 0    1  1
               * 1    0  1
               * 1    1  1
               * 
               * a && b  c
               * 0    0  0
               * 0    1  0
               * 1    0  0
               * 1    1  1
               */
              /*
             c = false;
             b = false;


             if (c)
             {
                 Console.WriteLine("c az igaz");
             }else if(b)
             {
                 Console.WriteLine("c az nem igaz de b az");
             }else
             {
                 Console.WriteLine("semmi nem igaz");
             }*/
              /*
              int i = 0;
              while (i < 5)
              {
                  continue;
                  Console.WriteLine("valami");
                  i+*;

              }*/
              /*
              for (int i=0;i<5;i++)
              {

                  Console.WriteLine("valami");

              }
              */
              /*
              for(int i=0;i<=100;i++)
              {
                  string sor = "";


                  if ((i % 3) == 0)
                  {
                      sor += "Fiz";
                  }
                  if ((i % 4) == 0)
                  {
                      sor += "Buzz";
                  }

                  if(sor=="")
                  {
                      sor += i;
                  }

                  Console.Write(sor+" \n");


              }*/





            int a, b, c;
            int.TryParse(Console.ReadLine(),out a);
            int.TryParse(Console.ReadLine(), out b);
            int.TryParse(Console.ReadLine(), out c);

            //(-b+gyök(b^2-4ac))/2a
            //(-b-gyök(b^2-4ac))/2a

            double x1, x2;
            x1 = (-b + Math.Sqrt((b * b - 4 * a * c))) / (2 * a);
            x2 = (-b - Math.Sqrt((b * b - 4 * a * c))) / (2 * a);

            Console.WriteLine("A megoldás x1=" + x1 + " X2=" + x2);














            //Console.WriteLine(c);
            //Console.Write(str+str2);

            Console.ReadKey();
            //végetér
        }
    }
}
