package harmadik_hazi;

public class hos implements Runnable {
float szint = 0;
String nev;
Object irhat;
Boolean Ido;
boolean megvan_minden= false;
Kuldetes kuldi = null;
public hos(String Nev) {
	nev=Nev;
	System.out.println(nev+" jelen uram!");
}
public void  szerez_kuldit() {
	for(int i=0;i<munka.Tabla.size();i++) {
		if(munka.Tabla.get(i).szint<=((int) szint )) {
			kuldi=munka.Tabla.get(i);
			munka.Tabla.remove(i);
			return;
	}
	}
	try {
		Thread.sleep(150);
	} catch (InterruptedException e) {
		System.out.println("Hiba a küldetés szerzésben!");
		e.printStackTrace();
	}
	
}
public void  lefoglalom() {
	for(int j=0;j<kuldi.kell_hozza.size();j++){
			if(munka.Raktar.contains(kuldi.kell_hozza.get(j))) {
				megvan_minden= true;
			}else {
				megvan_minden=false;
				try {
					Thread.sleep(300);
				} catch (InterruptedException e) {
					System.out.println("Hiba a lefoglalásban!");
					e.printStackTrace();
				}
				return;
			}
	}
	for(int j=0;j<kuldi.kell_hozza.size();j++) {
		munka.Raktar.remove(kuldi.kell_hozza.get(j));
	}
	if(kuldi.kell_hozza.size()==0) {
		megvan_minden=true;
	}
}
public void hol_van_francis() {
	try {
		String uzi = new String();
		uzi=nev + " felvette a ";
		if(kuldi.kell_hozza.size()==0)
			uzi+="semmit ";
		for(int i=0;i<kuldi.kell_hozza.size();i++)
		{
			uzi+= kuldi.kell_hozza.get(i) + ", ";
		}
		uzi+="és elment " + kuldi.feladat +"."+"\n";
		synchronized (stat.uzenet) {
			stat.pluszba(uzi);
		}
		Thread.sleep((long) kuldi.ido);// alszik munkaidőben
	} catch (InterruptedException e) {
		System.out.println("NINCS MEG FRANCIS");
		e.printStackTrace();
	}
	synchronized (munka.Raktar) { // viszateszi
		for(int j=0;j<kuldi.kell_hozza.size();j++) {
			munka.Raktar.add(kuldi.kell_hozza.get(j));
		}
	}
	szint+=kuldi.xp;
	kuldi=null;
	megvan_minden=false;
	
}
	@Override
	public void run() {
		//System.out.println(nev +" szálon vagyok");
		while(Ddolog.b) { 
			if(kuldi==null) { //nincs feladatot menj és szerez magadnak
				synchronized (munka.Tabla) {
				this.szerez_kuldit();
				//System.out.println(nev +" küldetésem van ?");
				}
				continue;
			}else{
				if(!megvan_minden) {
					//System.out.println(nev+"megvan minden");
					synchronized (munka.Raktar) {
						//System.out.println(nev +" raktárban vagyok");
					this.lefoglalom();//menj a raktárba és szerez fegyvert
					}
					continue;// ha van lefoglalom
				}else {
					//megyek a küldetésre
				//	System.out.println(nev +" küldetésre megyek "+ kuldi.szint+ " szintűre.");
					hol_van_francis();
				}}
			}
		}
	

}
