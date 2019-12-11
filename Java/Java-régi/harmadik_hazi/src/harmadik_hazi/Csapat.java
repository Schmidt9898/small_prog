package harmadik_hazi;

import java.util.ArrayList;

public class Csapat {
	String Csapatnev;
	ArrayList<hos> Tagok = new ArrayList<hos>();
	public Csapat(String nev) {
		Csapatnev=nev;
	}
	public void indit() {
		for(int i=0;i<Tagok.size();i++) {
			new Thread (Tagok.get(i)).start();
		}
	}

}
