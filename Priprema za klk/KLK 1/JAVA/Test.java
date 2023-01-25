package paket;

public class Test {

	public static void main(String[] args) {
		System.out.println("cao drugari :)");
		
		Video v1 = new Video();
		Video v2 = new Video("test", 10, "1080p");
		v1.getNaziv();
		v1.getTrajanje();
		v1.getRezolucijaVidea();
		v1.setNaziv("setTest");
		v1.setRezolucijaVidea("720p");
		v1.setTrajanje(20);
		
		VideoList vl = new VideoList();
		vl.dodajVideo(v1);
		vl.obrisiVideo("setTest");
	}

}
