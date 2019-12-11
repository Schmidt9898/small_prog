using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace alkalmazasfigyelo
{
    class Program
    {
        static Process myProcess = null;
        static int husz=20;
        static void Main(string[] args)
        {
            myProcess = Process.Start(@".\Hatterappformusic.exe", "arguments");
            myProcess.EnableRaisingEvents = true;
            myProcess.Exited += Onexit;
#pragma warning disable CS0618 // Type or member is obsolete
            Thread.CurrentThread.Suspend();
#pragma warning restore CS0618 // Type or member is obsolete
        }
        static void Onexit(object sender, EventArgs e)
        {
            if (husz > 0)
            {
                husz--;
            }
            else
                System.Environment.Exit(1);
            myProcess.Dispose();
             myProcess = Process.Start(@".\Hatterappformusic.exe", "arguments");
            myProcess.EnableRaisingEvents = true;
            myProcess.Exited += Onexit;
        }

    }
}
