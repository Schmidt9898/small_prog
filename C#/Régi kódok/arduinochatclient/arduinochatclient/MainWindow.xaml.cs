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

namespace arduinochatclient
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        tcpkapcsolat arduino=null;
        public System.Windows.Threading.DispatcherTimer dispatcherTimer = new System.Windows.Threading.DispatcherTimer();
        public MainWindow()
        {
            arduino = new tcpkapcsolat("81.182.180.54", 12345);
            //arduino = new tcpkapcsolat("192.168.1.123", 12345);
            dispatcherTimer.Interval = new TimeSpan(0, 0, 0, 1, 0);
            dispatcherTimer.Tick += loop;
            dispatcherTimer.Start();
            
            InitializeComponent();
            btn_fogad.IsEnabled = false;

        }
        public void loop(object sender, EventArgs e)
        {
            if (communication.szabad) { 
            (new Thread(() => {
                communication.szalak++;
                lock (communication.objektum)
                {
                    communication.szabad = false;
                    communication.sorok= new soregyseg_converter().to(arduino.lekerdez());
                    //communication.textbe = arduino.lekerdez();
                    communication.szabad = true;
                }
                communication.szalak--;
            })).Start();
        }
            lock (communication.objektum) {
                if (communication.sorok.Count>0) {
                    for(int i=0;i< communication.sorok.Count; i++)
                    {
                        TextBox dynamicLabel = new TextBox();
                        dynamicLabel.Name = "NewLabel";
                        dynamicLabel.Text = communication.sorok[i].szoveg;
                        dynamicLabel.TextWrapping = TextWrapping.Wrap;
                        dynamicLabel.Margin = new Thickness(0, 5, 0, 0);
                        dynamicLabel.HorizontalAlignment = HorizontalAlignment.Left;
                        dynamicLabel.MaxWidth = 300;
                        dynamicLabel.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("RED"));
                        dynamicLabel.Background = new SolidColorBrush((Color)ColorConverter.ConvertFromString("BLACK"));
                        grid_tabla.Children.Add(dynamicLabel);

                    }

//                    communication.textbe = "";
                    if (!grid_tabla.IsFocused)
                {
                    csuszka.ScrollToEnd();
                }

                }
                
               
            }
            lbl_nev.Content = communication.szalak;
        }

        private void btn_kuld_Click(object sender, RoutedEventArgs e)
        {
            arduino.kuld(tb_uzenet.Text);
            tb_uzenet.Text = "";
        }

        private void btn_fogad_Click(object sender, RoutedEventArgs e)
        {
         //   tb_tabla.Text+=arduino.lekerdez();
        }

        private void tb_uzenet_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.Key== System.Windows.Input.Key.Enter)
            {
                arduino.kuld(tb_uzenet.Text);
                
                tb_uzenet.Text = "";
            }
        }

        private void tb_nev_KeyUp(object sender, KeyEventArgs e)
        {
            if(e.Key==System.Windows.Input.Key.Enter)
            {
                Userdata.nev = tb_nev.Text;
                tb_uzenet.Focus();
            }
            
        }
    }
}
