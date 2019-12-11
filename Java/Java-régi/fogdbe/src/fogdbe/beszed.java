package fogdbe;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

import akinemfogjabe.bill;

public class beszed extends Thread {
	private Socket Pali;
public beszed(Socket Miert) {
	Pali=Miert;
		
}
@Override
public void run() {
	BufferedReader olvaso = null;
	//PrintWriter iro = null;

	 try {
		olvaso=new BufferedReader(new InputStreamReader(Pali.getInputStream()));
		bill iro=new bill(new PrintWriter(Pali.getOutputStream()));
		iro.start();
	} catch (IOException e1) {
		// TODO Auto-generated catch block
		e1.printStackTrace();
	}
			System.out.println("siker");
		String sor=new String("gg");
		
			//	while(!this.interrupted()){
		try {
			while((sor = olvaso.readLine()) != null) {
						if(sor.equals("KUSS"))
							break;
						System.out.println(sor);
						try {
							this.sleep(100);
						} catch (InterruptedException e) {}
					}
			Pali.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
			}
		

}
	

