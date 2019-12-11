/*
 * Created by SharpDevelop.
 * User: salamol
 * Date: 07.08.2018
 * Time: 14:27
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Net.Sockets;
using System.Net;
using System.Threading;

namespace tcpipkapcsolat
{
	/// <summary>
	/// Interaction logic for Window1.xaml
	/// </summary>
	public partial class Window1 : Window
	{
		//Ipconnection ipkapcsolat=new Ipconnection();
		Thread server=new Thread(new Ipconnection().listen);
		Thread client=new Thread(new Ipconnection().connect);
		public System.Windows.Threading.DispatcherTimer dispatcherTimer = new System.Windows.Threading.DispatcherTimer();
		public Window1()
		{
			InitializeComponent();
			dispatcherTimer.Interval = new TimeSpan(0,0,0,0,10);
			dispatcherTimer.Tick+=refreshgui;
			dispatcherTimer.Start();
			
			
			string HostName = Dns.GetHostName();  
            IPAddress[] ipaddress = Dns.GetHostAddresses(HostName);  
            Userdata.sajt_cim=ipaddress[1].ToString();
			cel.Text=Userdata.cel_cim;
			sorce.Text=Userdata.sajt_cim;
			nev.Text=Userdata.nev;
			
		}
		public void refreshgui(object sender,EventArgs e)
		{
			if(!communication.textbe.Equals(""))
			{
				textablak.Text+=communication.textbe;
				textablak.ScrollToEnd();
				communication.textbe="";
			}
			szal.Content=communication.i.ToString();
          /*  textline.Text = "000";
            sender_Click(sender,e);
            */

        }
		void listen_Click(object sender, RoutedEventArgs e)
		{	 
			if(server.IsAlive){
				server.Interrupt();
				//server.Abort();
				
			}
			server=new Thread(new Ipconnection().listen);
			server.IsBackground=true;
			communication.i++;
			server.Start();
		}
		void connect_Click(object sender, RoutedEventArgs e)
		{
			if(!client.IsAlive){
				client=new Thread(new Ipconnection().connect);
				client.IsBackground=true;
				communication.i++;
				client.Start();}
		}
		void sender_Click(object sender, EventArgs e)
		{
				communication.textki+=textline.Text+"\n";
				communication.textbe+=textline.Text+"\n";
			textline.Text="";
		}
		void textline_KeyUp(object sender, KeyEventArgs e)
		{
			if(e.Key==System.Windows.Input.Key.Enter)
			{
				communication.textki+=textline.Text+"\n";
				communication.textbe+=Userdata.nev+": "+textline.Text+"\n";
				textline.Text="";
			}
		}
		void nev_TextChanged(object sender, TextChangedEventArgs e)
		{
			Userdata.nev=nev.Text;
		}
		void sorce_TextChanged(object sender, TextChangedEventArgs e)
		{
			Userdata.sajt_cim=sorce.Text;
		}
		void cel_TextChanged(object sender, TextChangedEventArgs e)
		{
			Userdata.cel_cim=cel.Text;
		}
		
	}
}