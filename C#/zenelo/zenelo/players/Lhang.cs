using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NAudio;
using NAudio.Wave;

namespace zenelo.players
{
  /// <summary>
  /// Egyszrüsétett Naudio lejátszó. Kell hozzá az Naudió könyvtár.
  /// </summary>
    class Lhang
    {       
        private WaveOutEvent hullam= null;
        private AudioFileReader File = null;
        private float volume = 0;
        
        /// <summary>
        /// Megnyit egy lejátszót.
        /// </summary>
        /// <param name="hangero">0-1.0 közötti szám. Nagyobb lehet de torzít.</param>
        public Lhang(float hangero)
        {
            volume = hangero;
        }
        /// <summary>
        /// Megnyit egy lejátszó eszközt és betölt egy zeneszámot valamely háttértárról.
        /// </summary>
        /// <param name="filename">Valid elérési útvonal.</param>
        /// <param name="hangero">0-1.0 közötti szám. Nagyobb lehet de torzít.</param>
        public Lhang(string filename,float hangero)
        {
            volume = hangero;
            load_this(filename);
        }
        

        public float Volume
        {
            set
            {
                this.volume = value;
                try
                {
                    hullam.Volume = this.volume;
                }catch(Exception)
                {
                    return;//semmi mert nem vagyunk rá kíváncsiak.
                }
            }
        }
        /// <summary>
        /// Betötlti a zeneszámot a háttértárról.
        /// </summary>
        /// <param name="file_">Elérési útvonal</param>
        public void load_this(string file_)
        {
            if (File == null && hullam==null)
            {
                File = new AudioFileReader(file_);
                hullam = new WaveOutEvent();
                hullam.Init(File);
                hullam.Volume = this.volume;
            }
            else if(File != null && hullam != null)
            {
                
                    hullam.Stop();
                    feltakarit();

                File = new AudioFileReader(file_);
                hullam = new WaveOutEvent();
                hullam.Init(File);
                hullam.Volume = this.volume;
            }
            else
            {
                throw new System.Exception("Valami a streamekkel nem kóser.");
            }
        }
        /// <summary>
        /// Lejátsza vagy folytatja a betöltött zenét. Ha nincs betöltve semmi akkor nincs hatása. 
        /// </summary>
        public void Play_something()
        {
            if(hullam==null)
            {
              //nem csinál semmit
            }else
            {
                hullam.Play();
            }
        }

        private void feltakarit()
        {
            hullam.Dispose();
            hullam = null;
            File.Dispose();
            File = null;
        }
        /// <summary>
        /// Csak megállítja a lejátszást.
        /// </summary>
        public void pause()
        {
            try
            {
                hullam.Pause();
            }
            catch (Exception)
            {
                //nem csinál semmit.
            }
        }
        /// <summary>
        /// Lekérdezi vagy beállítja a lejátszás helyét másodperc pontossággal.
        /// </summary>
        public int helyzetmp
        {
            get {try{return (int) File.Position/hullam.OutputWaveFormat.AverageBytesPerSecond;}catch (Exception) { return 0; } }
            set { try { File.Position = value * hullam.OutputWaveFormat.AverageBytesPerSecond; } catch (Exception) { } }
        }
        /// <summary>
        /// Lekérdezi vagy beállítja a lejátszás helyét byte pontossággal.
        /// </summary>
        public long helyzetlong
        {
            get { try { return File.Position; } catch (Exception) { return 0; } }
            set { try { File.Position = value; } catch (Exception) { } }
        }

        public long hoszlong
        {
            get { try { return File.Length; } catch (Exception) { return 0; } }
        }
        public long hoszmp
        {
            get { try { return File.Length / hullam.OutputWaveFormat.AverageBytesPerSecond; } catch (Exception) { return 0; } }
        }







    }
}
