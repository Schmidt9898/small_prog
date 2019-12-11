package harmadik_hazi;

import java.util.ArrayList;

public class kuldetes_generalo implements Runnable {
	private ArrayList<String> S;
	ArrayList<String> feladat= new ArrayList<String>();
public kuldetes_generalo() {
	S=munka.getRaktar();
		feladat.add("megkeresni Francist");
		feladat.add("Bércesnéni órájára");
		feladat.add("virágot szedni");
		feladat.add("megsétáltatni Buksit");
		feladat.add("Meghekkelni az internetet");
		feladat.add("filmet nézni");
		feladat.add("megverni Mátét HS-ben");
		feladat.add("ebédelni");
		feladat.add("zongorázni");
		feladat.add("spawn killelni konzulátuson");
}
	@Override
	public void run() {
		while(Ddolog.getB()) {
		//System.out.println("2 új küldetés");
		Kuldetes a=new Kuldetes(S,feladat);
		Kuldetes b=new Kuldetes(S,feladat);
		synchronized (munka.class) {
		munka.addkuldi(a);
		munka.addkuldi(b);
		//System.out.println(munka.Tabla.size());
		}
		try {
			Thread.sleep(10);
		} catch (InterruptedException e) {
			System.out.println("Küldetes generáló hiba!!!!!");
			e.printStackTrace();
		}
		}
	}

}
