using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using static Hatterappformusic.fugvenyek.halozatevent;
using static Hatterappformusic.fugvenyek.ittvagyok;
using NAudio;
using NAudio.Wave;
using System.Diagnostics;
using System.Net;
using Hatterappformusic.fugvenyek;

namespace Hatterappformusic
{
    class Program
    {
        static ProcessStartInfo unmute = new ProcessStartInfo(@".\voice\nircmd.exe", "muteappvolume Hatterappformusic.exe 0");
        //vbsscript=Process.Start(unmute);
       
        static WaveOutEvent hullam = null;
        static List<AudioFileReader> Files = null;
        static Process vbsscript = null;
       
      //  AudioFileReader[] Files = null;
        static void Main(string[] args)
        {
            //try
            //{
            
            IPAddress[] ipaddress = Dns.GetHostAddresses(Dns.GetHostName());
            IPAddress ip = null;
            foreach(IPAddress i in ipaddress)
            {

                if(i.ToString().Contains("192.168."))
                {
                    ip = i;
                    break;
                }
            }

            //int index = ipaddress.Length / 2;
            fugvenyek.halozatevent a = new halozatevent(ip, 19982);
                a.datareceived += tcpcsomagerkezes;
            new Thread(new ittvagyok(ip,19983).holvagyok).Start();




            Files = new List<AudioFileReader>();
                Files.Add(new AudioFileReader(@"./voice/0.mp3"));
                Files.Add(new AudioFileReader(@"./voice/1.mp3"));
                Files.Add(new AudioFileReader(@"./voice/2.mp3"));
                Files.Add(new AudioFileReader(@"./voice/3.mp3"));
                Files.Add(new AudioFileReader(@"./voice/4.mp3"));
            /*while (true)
            {
                Thread.Sleep(1000);
            }*/
            Thread.CurrentThread.Join();

            //}
            //catch (Exception)
            //{
               
            //}
            
        }
        static void tcpcsomagerkezes(object sender, EventArgs e)
        {
            if (((datareceivedeventargs)e).msg.Contains("PING")){/*nem csinál semmit*/}
            else if(((datareceivedeventargs)e).msg.Contains("UNMUTE"))
            {
                (new Thread(() => {
                    Process.Start(unmute);
                })).Start();
            }
            else
            {
                if (hullam == null)
                {
                    hullam = new WaveOutEvent();
                    hullam.Volume = (float)0.9;
                }
                else
                {
                    hullam.Stop();
                    hullam.Dispose();
                    hullam = new WaveOutEvent();
                    hullam.Volume = (float)0.9;
                }
                string msg = ((datareceivedeventargs)e).msg;
                //Console.WriteLine(msg);
                int id;
                int.TryParse(msg, out id);
                switch (id)
                {
                    case 0:
                        Files[id].Position = 0;
                        hullam.Init(Files[id]);
                        hullam.Play();
                        break;
                    case 1:
                        Files[id].Position = 0;
                        hullam.Init(Files[id]);
                        hullam.Play();
                        break;
                    case 2:
                        Files[id].Position = 0;
                        hullam.Init(Files[id]);
                        hullam.Play();
                        break;
                    case 3:
                        Files[id].Position = 0;
                        hullam.Init(Files[id]);
                        hullam.Play();
                        break;
                    case 4:
                        Files[id].Position = 0;
                        hullam.Init(Files[id]);
                        hullam.Play();
                        break;
                    case 5:
                        if (vbsscript != null)
                            vbsscript.Dispose();
                        vbsscript = Process.Start(@".\voice\keres.vbs");
                        break;
                    case 6:
                        break;

                    default:

                        break;
                }

            }


        }
    }
}
