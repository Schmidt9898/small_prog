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
using level;

namespace the_336
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public enum State {exit,next,back,start}
        public int place=0;
        public bool canwrite = true;
        public bool isenterwrite = true;
        Biglist warden = new Biglist();
        //Level loader = new Level();
        Level level = new Level();
        List<Level> paths = new List<Level>();
        public MainWindow()
        {
            int i = 1;
            while(true)
            {
                try
                {
                    paths.Add(level.Loadlevel(@".\maps\level" + i + ".map"));
                    i++;
                }
                catch(Exception)
                {
                    break;
                }
            }
            


            InitializeComponent();

            warden = warden.Loadlevel(@"C:\Lacika\programok\C#\336\the-336\testwar.po");
            //level = level.Loadlevel(@"C:\Users\Schmidt László\Desktop\testmap.map");
            //level = paths[0];
            place--;
            Levelhelper(State.next);
            
        //C: \Users\Schmidt László\Desktop\testmap.map
        }


        public void Levelhelper(State state)
        {
            switch (state)
            {
                case State.exit:
                    //todo
                    break;
                case State.next:
                    Writelineasync(txb_chat, level.Complement+"\n Nyomj entert a folytatáshoz.", 255, 0, 0);
                    ablak.KeyDown += enterstart;
                    isenterwrite = false;
                    
                    break;
                case State.start:
                    ablak.KeyDown -= enterstart;
                    place++;

                    if (paths.Count > place)
                    {
                        level = paths[place];
                        Writelineasync(txb_chat, level.Prolog, 255, 0, 0);
                    }
                    isenterwrite = true;
                    break;
                default:
                    break;
            }
        }
        public void enterstart(object sender, KeyEventArgs e)
        {
            if(e.Key==Key.Enter)
            Levelhelper(State.start);
        }
        

        public void Writelineasync(RichTextBox box, string text, byte r, byte g, byte b)
        {
            text += "\n";
            Paragraph item = (Paragraph)box.Document.Blocks.Last();
            Run inline = new Run()
            {
                Foreground = new SolidColorBrush(Color.FromRgb(r, g, b))
            };
            item.Inlines.Add(inline);
            

            var slowTask = Task.Factory.StartNew(() =>
            {
                canwrite = false;
            foreach (char c in text)
            {
                System.Windows.Application.Current.Dispatcher.Invoke(
                 DispatcherPriority.Normal,
                 (ThreadStart)delegate {
                     inline.Text += c;
                     box.ScrollToEnd();
                 });
                 System.Threading.Thread.Sleep(50);
            }
                canwrite = true;
            }
            
            );
            //box.ScrollToEnd();

        }

        public void Write(RichTextBox box, string text, byte r, byte g, byte b)
        {
            Run inline = new Run(text)
            {
                Foreground = new SolidColorBrush(Color.FromRgb(r, g, b))
            };
            Paragraph item = (Paragraph)box.Document.Blocks.Last();
            item.Inlines.Add(inline);
        }
        public void WriteLine(RichTextBox box, string text, byte r, byte g, byte b)
        {
            Run inline = new Run(text + "\n")
            {
                Foreground = new SolidColorBrush(Color.FromRgb(r, g, b))
            };
            Paragraph item = (Paragraph)box.Document.Blocks.Last();
            item.Inlines.Add(inline);
        }

        private void Txb_userwriter_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.Key==Key.Enter && canwrite && isenterwrite)
            {
                WriteLine(txb_chat, txb_userwriter.Text, 0, 255, 0);
                string ans = level.Questionnull(txb_userwriter.Text);
                if (ans == null)
                    ans = warden.Question(txb_userwriter.Text);
                Writelineasync(txb_chat, ans,255,0,0);
                txb_userwriter.Clear();
            }
            
        }

        private void Btn_code_Click(object sender, RoutedEventArgs e)
        {
            if(level.Ispassok(txb_code.Text))
            {
                Levelhelper(State.next);
            }
        }
    }
}
