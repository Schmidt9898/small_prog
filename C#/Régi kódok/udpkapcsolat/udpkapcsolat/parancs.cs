/*
 * Created by SharpDevelop.
 * User: salamol
 * Date: 08/09/2018
 * Time: 13:28
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

using System.Windows.Controls;

namespace udpkapcsolat
{
	/// <summary>
	/// Description of parancs.
	/// </summary>
	public class parancs
	{
		public parancs()
		{
		}
		public void regparancs(string be)
		{

	if(be.Contains("REFRESH"))
	{
		communication.items.Clear();
   		 communication.items.Add(Regex.Replace(be,@"\:\s<-<[\w\s]*>->[\w\s]*",""));
		communication.only=1;
		communication.textki+="<-<JELEN>->\n";
	}else if(be.Contains("JELEN"))
	{
		if(!communication.items.Contains(Regex.Replace(be,@"\:\s<-<[\w\s]*>->[\w\s]*\n","")))
		{
			communication.items.Add(Regex.Replace(be,@"\:\s<-<[\w\s]*>->[\w\s]*\n",""));
		communication.only++;
		}
	}else if(be.Contains("KILL"))
	{
		communication.szabad=true;
	}
	else if(be.Contains("EXIT"))
	{
		communication.items.Clear();
		communication.only=0;
		communication.textki+="<-<JELEN>->\n";
	}else{
string c=Regex.Replace(be,@"([\w\s]*\:\s)","");
string a=Regex.Replace(c, @"<-<","");
string nev=Regex.Replace(a,@">->[\w]*","");
communication.items.Remove(nev);
communication.items.Add(Regex.Replace(be,@"\:\s<-<[\w\s]*>->[\w\s]*",""));
		
	}
		}
	}
}
