package del;

public class Main {

	public static void main(String[] args) {
		
		Autobus a1 = new Autobus();
		Autobus a2 = new Autobus("NS 123", 2003);
		Autobus a3 = new Autobus("NS 234", 1999);
		Autobus a4 = new Autobus("NI 123", 2002);
		Autobus a5 = new Autobus("SU 345", 2003);
		
		if (a2.voznoStanje())
			System.out.println("Autobus a2 je u voznom stanju.");
		else
			System.out.println("Autobus a2 nije u voznom stanju.");
		System.out.println();
		
		Parking p =  new Parking("Ispred FTN-a");
		
		System.out.println(p);
		System.out.println();
		
		p.uparkiraj(a1);
		p.uparkiraj(a2);
		p.uparkiraj(a3);
		p.uparkiraj(a4);
		p.uparkiraj(a5);
		
		System.out.println(p);
		System.out.println();
		
		Autobus a = p.isparkiraj("NI 123");
		if (a!=null) {
			System.out.println("Uspesno isparkiran autobus "+a.getRegbr());
		}else {
			System.out.println("Nije isparkiran");
		}
		System.out.println();
		
		System.out.println(p);

	}

}
