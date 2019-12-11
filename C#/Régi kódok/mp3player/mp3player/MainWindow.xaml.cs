using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
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

namespace mp3player
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public System.Windows.Threading.DispatcherTimer dispatcherTimer = new System.Windows.Threading.DispatcherTimer();
        mp3 player = new mp3();
        bool play = false;
        public MainWindow()
        {
            dispatcherTimer.Interval = new TimeSpan(0, 0, 0, 1, 0);
            dispatcherTimer.Tick += loop;
            dispatcherTimer.Start();
            InitializeComponent();
           // mp3 player = new mp3();
        }

        public void loop(object sender, EventArgs e)
        {
            timerem.Value = player.helyzet();
            if (timerem.Value == timerem.Maximum)
            {
                player.stop();
                play = false;
            }
                
        }
        private void btn_Play_Click(object sender, RoutedEventArgs e)
        {
            player.play();
            play = true;
        }

        private void btn_keres_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog()==true)
            {
                tb_file.Text = openFileDialog.FileName;
                
                player.open(tb_file.Text);
                timerem.Maximum = player.hosz();
                // MessageBox.Show(player.hosz().ToString());
            }
                
        }

        private void btn_stop_Click(object sender, RoutedEventArgs e)
        {
            player.stop();
            play = false;
        }

        private void kapkan_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            if(kapkan.IsFocused)
            player.hang((int) kapkan.Value);
            
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            player.helyzet(10000);
        }

        

        private void timerem_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            if (timerem.IsFocused)
            {
                if(play)
                {
                    player.helyzet((long)timerem.Value);
                    player.play();
                }else
                {
                    player.helyzet((long)timerem.Value);
                }
               
            }
        }

        private void Window_Drop(object sender, DragEventArgs e)
        {
            // string a;
            string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);
            tb_file.Text = files[0];

            player.open(tb_file.Text);
            timerem.Maximum = player.hosz();
            //MessageBox.Show(files[0] );
        }

      

        private void doboz_Drop(object sender, DragEventArgs e)
        {
            string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);
            foreach (string file in files)
            {
                ListBoxItem item = new ListBoxItem();
                item.Content = file;
                doboz.Items.Add(item);
            }
        }
    }
}
