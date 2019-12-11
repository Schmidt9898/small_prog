package beszelgeto;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class beszelo extends Thread {
	private Socket S;
	public static String szoveg= new String("abbba");
public beszelo(Socket S_) {
		S=S_;
}
@Override
public void run() {
	try {
		System.out.println("Sikeres csatlakozás.");
		BufferedReader SInput = new BufferedReader(new InputStreamReader(S.getInputStream()));
		PrintWriter SOutput = new PrintWriter(S.getOutputStream());
		String line= "";
		new iro().start();
		while(! (line = SInput.readLine()).equals("EXIT")){
			if(!line.equals("")) {
				System.out.println(line);
			}
			if(szoveg!="") {
				SOutput.print(szoveg);
				SOutput.flush();
			}
		}
		
		
	}catch(IOException e){
		
	}
}



}
