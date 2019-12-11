package akinemfogjabe;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class beszed extends Thread {
	private Socket Pali;
public beszed(Socket Miert) {
	Pali=Miert;
		
}
@Override
public void run() {
	try {
BufferedReader olvaso=new BufferedReader(new InputStreamReader(Pali.getInputStream()));
PrintWriter iro = new PrintWriter(Pali.getOutputStream());
	String sor="";
	try {
		while(! (sor = olvaso.readLine()).equals("KUSS") && !this.isInterrupted()){
			if(sor.equals(""))
			System.out.println(sor);
			if(!(csatorna.uzi.equals(""))) {
				iro.print(csatorna.uzi);iro.flush();}
			try {
				this.sleep(100);
			} catch (InterruptedException e) {}
		}
	} catch (IOException e) {}
	
}catch(IOException e) {}
}
	
}
