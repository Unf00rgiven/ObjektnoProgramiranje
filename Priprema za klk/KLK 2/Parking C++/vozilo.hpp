#ifndef VOZILO_HPP_INCLUDED
#define VOZILO_HPP_INCLUDED

#include "dinstring.hpp"

enum VrstaVozila {LAKO, MOTORNO, TERETNO, PRIKLJUCNO};

class Vozilo
{
protected:
    DinString regBr;
    VrstaVozila vrsta;
    int godiste;
public:
    Vozilo():regBr(""), vrsta(LAKO), godiste(0) {}
    Vozilo(const DinString& rb, VrstaVozila v, int g):regBr(rb), vrsta(v), godiste(g) {}

    DinString getRegBr()const
    {
        return regBr;
    }
    int getGodiste()const
    {
        return godiste;
    }

    virtual bool voznoStanje()=0;

};



#endif // VOZILO_HPP_INCLUDED
