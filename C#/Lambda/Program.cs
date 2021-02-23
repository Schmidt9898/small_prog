using System;

namespace Lambda
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Func<int,int> square = x => x * x;
            Console.WriteLine(square(2));

            Func<int, int> q2 = (x) => { return x * x; };
            Console.WriteLine(q2(4));






            Console.ReadKey();
        }
    }
}
