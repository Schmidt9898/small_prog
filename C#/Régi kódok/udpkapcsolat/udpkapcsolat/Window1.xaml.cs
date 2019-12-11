/*
 * Created by SharpDevelop.
 * User: salamol
 * Date: 09.08.2018
 * Time: 08:25
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;

using System.Text;
using System.Windows;

using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Input;

using System.Threading;

using System.Text.RegularExpressions;

using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace udpkapcsolat
{
	/// <summary>
	/// Interaction logic for Window1.xaml
	/// </summary>
	public partial class Window1 : Window
	{
		public System.Windows.Threading.DispatcherTimer dispatcherTimer = new System.Windows.Threading.DispatcherTimer();
		public System.Windows.Threading.DispatcherTimer baratlistatimer = new System.Windows.Threading.DispatcherTimer();
		Udp csatorna=new Udp();
		Thread olvas=new Thread(new Udp().read);
		Thread ir=new Thread(new Udp().write);
		System.Reflection.PropertyInfo[] szinek =typeof(Colors).GetProperties();
		public Window1()
		{
			InitializeComponent();
			bszinvalaszto.ItemsSource =szinek;
			
			szinvalaszto.ItemsSource=szinek;
			
			try{
			string p11123=System.IO.Path.GetFullPath(@"11123\11123.jpg");

			BitmapImage i11123 = new BitmapImage(new Uri(p11123));
			
			kep.Source=i11123;	
			string nevem = System.IO.File.ReadAllText(System.IO.Path.GetFullPath(@"11123\nev.txt"));
			if(!nevem.Equals("")){
				Userdata.nev=Regex.Replace(nevem,@"(\s[\w\s]\n)","");
				nev.Text=nevem;
				textline.Focus();
					szinvalaszto.SelectedIndex=3;
				bszinvalaszto.SelectedIndex=7;
				
			}
			}catch(Exception){
				szinvalaszto.SelectedIndex=3;
				bszinvalaszto.SelectedIndex=7;
			Random rnd = new Random();
			Userdata.nev=Encoding.ASCII.GetString(new byte[]{ ((byte)rnd.Next(65,91)), (byte)rnd.Next(65,91),(byte)rnd.Next(65,91),(byte)rnd.Next(65,91)});
			nev.Focus();
			}
			//nev.Text=Userdata.nev;
			dispatcherTimer.Interval = new TimeSpan(0,0,0,0,100);
			baratlistatimer.Interval = new TimeSpan(0,0,0,0,1000);//növeld
			dispatcherTimer.Tick+=refreshgui;
			baratlistatimer.Tick+=refresbaratlista;
			dispatcherTimer.Start();
			baratlistatimer.Start();
			olvas.IsBackground=true;
			ir.SetApartmentState(ApartmentState.STA);
			olvas.SetApartmentState(ApartmentState.STA);
			ir.IsBackground=true;
			olvas.Start();
			ir.Start();
		
		}
		public void refresbaratlista(object sender,EventArgs e)
		{
			felhasznalok.Text="";
			foreach(string elem in communication.items)
			{
				felhasznalok.Text+=elem+"\n";
			}
			
		}
			
		void textline_KeyUp(object sender, KeyEventArgs e)
		{
			
			if(e.Key==System.Windows.Input.Key.Enter && (!System.Text.RegularExpressions.Regex.IsMatch(textline.Text,@"^[\s]*$"))&& !textline.Text.Contains("|"))
			{
				if(textline.Text.Equals("*cls"))
				{
					textline.Text="";
					beszelgeto.Children.Clear();
				}else{
				TextBox dynamicLabel = new  TextBox();

  dynamicLabel.Name = "NewLabel";
  dynamicLabel.Text = textline.Text;
  dynamicLabel.Margin = new Thickness(0, 5, 0, 0);
  dynamicLabel.TextWrapping=TextWrapping.Wrap;
  dynamicLabel.HorizontalAlignment=HorizontalAlignment.Right;
dynamicLabel.MaxWidth = 300;
  	dynamicLabel.SetValue(TextBoxBase.TemplateProperty, GetRoundedTextBoxTemplate());
  dynamicLabel.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString(szinek[bszinvalaszto.SelectedIndex].Name));
  //dynamicLabel.Background = new SolidColorBrush((Color)ColorConverter.ConvertFromString(szinvalaszto.SelectedItem.ToString()));
  dynamicLabel.Background = new SolidColorBrush((Color)ColorConverter.ConvertFromString(szinek[szinvalaszto.SelectedIndex].Name));
			beszelgeto.Children.Add(dynamicLabel);
				communication.textki+=textline.Text;
				//communication.textbe+=Userdata.nev+": "+textline.Text+"";
				textline.Text="";
				}
			}
		}
	
		public void refreshgui(object sender,EventArgs e)
		{
			if(!communication.textbe.Equals(""))
			{
				TextBox dynamicLabel = new  TextBox();
			/*string a=Regex.Replace(communication.textbe,@"([\w\s]*\:\s\|)","");
				string b= Regex.Replace(a,@"(\:[\w\s]*)","");
				string betu=Regex.Replace(b,@"([a-zA-Z]*\s)","");
				string Back=Regex.Replace(b,@"(\s[a-zA-Z]*)","");
				dynamicLabel.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString(betu));
				dynamicLabel.Background = new SolidColorBrush((Color)ColorConverter.ConvertFromString(Back));*/
/*string regbe= Regex.Replace(communication.textbe,@"\|[a-zA-Z]*\s+[a-zA-Z]*\:","");*/

  dynamicLabel.Name = "NewLabel";
  dynamicLabel.Text = communication.textbe;
  dynamicLabel.TextWrapping=TextWrapping.Wrap;
  dynamicLabel.Margin = new Thickness(0, 5, 0, 0);
  dynamicLabel.HorizontalAlignment=HorizontalAlignment.Left;
  dynamicLabel.MaxWidth = 300;
  dynamicLabel.SetValue(TextBoxBase.TemplateProperty, GetRoundedTextBoxTemplate());
  

			beszelgeto.Children.Add(dynamicLabel);
			tekero.ScrollToEnd();
			//	textablak.Text+=communication.textbe;
			//	textablak.ScrollToEnd();
			//TODO
				communication.textbe="";
				
			}
			only.Content="Elérhető: "+communication.only.ToString();
			if(communication.szabad)
				Application.Current.Shutdown();
			
			
		}
		public void ablak_Closing(object sender,EventArgs e)
		{
			communication.disconnect=true;
		}
		void nev_KeyUp(object sender, KeyEventArgs e)
		{
			if(e.Key==Key.Enter)
			{
				if(!Regex.IsMatch(nev.Text,@"^[a-zA-Z0-9áÁéÉöÖőŐíÍüÜóÓúÚűŰ\s]*$"))
			{
				nev.Text="";
			}
				else if(!Regex.Replace(nev.Text,@"[\s]*","").Equals("")){
					string uzi="<-<"+Userdata.nev+">->";
					System.IO.File.WriteAllText(System.IO.Path.GetFullPath(@"11123\nev.txt"), nev.Text);
				Userdata.nev=nev.Text;
				communication.textki+=uzi;
				textline.Focus();
				}
				else{ 
					nev.Text=Userdata.nev;
				}
				//textline.IsEnabled=true;
			
			}
		}
		void button1_Click(object sender, RoutedEventArgs e)
		{
			panel.Visibility=Visibility.Visible;
		}
		 public ControlTemplate GetRoundedTextBoxTemplate()
        {
            ControlTemplate template = new ControlTemplate(typeof(TextBoxBase));
            FrameworkElementFactory elemFactory = new FrameworkElementFactory(typeof(Border));
            elemFactory.Name = "Border";
            elemFactory.SetValue(Border.CornerRadiusProperty, new CornerRadius(10));
            elemFactory.SetValue(Border.BorderBrushProperty, new SolidColorBrush(Colors.Black));
            elemFactory.SetValue(Border.BackgroundProperty, new TemplateBindingExtension(TextBox.BackgroundProperty));
            elemFactory.SetValue(Border.BorderThicknessProperty, new TemplateBindingExtension(TextBox.BorderThicknessProperty));
            elemFactory.SetValue(Border.SnapsToDevicePixelsProperty, true);
            template.VisualTree = elemFactory;


            FrameworkElementFactory scrollViewerElementFactory = new FrameworkElementFactory(typeof(ScrollViewer));
            scrollViewerElementFactory.Name = "PART_ContentHost";
            elemFactory.AppendChild(scrollViewerElementFactory);


            Trigger isEnabledTrigger = new Trigger();
            isEnabledTrigger.Property = TextBox.IsEnabledProperty;
            isEnabledTrigger.Value = false;

            Setter backgroundSetter = new Setter();
            backgroundSetter.TargetName = "Border";
            backgroundSetter.Property = TextBox.BackgroundProperty;
            backgroundSetter.Value = SystemColors.ControlBrush;

            Setter foregroundSetter = new Setter();
            foregroundSetter.Property = TextBox.ForegroundProperty;
            foregroundSetter.Value = SystemColors.GrayTextBrush;

            isEnabledTrigger.Setters.Add(backgroundSetter);
            isEnabledTrigger.Setters.Add(foregroundSetter);


            template.Triggers.Add(isEnabledTrigger);

            return template;
        }
			
	}
}