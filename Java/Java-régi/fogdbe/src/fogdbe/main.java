package fogdbe;

public class main {

	public static void main(String[] args) {
		Integer port= new Integer(12345);
		//String cim=new String("localhost");
		//new hallgato(cim,port).start();
		hallgato Pali=new hallgato(port);
		Pali.start();	
			System.out.println("Idióta");
		}
		
	}


