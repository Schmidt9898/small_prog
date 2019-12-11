using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Hatterappformusic.fugvenyek
{
    class halozatevent
    {
        TcpListener fül = null;
        TcpClient client = null;
        Thread olvaso = null;
       IPAddress cim;
        int port;


        public event EventHandler datareceived;

        protected virtual void Ondatareceived(EventArgs e)
        {
            EventHandler handler = datareceived;
            if (handler != null)
            {
                handler(this, e);
            }
        }
        public class datareceivedeventargs : EventArgs
        {
            public string msg { get; set; }

        }
       public halozatevent(IPAddress cim,int port)
        {
            try
            {
                this.cim = cim;
                this.port = port;
                Thread a = new Thread(TCRListening);
                a.IsBackground = true;
                a.Start();
            }
            catch(Exception)
            {

            }
            
        }
      
        /*private void asd()
        {
            Thread.Sleep(2000);
            datareceivedeventargs e = new datareceivedeventargs();
            e.msg = "üzenet egy másik szálról";
           for (int i=0;i<10;i++)
            {
                datareceived(this,e);
            }
        }*/
        private void TCRListening()
        {
            try
            {
            if (fül == null)
            {
                fül = new TcpListener(cim, port);
                fül.Start();
            }
            while (true)
            {
                client = fül.AcceptTcpClient();
                if (olvaso != null)
                {
                    olvaso.Abort();
                }
                olvaso = new Thread(TCPReading);
                olvaso.IsBackground = true;
                olvaso.Start();
            }
            }catch(Exception)
            {

            }
            
            
        }
        private void TCPReading()
        {
            try
            {
                 Byte[] bytes = new Byte[1024];
            NetworkStream streamn = client.GetStream();
                StreamReader stream = new StreamReader(streamn);
               // StreamWriter iro = new StreamWriter(streamn);
            int i;
            datareceivedeventargs e = new datareceivedeventargs();
            while (true)
            {
                while(client.Available>0)
                {

                        e.msg = stream.ReadLine();
                    //for (int j = 0; i < 100; i++)
                    //{
                        datareceived(this, e);
                        //}
                      
                        Console.WriteLine(e.msg);
                }
                Thread.Sleep(50);
            }
            }catch(Exception e)
            {
                Console.WriteLine(e.ToString());
            }
           
           

            }
        }





    }



