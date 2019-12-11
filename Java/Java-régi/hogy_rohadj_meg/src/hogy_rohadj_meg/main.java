package hogy_rohadj_meg;

import java.util.ArrayList;

public class main {

	public static void main(String[] args) throws InterruptedException {
		ArrayList<Integer> lista = new ArrayList<Integer>();
		for(int i=0;i<100;i++) {
			lista.add((int)( Math.random()*100));
		}
		new Thread(new adom(lista)).start();
		new Thread(new torol(lista)).start();
		while(true) {
			System.out.println(lista.size());
			Thread.sleep(100);
		}
	}

}
