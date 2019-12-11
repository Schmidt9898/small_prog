package harmadik_hazi;

import java.util.ArrayList;

public class Kuldetes {
	int szint;
	double ido;
	ArrayList<String> kell_hozza = new ArrayList<String>();
	String feladat;
	float xp;
	
	public Kuldetes(ArrayList<String> S,ArrayList<String> f) {
		szint = (int)(Math.random()*5);
	//	System.out.println("Küldetés szintje: "+szint+ " es a merete"+S.size()+" "+Math.random()*S.size());
	
		
		for(int i=0;i<szint;i++) {   //Igen tudom és megengedem, hogy előforduljon olyan eset, hogy az eszközök száma nem eggyezik meg a szint számával.
			String ez = new String(S.get((int)(Math.random()*S.size()))); // Mindenképpen lesz benne egy darab elem ha a szint nem 0.
			if(!kell_hozza.contains(ez)) {
			kell_hozza.add(ez);
			}
		}
		feladat = new String(f.get((int)(Math.random()*f.size())));
		xp=1;
		ido=(Math.random()*100)+1;
}
}