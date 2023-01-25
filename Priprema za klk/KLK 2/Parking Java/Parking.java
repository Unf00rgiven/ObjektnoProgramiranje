package del;

import java.util.HashMap;

public class Parking {
	private String naziv;
	private HashMap<String, Autobus> autobusi;
	
	public Parking(String n) {
		naziv = n;
		autobusi = new HashMap<>();
	}
	public boolean uparkiraj(Autobus a) {
		if (autobusi.containsKey(a.getRegbr()) || a.voznoStanje()==false) {
			return false;
		}
		autobusi.put(a.getRegbr(), a);
		return true;
	}
	public Autobus isparkiraj(String rbr) {
		return autobusi.remove(rbr);
	}
	
	public String toString() {
		String retVal="";
		
		retVal+="Naziv parkinga je: "+naziv+". ";
		
		if (autobusi.isEmpty()) return retVal+"- parking je prazan.";
		
		retVal+="\nNa parkingu su autobusi sa sledecim registarskim tablicama: ";
		for (Autobus a: autobusi.values()) {
			retVal+=a.getRegbr();
			retVal+=" ";
		}
		return retVal;
		
	}
	
	

}
