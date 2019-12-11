package fogdbe;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

public class hallgato extends Thread {
public Integer port;
//public String cim;
ServerSocket Pali;
public hallgato(Integer port_) {
	port=port_;
	//cim=cim_;
	//System.out.println("Mivan Laci?");
}
	
	
@Override
public void run() {
	
	try {
		Pali = new ServerSocket(port);
		Pali.setSoTimeout(10000);
	

		System.out.println("Mivan Laci?");
		while(!this.interrupted()) {
			System.out.println("Pali várakozik.");
			Socket Pali_ready= Pali.accept();
			new beszed(Pali_ready).start();
			break;
		}	} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("fölösleg bezárva");
		try {
			Pali.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	
}

}
