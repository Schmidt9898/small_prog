using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
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

namespace zenelejatszo
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary


    public partial class MainWindow : Window
    {
        public System.Windows.Threading.DispatcherTimer dispatcherTimer = new System.Windows.Threading.DispatcherTimer();
        List<string> lista;
        bool lejatszhat = false;
        bool loop_l = true;
        mp3string player = new mp3string();
        public MainWindow()
        {
            lista = new List<string>();
            dispatcherTimer.Interval = new TimeSpan(0, 0, 0, 1, 0);
            dispatcherTimer.Tick += loop;
            dispatcherTimer.Start();
            InitializeComponent();
        }
        public void loop(object sender, EventArgs e)
        {
        if(loop_l)
            {
                tekero.Value=player.get_helyzet();
            }

        }

        private void kilep_Click(object sender, RoutedEventArgs e)
        {
            System.Windows.Application.Current.Shutdown();
        }

        private void DockPanel_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Left)
                this.DragMove();
        }

        private void play_button_Click(object sender, RoutedEventArgs e)
        {
            if (lejatszhat)
            {
                player.stop();
                play_button.Content = "Play";
                lejatszhat = false;
            }
            else
            {
            player.set_volume((int)hangero.Value);
            player.play();
                play_button.Content = "Stop";
                lejatszhat = true;

            }
            
        }

        private void btn_add_Click(object sender, RoutedEventArgs e)
        {

            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == true)
            {
                ListBoxItem item = new ListBoxItem();
                string cim= openFileDialog.FileName;
                item.Content = Regex.Replace(cim, @"\w*\:\\(.)*\\", "");
                if (lista.Count == 0)
                {
                    lista.Add(cim);
                    Lista_toboz.Items.Add(item);
                    Lista_toboz.SelectedIndex=0;
                    player.open(cim);
                    tekero.Maximum = player.get_hosz();
                    most_szol_cim.Content = item.Content;
                }
                else
                {
                    lista.Add(cim);
                    Lista_toboz.Items.Add(item);
                }
                
                
                //player.open(tb_file.Text);
                //timerem.Maximum = player.hosz();
                // MessageBox.Show(player.hosz().ToString());
            }
        }

        private void Lista_toboz_PreviewMouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            if(!((ListBoxItem)Lista_toboz.SelectedItem).Content.Equals(most_szol_cim))
            {
                player.close();
                 player.open(lista[Lista_toboz.SelectedIndex]);
                tekero.Maximum = player.get_hosz();
                most_szol_cim.Content = ((ListBoxItem)Lista_toboz.SelectedItem).Content;

                if(lejatszhat)
                {
                    player.set_volume((int)hangero.Value);
                    player.play();
                }
            }
           

        }
      

        private void Lista_toboz_Drop(object sender, DragEventArgs e)
        {
            string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);
            ListBoxItem item;
            string cim = "";
            foreach (string file in files)
            {
                cim = file;
                item = new ListBoxItem();
                item.Content = Regex.Replace(cim, @"\w*\:\\(.)*\\", "");
                if (lista.Count == 0)
                {
                    lista.Add(cim);
                    Lista_toboz.Items.Add(item);
                    Lista_toboz.SelectedIndex = 0;
                    player.open(cim);
                    tekero.Maximum = player.get_hosz();
                    most_szol_cim.Content = item.Content;
                }
                else
                {
                    lista.Add(cim);
                    Lista_toboz.Items.Add(item);
                }

            }
        }

     
        private void hangero_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
        if(hangero.IsFocused)
            {
                player.set_volume((int)hangero.Value);
                
            }
        }

        private void tekero_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            // dispatcherTimer.Tick -= loop;
            loop_l = false;
        }

        private void tekero_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            player.set_helyzet((int)tekero.Value);
            if(lejatszhat)
            {
                player.play();
            }
            loop_l = true;
           // dispatcherTimer.Tick += loop;
        }

        private void elore_Click(object sender, RoutedEventArgs e)
        {

            if(Lista_toboz.SelectedIndex+1!=Lista_toboz.Items.Count)
            {
                Lista_toboz.SelectedIndex++;
                

            }
            else
            {
                Lista_toboz.SelectedIndex = 0;
            }
            player.close();
            player.open(lista[Lista_toboz.SelectedIndex]);
            tekero.Maximum = player.get_hosz();
            most_szol_cim.Content = ((ListBoxItem)Lista_toboz.SelectedItem).Content;
            if (lejatszhat)
            {
                player.set_volume((int)hangero.Value);
                player.play();
            }
            }

        private void vissza_Click(object sender, RoutedEventArgs e)
        {
            if (Lista_toboz.SelectedIndex  !=0)
            {
                Lista_toboz.SelectedIndex--;


            }
            else
            {
                Lista_toboz.SelectedIndex = Lista_toboz.Items.Count-1;
            }
            player.close();
            player.open(lista[Lista_toboz.SelectedIndex]);
            tekero.Maximum = player.get_hosz();
            most_szol_cim.Content = ((ListBoxItem)Lista_toboz.SelectedItem).Content;
            if (lejatszhat)
            {
                player.set_volume((int)hangero.Value);
                player.play();
            }

        }

        private void btn_delete_Click(object sender, RoutedEventArgs e)
        {
            if (Lista_toboz.Items.Count > 0)
            {
                int idx = Lista_toboz.SelectedIndex;
                lista.RemoveAt(idx);
                Lista_toboz.Items.RemoveAt(idx);
                //Lista_toboz.SelectedIndex++;
                if (idx != Lista_toboz.Items.Count)
                {
                    Lista_toboz.SelectedIndex=idx;


                }
                else
                {
                    Lista_toboz.SelectedIndex = 0;
                }
            }
        }

        private void btn_clear_all_Click(object sender, RoutedEventArgs e)
        {
            Lista_toboz.Items.Clear();
            lista.Clear();
        }
    }
}
