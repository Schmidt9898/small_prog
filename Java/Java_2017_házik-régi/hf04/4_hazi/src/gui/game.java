package gui;

import java.util.ArrayList;
import java.util.Random;

public class game implements Runnable {
	String nev;
	ArrayList<hajo> hajok=new ArrayList<>();
public game(String nev_,int tabla) {
	nev=nev_;
	Random rn= new Random();
	int irany=1;
	for(int i=1;i<5;i++) {
		while(true) {
			int rand=rn.nextInt()%21;
			
		if(rand<=19-i)	{
			hajok.add(new hajo(i, irany, rand, rand));
		}
		}
		
	}
	
}
	@Override
	public void run() {
	

	}

}
