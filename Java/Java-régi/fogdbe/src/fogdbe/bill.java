package fogdbe;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class bill extends Thread {
	 PrintWriter iro;
public bill(PrintWriter ir) {
	iro=ir;
}
@Override
public void run() {
	BufferedReader be=new BufferedReader(new InputStreamReader(System.in));
	String sor="";
		try {
			while(! (sor= be.readLine()).equals("KUSS")) {
				iro.println(sor);
				iro.flush();
			}
			iro.println("KUSS");
		} catch (IOException e) {
			e.printStackTrace();
		}
}

}
