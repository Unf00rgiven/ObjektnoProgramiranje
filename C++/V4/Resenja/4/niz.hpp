#ifndef NIZ_HPP_INCLUDED
#define NIZ_HPP_INCLUDED

#include <iostream>
using namespace std;

/* iznad naziva genericke klase potrebno je definisati njen sablon
- u tu svrhu koristi se kljucna rec "template" iza koje se definisu elementi sablona
- primer kako bismo definisali genericku klasu:
            template <class T, int D>
            class Klasa {};
*/

 /* Niz - genericka klasa koja opisuje opsti slucaj:
    1. tip elemenata = moze biti prost (int, double, char, ...), a moze biti i klasni tip (MojaKlasa), tj. tip T
    2. broj elemenata = proizvoljno, a maksimalno D elemenata */
template <class T, int D>
class Niz {
    private:
        T el[D]; //niz koji se zove el, ima maksimalno D elemenata, pri cemu su elementi niza tipa T
        int brEl; //polje koje reprezentuje trenutni broj elemenata u nizu (kao neki "indkes", tj. kolika je stvarna duzina niza)

    public:
        Niz() { brEl=0; } //konstruktor
        ~Niz() {} //destruktor

        int getBrEl() const { return brEl; } //metoda koja vraca trenutan broj elemenata u nizu

        T operator[](int i) const { return el[i]; } //operatorska metoda kojom se preklapa operator indeksiranja
        T& operator[](int i) { return el[i]; } //operatorska metoda kojom se preklapa operator indeksiranja

        Niz<T,D>& operator=(const Niz<T,D>&); //operatorska metoda kojom se preklapa operator = za dodelu vrednosti

        void printNiz() const; //metoda koja ispisuje elemente niza
        bool insertNiz(const T&); //metoda koja dodaje novi element u niz
};

/* iznad definicije svake od metoda u okviru kojih se manipulise elementima sablona,
potrebno je definisati sablon genericke klase
- to se postize koriscenjem kljucne reci "template" iz koje se definisu elementi sablona
*** VAZNO: to vazi ukoliko se deklaracija i definicija metode razdvajaju. Ako to nije slucaj,
tj. ako se metoda definise unutar tela genericke klase, nije potrebno definisati sablon. */

template <class T, int D>
Niz<T,D>& Niz<T,D>::operator=(const Niz<T,D>& rn) {
    for(brEl = 0; brEl < rn.brEl; brEl++)
        el[brEl] = rn[brEl];
    return *this;
}

template <class T, int D>
void Niz<T,D>::printNiz() const {
    cout << "( ";
    for(int i = 0; i < brEl - 1; i++)
        cout << el[i] << ", ";
    cout << el[brEl - 1] << " )" << endl;
}

template <class T, int D>
bool Niz<T,D>::insertNiz(const T& t) {
    if(brEl < D) {
        el[brEl] = t;
        brEl++;
        return true;
    }
    else
        return false;
}

//operatorska funkcija kojom se preklapa operator == za proveru jednakosti (izvan tela klase!)
template <class T, int D>
bool operator==(const Niz<T,D>& rn1, const Niz<T,D>& rn2) {
    if(rn1.getBrEl() != rn2.getBrEl())
        return false;
    for(int i = 0; i < rn1.getBrEl(); i++)
        if(rn1[i] != rn2[i])
            return false;
    return true;
}

//operatorska funkcija kojom se preklapa operator != za proveru nejednakosti (izvan tela klase!)
template <class T, int D>
bool operator!=(const Niz<T,D>& rn1, const Niz<T,D>& rn2) {
    if(rn1.getBrEl() != rn2.getBrEl())
        return true;
    for(int i = 0; i < rn1.getBrEl(); i++)
        if(rn1[i] != rn2[i])
            return true;
    return false;
}

#endif // NIZ_HPP_INCLUDED
