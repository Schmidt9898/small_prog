using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace zenelejatszo
{
    class mp3string
    {
        [DllImport("winmm.dll")]
        private static extern long mciSendString(string lpstrCommand, StringBuilder lpstrReturnString, int uReturnLength, int hwndCallback);
        public void open(string file)
        {
            /*string command = "close mp3";
            mciSendString(command, null, 0, 0);*/

            string command = "open \"" + file + "\" type MPEGVideo alias mp3";
            mciSendString(command, null, 0, 0);
          //  command = "setaudio  mp3 volume to 200";
           // mciSendString(command, null, 0, 0);
            // setaudio sounds\\character_select.mp3 volume to 500"
        }
        public void play()
        {
            string command = "play mp3";
            // play mysound from 1000 to 2000 notify
            mciSendString(command, null, 0, 0);
        }
        public void stop()
        {
            string command = "stop mp3";
            mciSendString(command, null, 0, 0);
            /*
            command = "close mp3";
            mciSendString(command, null, 0, 0);*/
        }
        public void close()
        {
            string command = "close mp3";
            mciSendString(command, null, 0, 0);
        }
        public void set_volume(int volume_to)
        {
            string command = "setaudio mp3 volume to " + volume_to.ToString();
            mciSendString(command, null, 0, 0);
        }
        public long get_hosz()
        {
            StringBuilder sb = new StringBuilder(128);
            mciSendString("status mp3 length", sb, 128, 0);
            try
            {
                return ((long)Convert.ToUInt64(sb.ToString()));
            }catch(Exception)
            {
                return 0;
            } 
        }
        public long get_helyzet()
        {
            StringBuilder sb = new StringBuilder(128);
            mciSendString("status mp3 position", sb, 128, 0);
            try { return ((long)Convert.ToUInt64(sb.ToString())); } catch (Exception) { return 0; }
            
        }
        public void set_helyzet(long pozicio)
        {
            // StringBuilder sb = new StringBuilder(128);
            mciSendString("seek mp3 to " + pozicio, null, 0, 0);
            // try { return ((long)Convert.ToUInt64(sb.ToString())); } catch (Exception) { return 0; }

            //return ((long)Convert.ToUInt64(""));
        }




    }
}
