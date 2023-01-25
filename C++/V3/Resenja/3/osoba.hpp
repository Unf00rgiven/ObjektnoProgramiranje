#ifndef OSOBA_DEF
#define OSOBA_DEF

#include "dinstring.hpp"
#include <iostream>

using namespace std;

class Osoba
{
	protected:
		DinString ime, prezime;

	public:
		Osoba(const char* s1 = "", const char* s2 = "") : ime(s1), prezime(s2) { }

		Osoba(const DinString& ds1, const DinString& ds2) :	ime(ds1), prezime(ds2) { }

		Osoba(const Osoba& osoba) : ime(osoba.ime), prezime(osoba.prezime) { }


		//metoda se proglasava virtuelnom samo jednom, i to u roditeljskoj klasi (kljucna rec "virtual")
		//i tada u svim klasama naslednicama ta metoda zadrzava tu osobinu

		//virtuelne metode osiguravaju da se za objekat poziva ispravna metoda, bez
        //obzira na vrstu reference (ili pokazivaca) koji se koristi za poziv metode

		//metoda se deklarise kao virtuelna u BAZNOJ klasi
		virtual void predstaviSe() const
		{
			cout << "Zovem se " << ime << " " << prezime << "." << endl;
		}

		/*
		void predstaviSe() const
		{
			cout << "Zovem se " << ime << " " << prezime << "." << endl;
		}
		*/
};

#endif
