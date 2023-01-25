package del;

public class Autobus {
	
	private String regbr;
	private int godiste;

	public Autobus() {
		regbr = "";
		godiste = 0;
	}
	
	public Autobus(String t, int g) {
		regbr = t;
		godiste = g;
	}
	
	public boolean voznoStanje(){
		if (godiste>2000) {
			return true;
		}
		return false;
	}

	public String getRegbr() {
		return regbr;
	}

	public int getGod() {
		return godiste;
	}
	
	
}
