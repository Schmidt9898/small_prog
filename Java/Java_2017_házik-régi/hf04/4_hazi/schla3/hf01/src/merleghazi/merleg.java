package merleghazi;

public class merleg {
		private int[] sulyok;
		public merleg(int[] a) {
			sulyok = a;
		}
		int[] sulyokraValt(int t) {
		
		int fel[] = new int[t+1];
		int le[] = new int[t+1];
		fel[0]=0;
		for(int i=1;i<=t;i++) {
			fel[i]=Integer.MAX_VALUE-1;
			le[i]=-1;
		}
		for(int j=0;j<sulyok.length;j++) {
			for(int i=1;i<=t;i++) {
				if(i>=sulyok[j]) {
					if(fel[i-sulyok[j]]+1<fel[i]) {
						fel[i]=1+fel[i-sulyok[j]];
						le[i]=j;
					}
				}
			}
		}
		int[] valasz= new int[sulyok.length];
		for(int e:valasz) {
			e=0;
		}
	if(le[le.length-1]==-1) {
		System.out.print("nincs megoldás");
		return valasz;
	}
	int elol = le.length-1;
	while(elol!=0) {
		int j=le[elol];
		valasz[j]++;
		elol-=sulyok[j];
	}
			return valasz;
		}
		public void sulyokatListaz(int s) {
			int[] v=sulyokraValt(s);
			int osz=0;
			for(int e:v) {
				System.out.print(e);
				System.out.print(" ");
				osz+=e;
			}
			System.out.println();
			System.out.print("összesen: ");	
			System.out.println(osz);
		}
		
}
