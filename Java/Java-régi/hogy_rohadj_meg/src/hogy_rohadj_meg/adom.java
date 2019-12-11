package hogy_rohadj_meg;

import java.util.ArrayList;

public class adom implements Runnable {
	public ArrayList<Integer> l;
	public adom(ArrayList<Integer> ll) {
		l=ll;
	}

	@Override
	public void run() {
		while(true) {
			//for(int i=0;i<;i++) {
				l.add((int)( Math.random()*100));
				try {
					Thread.sleep(10);
				} catch (InterruptedException e) {
					System.out.println("Mi a Fasz?");
					e.printStackTrace();
				}
		//	}
			}

	}

}
