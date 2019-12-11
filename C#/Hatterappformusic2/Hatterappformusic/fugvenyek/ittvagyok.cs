using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Hatterappformusic.fugvenyek
{
    
    
    class ittvagyok
    {
        UdpClient udp = null;
        IPEndPoint csoport = null;
        IPAddress myip = null;
        public ittvagyok(IPAddress myip_,int port)
        {
            myip = myip_;
            udp = new UdpClient();
            csoport = new IPEndPoint(IPAddress.Any, port);
        }
        public void holvagyok()
        {
            udp.Client.Bind(csoport);
            var from = new IPEndPoint(0,0);
            udp.EnableBroadcast = true;
            while (true)
            {
                if(udp.Available == 0)
                    Thread.Sleep(500);
                else
                {
                    byte[] uzenet=udp.Receive(ref from);
                    if(Encoding.UTF8.GetString(uzenet).Contains("WHERE"))
                    {
                        uzenet =Encoding.Default.GetBytes(myip.ToString());
                        
                            udp.Send(uzenet, uzenet.Length, from);
                        
                        
                    }
                    

                }
            }
            
        }
    }
}
