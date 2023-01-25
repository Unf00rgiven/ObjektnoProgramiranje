#ifndef STUDENT_DEF
#define STUDENT_DEF

#include "osoba.hpp"

/*izvedena klasa moze imati 3 vrste metoda:
    1. nasledjene ("as is" od roditelja)
    2. redefinisane (modifikovano ponasanje metode u odnosu na roditeljsku)
    3. nove (karakteristicne za potomka)
*/

class Student : public Osoba
{
	protected:
		int brojIndeksa;

	public:
		Student(const char* s1 = "", const char* s2 = "", int i = 0) : Osoba(s1, s2), brojIndeksa(i) { }

		Student(const DinString& ds1, const DinString& ds2, int i) : Osoba(ds1, ds2), brojIndeksa(i) { }

		Student(const Osoba& os, int i) : Osoba(os), brojIndeksa(i) { }

		Student(const Student& s) : Osoba((Osoba)s), brojIndeksa(s.brojIndeksa) { }

		void predstaviSe() const
		{
			Osoba::predstaviSe();
			//cout << "ime: " << ime << endl; //greska: private atribut u natklasi + publilc nasledjivanje -> atribut nije vidljiv u potklasi
			cout << "Broj mog indeksa je " << brojIndeksa << "." << endl;
		}
};

#endif
