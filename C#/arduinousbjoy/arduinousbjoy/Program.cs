using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Henooh;
using System.Text.RegularExpressions;
using InputManager;


namespace arduinousbjoy
{
    class Program
    {
        // const UInt32 WM_KEYDOWN = 0x0100;
        // const int VK_F5 = 0x75 ;

        // [System.Runtime.InteropServices.DllImport("user32.dll")]
        // static extern bool PostMessage(IntPtr hWnd, UInt32 Msg, int wParam, int lParam);

        // [STAThread]
        static void Main(string[] args)
        {
            String msg = null;
            SerialPort usb = null;
            while (true)
            {
                for (int i = 0; i < 10; i++)
                {
                    usb = new SerialPort("COM" + i, 9600);
                    try
                    {
                        usb.Open();
                        break;
                    }
                    catch (System.IO.IOException e)
                    { Console.WriteLine(e.Message); }

                }



                Henooh.DeviceEmulator.KeyboardController controller = new Henooh.DeviceEmulator.KeyboardController();
                while (usb.IsOpen)
                {

                    while (usb.BytesToRead > 0)
                    {
                        msg = usb.ReadLine();
                        Console.WriteLine(msg);
                        Regex regex = new Regex(@"( : )");//" : "
                        String[] values = regex.Split(msg);
                        bool value = values[2].Contains("1");
                        //int pin = int.Parse(values[0]);

                        switch(values[0])
                        {
                            case "L1" :
                                if (value)
                                    //controller.Press(Henooh.DeviceEmulator.Native.VirtualKeyCode.F13, new TimeSpan(0, 0, 0));
                                controller.Press(Henooh.DeviceEmulator.Native.VirtualKeyCode.VK_L, new TimeSpan(0, 0, 0));
                                //controller.Alt(Henooh.DeviceEmulator.Native.VirtualKeyCode.NUMPAD4);

                                else
                                    controller.Press(Henooh.DeviceEmulator.Native.VirtualKeyCode.VK_L, new TimeSpan(0, 0, 0));
                                break;
                            case "L2":
                                if (value)
                                    controller.Down(Henooh.DeviceEmulator.Native.VirtualKeyCode.VK_K);
                                else
                                    controller.Up(Henooh.DeviceEmulator.Native.VirtualKeyCode.VK_K);
                                break;
                            case "R2":
                                if (value)
                                    controller.Press(Henooh.DeviceEmulator.Native.VirtualKeyCode.VK_U,new TimeSpan(0,0,0));
                                else
                                    controller.Press(Henooh.DeviceEmulator.Native.VirtualKeyCode.VK_U, new TimeSpan(0, 0, 0));
                                break;
                            case "R1":
                                if (value)
                                    controller.Press(Henooh.DeviceEmulator.Native.VirtualKeyCode.NUMPAD4, new TimeSpan(0, 0, 0));
                                else
                                    controller.Press(Henooh.DeviceEmulator.Native.VirtualKeyCode.NUMPAD4, new TimeSpan(0, 0, 0));
                                break;
                            case "RE":
                                if (value)
                                    controller.Down(Henooh.DeviceEmulator.Native.VirtualKeyCode.NUMPAD5);
                                else
                                    controller.Up(Henooh.DeviceEmulator.Native.VirtualKeyCode.NUMPAD5);
                                break;
                            case "RT":
                               // Console.WriteLine(msg);
                                if (value)
                                    controller.Press(Henooh.DeviceEmulator.Native.VirtualKeyCode.VK_N, new TimeSpan(0, 0, 0));
                                else
                                    controller.Alt(Henooh.DeviceEmulator.Native.VirtualKeyCode.VK_N);
                                break;
                            default:
                                break;
                        }
                        //controller.Down(Henooh.DeviceEmulator.Native.VirtualKeyCode.F13);
                        //controller.Press(Henooh.DeviceEmulator.Native.VirtualKeyCode.F13, new TimeSpan(0, 0, 0));
                    }
                    Thread.Sleep(10);

                }
                Thread.Sleep(500);
            }

        }
        
    }
}
           