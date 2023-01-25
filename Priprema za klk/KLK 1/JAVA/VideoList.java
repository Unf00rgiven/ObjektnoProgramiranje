package paket;

import java.util.ArrayList;

public class VideoList {
	private ArrayList<Video> listaVidea;
	
	public VideoList() {
		listaVidea = new ArrayList<Video>();
	}
	
	public boolean dodajVideo(Video v) {
		for(Video v1: listaVidea) {
			if(v1.getNaziv().equals(v.getNaziv())) {
				return false;
			}
		}
		
		return listaVidea.add(v);
	}
	
	public boolean obrisiVideo(String obrisi) {
		int zaBrisanje = -1;
		
		for(int i = 0;i<listaVidea.size();i++) {
			if(listaVidea.get(i).getNaziv().equals(obrisi)) {
				zaBrisanje = i;
				break;
			}
		}
		
		return listaVidea.remove(zaBrisanje)!=null;
	}
	
}