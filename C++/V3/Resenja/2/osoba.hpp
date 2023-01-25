#ifndef OSOBA_DEF
#define OSOBA_DEF

#include "dinstring.hpp"
#include <iostream>

using namespace std;

/* ponasanje clanova natklase u zavisnosti od nacina izvodjenja:

    (clan u natklasi) public    + (nacin izvodjenja) public    -> (clan u potklasi) PUBLIC
    (clan u natklasi) public    + (nacin izvodjenja) protected -> (clan u potklasi) PROTECTED
    (clan u natklasi) public    + (nacin izvodjenja) private   -> (clan u potklasi) PRIVATE
    (clan u natklasi) protected + (nacin izvodjenja) public    -> (clan u potklasi) PROTECTED
    (clan u natklasi) protected + (nacin izvodjenja) protected -> (clan u potklasi) PROTECTED
    (clan u natklasi) protected + (nacin izvodjenja) private   -> (clan u potklasi) PRIVATE
    (clan u natklasi) private   + (nacin izvodjenja) public    -> (clan u potklasi) NIJE VIDLJIV
    (clan u natklasi) private   + (nacin izvodjenja) protected -> (clan u potklasi) NIJE VIDLJIV
    (clan u natklasi) private   + (nacin izvodjenja) private   -> (clan u potklasi) NIJE VIDLJIV
*/

/* ZAKLJUCAK:
  clanu klase koji je PRIVATE moze se direktno pristupati iz:
    1. metoda te klase
    2. prijateljskih funkcija te klase

  clanu klase koji je PROTECTED moze se direktno pristupati iz:
    1. metoda te klase
    2. prijateljskih funkcija te klase
    3. metoda potklasa te klase
  - konstruktori,destruktori i prijateljstvo se NE NASLEDJUJU
*/

class Osoba
{
	private:
		DinString ime, prezime;

	public:
		Osoba(const char* s1 = "", const char* s2 = "") : ime(s1), prezime(s2) { }

		Osoba(const DinString& ds1, const DinString& ds2) :	ime(ds1), prezime(ds2) { }

		Osoba(const Osoba& osoba) : ime(osoba.ime), prezime(osoba.prezime) { }

		void predstaviSe() const
		{
		    //preklapanje operatora je mehanizam pomocu kog "učimo" operator
            //kako da se ponasa ukoliko mu operandi budu objekti nekih klasa

		    //na ispis saljemo OBJEKTE klase DinString (ime, prezime)
            //to je moguce uraditi jer u klasi DinString imamo preklopljen operator ispisa "<<"
			cout << "Zovem se " << ime << " " << prezime << "." << endl;
		}

};

#endif
