using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using System.Threading;

namespace serialports
{
    class Program
    {
        static void Main(string[] args)
        {
            SerialPort usb = null;
            for (int i=0;i<10;i++)
            {
               usb = new SerialPort("COM"+i, 9600);
                try
                {
                    usb.Open();
                    break;
                }catch(System.IO.IOException e)
                { Console.WriteLine(e.Message); }
                
            }
             usb.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler (delegate (Object o, SerialDataReceivedEventArgs a)
                {
                    Console.WriteLine(usb.ReadLine());
                });
            while (true)
            {
                Thread.Sleep(1000);
            }
        }
            
        }
    }

