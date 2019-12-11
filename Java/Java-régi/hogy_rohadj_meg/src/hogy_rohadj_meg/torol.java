package hogy_rohadj_meg;

import java.util.ArrayList;

public class torol implements Runnable {
	public ArrayList<Integer> l;
	public torol(ArrayList<Integer> ll) {
		l=ll;
	}
	@Override
	public void run() {
		while(true) {
		if(l.size()>0) {
		//	System.out.print("Törölve:");
			//System.out.println(l.get(0));
			l.remove(0);
			//System.out.println(l.size());
			
		}else {
			System.out.println("nem tudok");
			/*try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}*/
		}
		
		}
	}

}
