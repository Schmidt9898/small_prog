using System;
using System.Collections.Generic;
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
using level;

namespace Levelbuilder
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Btn_new_Click(object sender, RoutedEventArgs e)
        {
            txb_answer.Text = "answer";
            txb_question.Text = "question";
            txb_prolog.Text = "prolog";
            txb_complement.Text = "complement";
            lb_answer.Items.Clear();
            lb_question.Items.Clear();
            random.Items.Clear();
        }

        private void Btn_open_Click(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.OpenFileDialog openFileDialog = new Microsoft.Win32.OpenFileDialog();
            if (openFileDialog.ShowDialog() == true)
            {

            
                txb_path.Text=openFileDialog.FileName;
            Level temp = new Level();
            temp = temp.Loadlevel(openFileDialog.FileName);
            List<string> fill;
            ListBoxItem item;
            fill = temp.setQuestion;
            lb_question.Items.Clear();
            foreach (string q in fill)
            {
                item = new ListBoxItem();
                item.Content = q;
                lb_question.Items.Add(item);
            }

            //////// válasz
            fill = temp.setAnswer;
            lb_answer.Items.Clear();
            foreach (string a in fill)
            {
                item = new ListBoxItem();
                item.Content = a;
                lb_answer.Items.Add(item);
            }
                fill = temp.setDono;
                random.Items.Clear();
                foreach (string a in fill)
                {
                    item = new ListBoxItem();
                    item.Content = a;
                    random.Items.Add(item);

                }
                //////////////////////////////////////

                txb_prolog.Text = temp.Prolog;
            txb_complement.Text = temp.Complement;
                // txb_code.Text = temp.Code;
            }


        }

        private void Btn_save_Click(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.SaveFileDialog dlg = new Microsoft.Win32.SaveFileDialog();
            dlg.FileName = txb_path.Text; // Default file name
            dlg.DefaultExt = ".map"; // Default file extension
            dlg.Filter = " Map File (.map)|*.map"; // Filter files by extension

            // Show save file dialog box
            Nullable<bool> result = dlg.ShowDialog();

            // Process save file dialog box results
            if (result == true)
            {
                // Save document
                txb_path.Text = dlg.FileName;
                Level temp = new Level();
                //////kérdés
                List<string> fill = new List<string>();
                foreach(ListBoxItem q in lb_question.Items)
                {
                    fill.Add((string)q.Content);
                }
                temp.setQuestion = fill;
                //////// válasz
                fill = new List<string>();
                foreach (ListBoxItem a in lb_answer.Items)
                {
                    fill.Add((string)a.Content);
                }
                temp.setAnswer = fill;
                ///random lista
                fill = new List<string>();
                foreach (ListBoxItem d in random.Items)
                {
                    fill.Add((string)d.Content);
                }
                temp.setDono = fill;

                //////////////////////////////////////
                temp.Prolog = txb_prolog.Text;
                temp.Complement = txb_complement.Text;
                temp.Code = txb_code.Text;

                temp.Savetofile(dlg.FileName);
            }
        }

        private void Btn_add_Click(object sender, RoutedEventArgs e)
        {
            ListBoxItem qitem = new ListBoxItem();
            ListBoxItem aitem = new ListBoxItem();
            qitem.Content = txb_question.Text;
            aitem.Content = txb_answer.Text;
            lb_question.Items.Add(qitem);
            lb_answer.Items.Add(aitem);
        }

        private void Lb_question_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

            try
            {
                lb_answer.SelectedIndex = lb_question.SelectedIndex;

                txb_question.Text = (string)((ListBoxItem)lb_question.Items.GetItemAt(lb_answer.SelectedIndex)).Content;
                txb_answer.Text = (string)((ListBoxItem)lb_answer.Items.GetItemAt(lb_answer.SelectedIndex)).Content;
            }catch(Exception)
            {

            }
           
        }

        private void Btn_remove_Click(object sender, RoutedEventArgs e)
        {
            if(lb_answer.Items.Count>0 && lb_question.SelectedIndex>=0)
            {
                int i = lb_question.SelectedIndex;
                lb_question.Items.RemoveAt(i);
                lb_answer.Items.RemoveAt(i);
                lb_question.SelectedIndex = 0;
            }
           
        }

        private void Btn_edit_Click(object sender, RoutedEventArgs e)
        {
            if (lb_question.Items.Count <= 0)
                return;
            ((ListBoxItem)lb_question.Items.GetItemAt(lb_answer.SelectedIndex)).Content = txb_question.Text;
            ((ListBoxItem)lb_answer.Items.GetItemAt(lb_answer.SelectedIndex)).Content = txb_answer.Text;
        }

        private void Btn_savebiblist_Click(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.SaveFileDialog dlg = new Microsoft.Win32.SaveFileDialog();
            dlg.FileName = txb_path.Text; // Default file name
            dlg.DefaultExt = ".po"; // Default file extension
            dlg.Filter = " Map File (.po)|*.po"; // Filter files by extension

            // Show save file dialog box
            Nullable<bool> result = dlg.ShowDialog();

            // Process save file dialog box results
            if (result == true)
            {
                // Save document
                txb_path.Text = dlg.FileName;
                Biglist temp = new Biglist();
                //////kérdés
                List<string> fill = new List<string>();
                foreach (ListBoxItem q in lb_question.Items)
                {
                    fill.Add((string)q.Content);
                }
                temp.setQuestion = fill;
                //////// válasz
                fill = new List<string>();
                foreach (ListBoxItem a in lb_answer.Items)
                {
                    fill.Add((string)a.Content);
                }
                temp.setAnswer = fill;
                ///random lista
                fill = new List<string>();
                foreach (ListBoxItem d in random.Items)
                {
                    fill.Add((string)d.Content);
                }
                temp.setDono = fill;

                //////////////////////////////////////
                

                temp.Savetofile(dlg.FileName);
            }
        }

        private void Btn_openbiglist_Click(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.OpenFileDialog openFileDialog = new Microsoft.Win32.OpenFileDialog();
            if (openFileDialog.ShowDialog() == true)
            {


                txb_path.Text = openFileDialog.FileName;
                Biglist temp = new Biglist();
                temp = temp.Loadlevel(openFileDialog.FileName);
                List<string> fill;
                ListBoxItem item;
                fill = temp.setQuestion;
                lb_question.Items.Clear();
                foreach (string q in fill)
                {
                    item = new ListBoxItem();
                    item.Content = q;
                    lb_question.Items.Add(item);
                }

                //////// válasz
                fill = temp.setAnswer;
                lb_answer.Items.Clear();
                foreach (string a in fill)
                {
                    item = new ListBoxItem();
                    item.Content = a;
                    lb_answer.Items.Add(item);
                }
                

                ///random lista
                fill = temp.setDono;
                random.Items.Clear();
                foreach (string a in fill)
                {
                    item = new ListBoxItem();
                    item.Content = a;
                    random.Items.Add(item);
                    
                }
                
            }
            }

        private void Btn_add_dono_Click(object sender, RoutedEventArgs e)
        {
            ListBoxItem ritem = new ListBoxItem();
            ritem.Content = txb_random.Text;
            random.Items.Add(ritem);
        }

        private void Btn_edit_dono_Click(object sender, RoutedEventArgs e)
        {
            if (random.Items.Count <= 0)
                return;
            ((ListBoxItem)random.Items.GetItemAt(random.SelectedIndex)).Content = txb_random.Text;
        }

        private void Btn_remove_dono_Click(object sender, RoutedEventArgs e)
        {
            if (random.SelectedIndex >= 0)
            {
                int i = random.SelectedIndex;
                random.Items.RemoveAt(i);
                random.SelectedIndex = 0;
            }
        }

        private void Random_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            try
            {
                lb_answer.SelectedIndex = lb_question.SelectedIndex;

                txb_question.Text = (string)((ListBoxItem)lb_question.Items.GetItemAt(lb_answer.SelectedIndex)).Content;
                txb_answer.Text = (string)((ListBoxItem)lb_answer.Items.GetItemAt(lb_answer.SelectedIndex)).Content;
            }
            catch (Exception)
            {

            }
        }
    }
}
