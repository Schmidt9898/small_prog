using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace consoletcpwriter
{
    class Program
    {
        static void Main(string[] args)
        {
            TcpClient client = new TcpClient("192.168.1.150", 12345);
            NetworkStream stream = client.GetStream();
            while (true)
            {
                byte[] msg = System.Text.Encoding.UTF8.GetBytes(Console.ReadLine());
                stream.Write(msg, 0, msg.Length);
            }
        }
        }
}
