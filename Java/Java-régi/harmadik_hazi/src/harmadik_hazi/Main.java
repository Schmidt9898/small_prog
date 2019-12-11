package harmadik_hazi;


import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		{
			munka.Raktar.add("Ájtatosmanó-érmét");
			munka.Raktar.add("Kéttonnás tunikát");
			munka.	Raktar.add("Dashi szemét");
			munka.	Raktar.add("Harmadik kézt");
			munka.	Raktar.add("Arany tigriskarmokat");
			munka.	Raktar.add("Árnyak leplét");
			munka.	Raktar.add("Örvös állat járatát");
			munka.	Raktar.add("Hangyák a gatyábant");
			munka.	Raktar.add("Saiping nyelvét");
			munka.	Raktar.add("Kuszaháló fésűjét");
		}
		ArrayList<Csapat> csapatok = new ArrayList<Csapat>();
		{
			Csapat valtozo = new Csapat("Crew of the Raza");
			valtozo.Tagok.add(new hos("Two"));
			valtozo.Tagok.add(new hos("Three"));
			valtozo.Tagok.add(new hos("Four"));
			valtozo.Tagok.add(new hos("Five"));
			valtozo.Tagok.add(new hos("Six"));
			csapatok.add(valtozo);
			
			valtozo = new Csapat("SG1");
			valtozo.Tagok.add(new hos("ONeill"));
			valtozo.Tagok.add(new hos("Daniel"));
			valtozo.Tagok.add(new hos("Tealc"));
			valtozo.Tagok.add(new hos("Carter"));
			csapatok.add(valtozo);
			
			valtozo = new Csapat("Rainbow");
			valtozo.Tagok.add(new hos("Tachanka"));
			valtozo.Tagok.add(new hos("Caveira"));
			valtozo.Tagok.add(new hos("IQ"));
			valtozo.Tagok.add(new hos("Ying"));
			csapatok.add(valtozo);
			
			valtozo = new Csapat("X force");
			valtozo.Tagok.add(new hos("Deadpool"));
			csapatok.add(valtozo);
			/*valtozo = new Csapat("Recruitok");
			for(int i=0;i<100;i++) {
				valtozo.Tagok.add(new hos("Recruit"));
			}
			csapatok.add(valtozo);*/
		}
///////////////////////////////////////////feltöltve.
		///kezdjük
		System.out.println("Raktár tartalma "+munka.Raktar.size());
		new Thread(new kuldetes_generalo()).start();;
		new Ora().start();
		new Thread(new statiro()).start();;
		for(int i=0;i<csapatok.size();i++) {
			csapatok.get(i).indit();
		}
		while(true) {
		if(!Ddolog.b) {
		float[] szumma= new float[csapatok.size()];
		for (int i = 0; i < szumma.length; i++) {szumma[i] = 0;}
		for(int i=0;i<csapatok.size();i++) {
			for(int j=0;j<csapatok.get(i).Tagok.size();j++) {
				szumma[i]+=csapatok.get(i).Tagok.get(j).szint;
			}
		}
		for (int i = 0; i < szumma.length; i++) {
			System.out.println("A " + csapatok.get(i).Csapatnev + " :"+ szumma[i] + " pontot szerzett.");
			}
		break;
		}else {
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	}

}
