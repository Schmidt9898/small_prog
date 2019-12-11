using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace mp3player
{
    class mp3
    {
        [DllImport("winmm.dll")]
        private static extern long mciSendString(string lpstrCommand, StringBuilder lpstrReturnString, int uReturnLength, int hwndCallback);

        public void open(string file)
        {
            string command = "close MyMp3";
            mciSendString(command, null, 0, 0);

            command = "open \"" + file + "\" type MPEGVideo alias MyMp3";
            mciSendString(command, null, 0, 0);
            command = "setaudio  MyMp3 volume to 200";
            mciSendString(command, null, 0, 0);
           // setaudio sounds\\character_select.mp3 volume to 500"
        }

        public void play()
        {
            string command = "play MyMp3";
           // play mysound from 1000 to 2000 notify
            mciSendString(command, null, 0, 0);
        }
        
        public void stop()
        {
            string command = "stop MyMp3";
            mciSendString(command, null, 0, 0);
            /*
            command = "close MyMp3";
            mciSendString(command, null, 0, 0);*/
        }
        public void hang(int ennyi)
        {
            string command = "setaudio MyMp3 volume to "+ennyi.ToString();
            mciSendString(command, null, 0, 0);
        }
        public long hosz()
        {
            StringBuilder sb = new StringBuilder(128);
            mciSendString("status MyMp3 length", sb, 128, 0);
            return ((long)Convert.ToUInt64(sb.ToString()));
            //return ((long)Convert.ToUInt64(""));
        }
        public long helyzet()
        {
            StringBuilder sb = new StringBuilder(128);
            mciSendString("status MyMp3 position", sb, 128, 0);
            try { return ((long)Convert.ToUInt64(sb.ToString())); } catch (Exception) { return 0; }
            
            //return ((long)Convert.ToUInt64(""));
        }
        public void helyzet(long pozicio)
        {
           // StringBuilder sb = new StringBuilder(128);
            mciSendString("seek MyMp3 to "+pozicio, null, 0, 0);
           // try { return ((long)Convert.ToUInt64(sb.ToString())); } catch (Exception) { return 0; }

            //return ((long)Convert.ToUInt64(""));
        }

    }
}
