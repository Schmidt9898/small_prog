package beszelgeto;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class Start {

	public static void main(String[] args) {
	//	new hallgat(22222).start();
		BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
		try {
			//if(cin.readLine().equals("Connect")) {
			//	String ip=cin.readLine();
				//Socket S = new Socket(ip,12345);
			Socket S = new Socket("192.168.1.11",12345);
				new beszelo(S).start();
			//}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
