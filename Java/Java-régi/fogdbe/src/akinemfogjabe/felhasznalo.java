package akinemfogjabe;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;

import fogdbe.csatorna;

public class felhasznalo {

	public static void main(String[] args) {
		try {
			Socket S=new Socket("localhost",12345);
			beszed Laci=new beszed(S);
			Laci.start();
			BufferedReader be=new BufferedReader(new InputStreamReader(System.in));
			try {
				while(! (csatorna.uzi= be.readLine()).equals("KUSS"));
				csatorna.uzi="KUSS";
				Laci.interrupt();
				System.out.println("Laci kussol");
			} catch (IOException e) {}
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
