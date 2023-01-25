package paket;

public class Video {
	private String naziv;
	private int trajanje;
	private String rezolucijaVidea;
	
	public Video() {
		super();
	}
	
	public Video(String naziv, int trajanje, String rezolucijaVidea) {
		super();
		this.naziv = naziv;
		this.trajanje = trajanje;
		this.rezolucijaVidea = rezolucijaVidea;
	}
	
	public String getNaziv() {
		return naziv;
	}
	
	public void setNaziv(String naziv) {
		this.naziv = naziv;
	}
	
	public int getTrajanje() {
		return trajanje;
	}
	
	public void setTrajanje(int trajanje) {
		this.trajanje = trajanje;
	}
	
	public String getRezolucijaVidea() {
		return rezolucijaVidea;
	}
	
	public void setRezolucijaVidea(String rezolucijaVidea) {
		this.rezolucijaVidea = rezolucijaVidea;
	}
	
}
