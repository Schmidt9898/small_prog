using System;

namespace minta
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Helo ez egy kis segítség...\n");
            Console.Write("Így írsz egy sorba lezárás nélkül   ");
            Console.WriteLine("ez meg hagy egy \\n -t a végén.");

            Console.WriteLine("változók...");
          //tipus   neve  = érték
            int       i   =  0;
            double d = 1.0/2.0;
            bool feltetel = true;
            char c = 'A';
            string str = "Ez valamilyen szöveg.";

            Console.WriteLine(i);
            Console.WriteLine(d);
            Console.WriteLine(feltetel);
            Console.WriteLine(c);
            Console.WriteLine(str);

            Console.WriteLine("egyszerű műveletek...");

            i++;i--;i += 10;
            d++;d/= 100;d = d * 10;
            feltetel = !feltetel;
            feltetel = i < d || i>d && 1==1 && 1!=10;
            int[] tomb = { 1, 12, 212, 341, 436, 73, 763, 54 };

            c = 'a';
            str = str + str;
            str += c;
            str = str.ToUpper();

            Console.WriteLine(i);
            Console.WriteLine(d);
            Console.WriteLine(feltetel);
            Console.WriteLine(c);
            Console.WriteLine(str);

            //feltételes értékadás
          //minek =(mikor) ?  ha igaz : ha hamis;
            i = (feltetel) ? 5 : 10;


            if (feltetel)
            {
                Console.WriteLine("feltétel igaz...");
            }
            else
            {
                Console.WriteLine("feltétel hamis...");
            }



            if(feltetel)
            {
                Console.WriteLine("feltétel igaz...");
            }
            else if(i==1)
            {
                Console.WriteLine("i=1 igaz...");
            }
            else
            {
                Console.WriteLine("feltétel hamis és i nem 1...");
            }

            Console.WriteLine("Ciklusok");

            i = 0;
            while (i < 10)
            {
                Console.WriteLine("iteráció");
                i++;
            }
            Console.WriteLine("vagy");
            i = 0;
            while (true)
            {
                Console.WriteLine("iteráció");
                i++;
                if (i > 10)
                    break;
            }
            //break = itt kilép a ciklusból 
            //continue = folytatja a következő iterációval

            for (int iterator = 0; iterator < 5; iterator++)
            {
                Console.WriteLine("iteráció"+iterator);
            }
            Console.WriteLine("vagy");
            for (i = 0; i < 5; i++)
            {
                Console.WriteLine("i iteráció"+i);
            }

            Console.WriteLine("foreach");
            foreach(int elem in tomb)
            {
                Console.WriteLine(elem);
            }
            Console.WriteLine("extra switch");
            str = "alma";
            switch(str)
            {
                case "alma": Console.WriteLine("alma a switchben"); break;
                default: Console.WriteLine("ha nincs felsorolt eset");break;
            }





            Console.ReadKey();
        }
    }
}
