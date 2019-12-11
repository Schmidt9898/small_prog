using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Text.RegularExpressions;
namespace udpkapcsolat
{
    /// <summary>
    /// Description of Class1.
    /// </summary>
    public class Udp
    {
        UdpClient udp = new UdpClient();
        IPEndPoint csoport = new IPEndPoint(IPAddress.Any, 12345);
        public Udp()
        {
            //udp.Client.Bind(csoport);
        }
        public void read()
        {
            string be = "";
            try
            {
                udp.Client.Bind(csoport);

                var from = new IPEndPoint(0, 0);
                while (true)
                {

                    byte[] begyutt = udp.Receive(ref from);
                    be = Encoding.UTF8.GetString(begyutt);
                    if (Regex.IsMatch(be, @"^" + Userdata.nev + ": "))
                        continue;
                    if (Regex.IsMatch(be, @"<-<[\w\s]*>->"))
                    {
                        try
                        {
                            new parancs().regparancs(be);
                        }
                        catch (Exception e) { MessageBox.Show(e.ToString()); }
                    }
                    else
                    {

                        communication.textbe = be;
                    }
                    Thread.Sleep(100);
                }
            }
            catch (SocketException e)
            {
                MessageBox.Show("A Port foglalt!\n" + e.ToString());
                communication.szabad = true;
            }
        }
        public void write()
        {
            byte[] uzenet = Encoding.UTF8.GetBytes(Userdata.nev + ": <-<REFRESH>->\n");
            udp.Send(uzenet, uzenet.Length, "255.255.255.255", 12345);
            while (true)
            {
                if (communication.disconnect)
                {
                    uzenet = Encoding.UTF8.GetBytes(Userdata.nev + ": <-<EXIT>->\n");
                    udp.Send(uzenet, uzenet.Length, "255.255.255.255", 12345);
                    communication.disconnect = false;
                }
                if (!Regex.IsMatch(communication.textki, @"^[\s]*$"))
                {
                    uzenet = Encoding.UTF8.GetBytes(Userdata.nev + ": " + communication.textki);
                    communication.textki = "";
                    //udpClient.Send(data, data.Length, "255.255.255.255", PORT);
                    udp.Send(uzenet, uzenet.Length, "255.255.255.255", 12345);
                }
                Thread.Sleep(100);
            }
        }
    }
}