package beszelgeto;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;

public class hallgat extends Thread {
	
	private Integer port;
	public hallgat(Integer p) {
		port=p;
	}

	@Override
	public void run() {
		try {
			ServerSocket Server = new ServerSocket(port);
			InetAddress ip;

			ip = InetAddress.getLocalHost();
			System.out.println(ip+":"+port);
			while(!this.interrupted()) {
				new beszelo(Server.accept()).start(); 
				
			}
		}catch(IOException e) {
			
		}
	}

	
	
	
	
}
