#ifndef ARTIKAL_HPP_INCLUDED
#define ARTIKAL_HPP_INCLUDED

#include "dinstring.hpp"
#include <iomanip>

/* staticko polje je clan klase koji je zajednicki za sve njene objekte,
sto zanci da je u svakom trenutku njegova vrednost ista za sve instance te klase
- deklarise se pomocu rezervisane reci "static"
- ponasanje statickih polja je slicno ponasanju globalnih promenljivih;
razlika je u tome sto se staticka polja vezuju za klasu u kojoj su deklarisana
- staticka polja pripadaju klasi, ali ne i objektu */

/* staticko polje (u ovom zadatku) predstavljace broj instanci klase Artikal,
tj. ono ce biti deljeno izmedju objekata te klase
- svaki put kad napravimo novu instancu potrebno ga je inkrementirati: konstruktor -> ++
- svaki put kad se unisti neka instanca potrebno ga je dekrementirati: destruktor -> -- */

class Artikal{
    private:
        DinString naziv;
        double cena;
        static int instanci; //deklaracija statickog polja

    public:
        Artikal(const char[],const double);
        Artikal(const DinString&, const double);
        Artikal(const Artikal&);
        ~Artikal();

        DinString getNaziv()const;
        double getCena()const;

        friend ostream& operator<<(ostream& ,const Artikal&); //preklopljeni operator ispisa
};

#endif // ARTIKAL_HPP_INCLUDED
