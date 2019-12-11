using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
using NAudio;
using NAudio.Wave;
using zenelo.players;
using zenelo.converter;
using System.Text.RegularExpressions;

namespace zenelo
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private DispatcherTimer dispatcherTimer;
        Lhang lejatszo = null;
        bool lejatszhat = false;
        bool l_loop = true;
        
        string hoszstring = "00:00";
        timetostringconverter timeconv;
        

        public MainWindow()
        {
            InitializeComponent();

            dispatcherTimer = new System.Windows.Threading.DispatcherTimer();
            dispatcherTimer.Tick += loop;
            dispatcherTimer.Interval = new TimeSpan(0,0,0,0,100);
            dispatcherTimer.Start();
            /*
            string filename1 = @"C:\Users\Schmidt László\Music\Alexander Jean - Waiting For You.mp3";
            string filename2 = @"C:\Users\Schmidt László\Music\Intim Torna Illegál - Örökké.mp3";
            string filename3 = @"C:\Users\Schmidt László\Music\endgame_athena_by_yhrite-d8hz9cx.jpg";
            double Hangero = 0.5;
            bool lejatszhat = false;*/
            csuszka_hangero.Value = 0.5;
            if(parameter.args.Length>0)
                lejatszo = new Lhang(parameter.args[0],(float)csuszka_hangero.Value);
            else
            lejatszo = new Lhang((float)csuszka_hangero.Value);
            timeconv =new timetostringconverter();
         
            
          //  Thread.Sleep(5000);
            csuszka.Maximum = lejatszo.hoszmp;
            lbl_cim.Content = lejatszo.hoszmp.ToString();
            // lejatszo.Play_something();
            //  lejatszo.helyzetmp = 53;
            hoszstring = timeconv.timetostring(lejatszo.hoszmp);
        }
        void loop(object sender,EventArgs e)
        {
            if(l_loop)
            csuszka.Value = lejatszo.helyzetmp;

            lbl_ido.Content =timeconv.timetostring(csuszka.Value)+ "/"+hoszstring;
        }
        /*talán viszateszem egyszer.
        private void ablak_MouseDown(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Left)
                this.DragMove();
        }
        */
        private void exit_Click(object sender, RoutedEventArgs e)
        {
            System.Windows.Application.Current.Shutdown();
        }

        private void back_Click(object sender, RoutedEventArgs e)
        {
            //TODO
        }

        private void start_stop_Click(object sender, RoutedEventArgs e)
        {
            lejatszhat = !lejatszhat;
            if (lejatszhat)
                lejatszo.Play_something();
            else
                lejatszo.pause();
        }

        private void forward_Click(object sender, RoutedEventArgs e)
        {
            //TODO
        }

        private void elsosor_MouseDown(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Left)
                this.DragMove();
        }

        private void csuszka_hangero_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            if(lejatszo!=null)
            lejatszo.Volume = (float)csuszka_hangero.Value;
        }

        private void csuszka_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            l_loop = false;
        }

        private void csuszka_PreviewMouseUp(object sender, MouseButtonEventArgs e)
        {
            lejatszo.helyzetmp = (int)csuszka.Value;
            l_loop = true;
        }
        //Nem tudom még 
        private void elsosor_Drop(object sender, DragEventArgs e)
        {
            maindrop(sender, e);
        }

        private void csuszka_Drop(object sender, DragEventArgs e)
        {
            maindrop(sender, e);
        }

        private void harmadiksor_Drop(object sender, DragEventArgs e)
        {
            maindrop(sender, e);
        }
        public void maindrop(object sender, DragEventArgs e)
        {
            try { string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);
            lejatszo.load_this(files[0]);
            csuszka.Maximum = lejatszo.hoszmp;
            hoszstring=timeconv.timetostring(lejatszo.hoszmp);
            lbl_cim.Content= Regex.Replace(files[0], @"\w*\:\\(.)*\\", "");
            if (lejatszhat)
                lejatszo.Play_something();
            } catch (Exception) {
                lbl_cim.Content = "Nem ismert kiterjesztés!";
            }
            
        }

        private void lejatszas_lista_Drop(object sender, DragEventArgs e)
        {

        }
    }
}
