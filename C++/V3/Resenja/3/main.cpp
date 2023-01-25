#include "phdstudent.hpp"

//sta god prosledili uvek ispisuje samo roditeljski deo -> parametar prosledjen po VREDNOSTI
/*ako se objekat ne prosledi preko reference slobodnoj funkciji, tada ce rezultat poziva metode
specifikacije uvek biti isti bez obzira na tip objekta koji se salje
(pozvace se metoda specifikacije iz osnovne klase)*/
void predstavljanje1(Osoba osoba)
{
    cout << "Predstavljanje 1: ";
    osoba.predstaviSe();
}

//parametar prosledjen po REFERENCI -> VIRTUALNOST dolazi do izrazaja
/*u zavisnosti od stvarnog tipa objekta koji se prosleduje slobodnoj funkciji preko reference,
takav će biti i rezultat poziva metode specifikacije*/
void predstavljanje2(const Osoba &osoba)
{   // virtual void predstaviSe() const -> ispis svih polja
    // void predstaviSe() const -> ispis samo roditeljskog dela
    cout << "Predstavljanje 2: ";
    osoba.predstaviSe();
}


int main(){

	const char *s1 = "Petar";
	const char *s2 = "Petrovic";
	const char *s3 = "Jovan";
	const char *s4 = "Jovanovic";

    DinString ds1(s1), ds2(s2), ds3(s3), ds4(s4);

    Osoba os1(s1,s2), os2(ds3,ds4), os3(os2);
    Student st1(s1, s2, 1234), st2(ds1, ds2, 1234), st3(os2, 1234), st4(st2);
    PhDStudent phds1(s1, s2, 1234, 8.56), phds2(ds1, ds2, 1234, 8.56), phds3(os3, 1234, 8.77), phds4(st3, 8.77);


    cout << "Direktno predstavljanje objekata" << endl; //pozivaju se redefinisane metode -> razlicit ispis
    cout << endl;
    cout << "Osoba: " << endl;
    os1.predstaviSe();

    cout << endl;
    cout << "Student: " << endl;
    st1.predstaviSe();

    cout << endl;
    cout << "PhDStudent: " << endl;
    phds1.predstaviSe();


    cout << endl << endl;
    cout << "Predstavljanje objekata preko funkcije" << endl;
    cout << endl;

    cout << "Osoba:" << endl;
    predstavljanje1(os1); //prenos po vrednosti
    predstavljanje2(os1); //prenos po referenci -> virtualnost dolazi do izrazaja

    cout << endl;
    cout << "Student:" << endl;
    predstavljanje1(st1); //prenos po vrednosti
    predstavljanje2(st1); //prenos po referenci -> virtualnost dolazi do izrazaja

    cout << endl;
    cout << "PhDStudent:" << endl;
    predstavljanje1(phds1); //prenos po vrednosti
    predstavljanje2(phds1); //prenos po referenci -> virtualnost dolazi do izrazaja

    // testirati i kad metod nije virtualan

    // ukoliko metoda predstaviSe() nije virtuelna, tada nema razlike u ispisu:
    // obe slobodne funkcije (i predstavljanje1 i predstavljanje2) daju isti rezultat
    // bez obzira na to da li se parametar prenosi po vrednosti ili po referenci

    return 0;

}
