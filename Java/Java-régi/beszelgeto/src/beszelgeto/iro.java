package beszelgeto;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class iro extends Thread {
public iro() {
	
}

@Override
public void run() {
	BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
	while(!this.isInterrupted()) {
		try {
			beszelo.szoveg=cin.readLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

}
