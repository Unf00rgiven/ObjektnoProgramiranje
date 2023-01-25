#include "artikal.hpp"

int Artikal::instanci = 0; //inicijalizacija vrednosti statickog polja uvek se mora vrsiti van klase

Artikal::Artikal(const char n[], const double c) : naziv(n), cena(c){
    instanci++;
}

Artikal::Artikal(const DinString& n, const double c) : naziv(n), cena(c){
    instanci++;
}

Artikal::Artikal(const Artikal& a) : naziv(a.naziv), cena(a.cena){
    instanci++;
}

Artikal::~Artikal(){
    instanci--;
}

DinString Artikal::getNaziv() const{
    return naziv;
}

double Artikal::getCena() const{
    return cena;
}

/* setw(int param) - funkcija koja postavlja udaljenost od leve ivice terminala, tj. koristi se da se zauzme željena "sirina" ispisa na konzoli
                   - ocekuje celobrojni tip podatka
                   - nema povratnu vrednost
                   - nalazi se u iomanip biblioteci */

/* preklapanje operatora = mehanizam pomocu kog ucimo odredjeni operator kako da se ponasa u slucaju da su operandi objekti klasa
                         - postoje dva nacina preklapanja operatora (Zbirka, str 46, primer klase Complex):
                             1. metodom: =, +=, -=, *=, /=, ++
                             2. slobodnom funkcijom (prijateljskom funkcijom): +, -, *, /, ==, !=, <<, >> */

/* preklapanje operatora ispisa:
- ostream& je referenca na standardni izlaz
- parametri: gde saljemo, sta saljemo na ispis
- os je "izlazni bafer" koji treba napuniti podacima koje je neophodno ispisati
- pri pozivu ispisa na konzoli datog objekta klase Artikal ispisace se sledece informacije o objektu
koje smo "upisali" u objekat klase ostream os koji smo vratili na kraju metode: */
ostream& operator<<(ostream& os, const Artikal& a){
    os << "--------- ARTIKAL ------" << endl;
    os << setw(10)<<"NAZIV: " << a.naziv << endl;
    os << setw(10)<<"CENA: " << a.cena << endl;
    os << setw(10)<<"INSTANCI: " << a.instanci << endl;
    os << "------------------------" << endl << endl;

    return os;
}
