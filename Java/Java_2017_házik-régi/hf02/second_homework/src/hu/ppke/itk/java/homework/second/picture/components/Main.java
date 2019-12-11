package hu.ppke.itk.java.homework.second.picture.components;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.io.Writer;
public class Main {

	public static void main(String[] args) {
	/*	if(args[0]=="--html") {
		Writer f = new FileWriter("megoldas.html");
		}
		else {
		Writer f=new FileWriter("megoldas.svg");
		}*/
		
		try {
		Reader r=new FileReader("example.in");
		
		Picture P=new Picture();
		
	//	Writer f=new FileWriter("megoldas.svg");
		Writer hf = new FileWriter("megoldas.html");
		

		P.build(r);
		//P.write(f);
		P.write(hf);
		}catch
		(Exception e) {}

}
}
