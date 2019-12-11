package harmadik_hazi;

import java.util.ArrayList;

public class munka {
	static ArrayList<Kuldetes> Tabla = new ArrayList<Kuldetes>();
	static ArrayList<String> Raktar = new ArrayList<String>();
	public static ArrayList<Kuldetes> gettabla()
	{
		return Tabla;
	}
	public static void törölkuldi(Kuldetes ezt)
	{
		Tabla.remove(ezt);
	}
	public static void addkuldi(Kuldetes ezt)
	{
		Tabla.add(ezt);
	}
	//////////////////////////
	public static ArrayList<String> getRaktar()
	{
		return Raktar;
	}
	public static void elvisz(String ezt)
	{
		Raktar.remove(ezt);
	}
	public static void viszhoz(String ezt)
	{
		Raktar.add(ezt);
	}
}
