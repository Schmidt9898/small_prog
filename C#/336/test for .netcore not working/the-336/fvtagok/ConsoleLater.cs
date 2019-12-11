using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace the_336.fvtagok
{
    class ConsoleLater
    {
        int millisecond;
        public ConsoleLater(int mil_)
        {
            millisecond = mil_;
        }
        public int Millisecond
        {
            get { return millisecond; }
            set { millisecond = value; }
        }
        public void WriteLine(string str)
        {
            foreach(char i in str)
            {
                Console.Write(i);
                Thread.Sleep(millisecond);
            }
            Console.Write("\n");

        }
        public void Write(string str)
        {
            foreach (char i in str)
            {
                Console.Write(i);
                Thread.Sleep(millisecond);
            }
            //Console.Write("\n");

        }
    }
}
