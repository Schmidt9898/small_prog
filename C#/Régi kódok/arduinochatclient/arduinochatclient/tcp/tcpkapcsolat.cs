using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.IO;

namespace arduinochatclient
{
    class tcpkapcsolat
    {
        private string cel_cim;
        private int port;

        public tcpkapcsolat(string cel,int port_)
        {
            cel_cim = cel;
            port = port_;
            
        }
        string konverter(long l,int meret)
        {
            string valasz = "";
           // int[] tomb = new int[meret];
            int temp = 0;
            for(int i=0;i<meret;i++)
            {
                temp = (int) (l / (Math.Pow(10, (meret-1 - i))));
                l -=(long) (temp * (Math.Pow(10, (meret-1 - i))));
                valasz += temp;
            }

            return valasz; 
        }
        string uzenetformazas(string uzenet)
        {
            string formazott_uzenet = "|" + Userdata.nev + "|#" + uzenet + "#";


            return formazott_uzenet;
        }

        public void kuld(String uzenet)
        {
            try { TcpClient client = new TcpClient(cel_cim,port);
            //TcpClient client = new TcpClient(Userdata.cel_cim,Userdata.port);
            NetworkStream stream = client.GetStream();
                //Hozzá kell fűzni egy 0-t.
            byte[] msg = System.Text.Encoding.UTF8.GetBytes("0"+ uzenetformazas(uzenet));
					
					
      		 		stream.Write(msg, 0, msg.Length);
                client.Close();
                //communication.i += msg.Length;
            } catch (Exception) { }
        }
        public MemoryStream lekerdez()
        {
            var valasz = new MemoryStream();
            var writer = new StreamWriter(valasz);
            try
            {
                TcpClient client = new TcpClient(cel_cim,port);
                //TcpClient client = new TcpClient(Userdata.cel_cim,Userdata.port);
                NetworkStream stream = client.GetStream();
                byte[] msg = System.Text.Encoding.UTF8.GetBytes("1"+ konverter(communication.i,8));
                stream.Write(msg, 0, msg.Length);
                Byte[] bytes = new Byte[2048];
                string uzenet = "";

                while (client.Connected)
                {
                    
                    try
                    {
                        int i = stream.Read(bytes, 0, bytes.Length);
                        communication.i += i;
                        writer.Write(System.Text.Encoding.UTF8.GetString(bytes, 0, i));
                        
                        // return uzenet + " <--nem vége";
                        Thread.Sleep(200);
                    }
                    catch (Exception e) { client.Close(); }
                    if(!(client.Available>0))
                    {
                        client.Close();
                    }

                }
                client.Close();
                writer.Flush();
                return valasz;

            }
            catch (Exception) { return valasz; }

        }
    }
}
