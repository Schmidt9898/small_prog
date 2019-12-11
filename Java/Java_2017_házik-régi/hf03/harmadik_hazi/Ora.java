package harmadik_hazi;

public class Ora extends Thread {
	@Override
	public void run() {
		System.out.println("kezdjük");
		try {
			Thread.sleep(30000);
		} catch (InterruptedException e) {
			System.out.println("Hiba az órában!");
			e.printStackTrace();
		}
		Ddolog.b=false;
		//System.out.println(Ddolog.b);
		System.out.println("vége, de aki küldetésen van az még visza érhet.");
		
	}

}
