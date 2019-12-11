/*
 * Created by SharpDevelop.
 * User: salamol
 * Date: 08/07/2018
 * Time: 14:43
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
	/// Description of Ipconnection.
	/// </summary>
	public class Ipconnection
	{
		TcpClient client=null;
		TcpListener server=null;
		bool futhatok=true;
		//Thread parent=null;
	//	public Ipconnection(Thread parent_){parent=parent_;}
		
		public void listen()
		{
			try{

			server=new TcpListener(IPAddress.Parse(Userdata.sajt_cim),12345);
			server.Start();
			client=server.AcceptTcpClient();
			Thread o=new Thread(olvaso);					communication.i++;
			Thread i=new Thread(iro);						communication.i++;
			o.IsBackground=true;	
			i.IsBackground=true;
			o.Start();
			i.Start();
			//Thread.Sleep(1000);
			}catch(Exception e){
				communication.textbe+=e.ToString();
			}
			communication.i--;
		}
		public void connect()
		{
			try{
				if(communication.szabad){
			client=new TcpClient(Userdata.cel_cim,12345);
			communication.szabad=false;	
			communication.textbe+="Sikeresen kapcsolódva a '"+Userdata.cel_cim+"' címre\n";
			Thread o=new Thread(olvaso);			communication.i++;
			Thread i=new Thread(iro);				communication.i++;
			o.IsBackground=true;
			i.IsBackground=true;
			o.Start();
			i.Start();}
				
		//	Thread.Sleep(1000);
			}catch(Exception e){ communication.textbe += e.ToString(); }
			communication.i--;
		}
		public void olvaso()
		{
			//parent.Suspend();
			Byte[] bytes = new Byte[1024];
      		NetworkStream stream = client.GetStream();
      		while(client.Connected && futhatok) 
      		{
      			try{
      		int i=stream.Read(bytes, 0, bytes.Length);
      		communication.textbe+= System.Text.Encoding.UTF8.GetString(bytes, 0, i);}
      			catch(Exception e){communication.textbe+="OLVASÓ HIBA\n";}
            
      		 }
      		communication.textbe+="MEGSZAKADT A KAPCSOLAT\n";
      		communication.i--;
      		communication.szabad=true;
      		//parent.Resume();
      		//vége
		}
		public void iro()
		{
			NetworkStream stream = client.GetStream();
			while(client.Connected && futhatok){
				try{
				if(!communication.textki.Equals(""))
				{
					byte[] msg = System.Text.Encoding.UTF8.GetBytes(communication.textki);
					
					communication.textki="";
      		 		stream.Write(msg, 0, msg.Length);
				}
				
				Thread.Sleep(100);
				}catch(Exception e){communication.textbe+="ÍRÁS HIBA\n";}
			}
			communication.textbe+="MEGSZAKADT A KAPCSOLAT\n";
			communication.i--;
			
		}
	}
}
