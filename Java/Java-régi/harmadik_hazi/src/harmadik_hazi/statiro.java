package harmadik_hazi;

public class statiro implements Runnable {

	@Override
	public void run() {
		while(Ddolog.b) {
			synchronized (stat.uzenet) {
			System.out.println(stat.uzenet);
			stat.uzenet="";
			}
			try {
				Thread.sleep(10000);
			} catch (InterruptedException e) {
				System.out.println("Hiba a ki íróban!");
				e.printStackTrace();
			}
			
		}
		
		System.out.println(stat.uzenet);

	}

}
