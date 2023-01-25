#ifndef AUTOBUS_HPP_INCLUDED
#define AUTOBUS_HPP_INCLUDED

#include "vozilo.hpp"

class Autobus: public Vozilo
{
private:
    int brojMesta;
    static int brojAutobusa;
public:
    Autobus():Vozilo()
    {
        brojMesta=20;
        brojAutobusa++;
    }
    Autobus(const DinString& rb, VrstaVozila v, int g, int bm):Vozilo(rb, v, g)
    {
        brojMesta=bm;
        brojAutobusa++;
    }
    ~Autobus()
    {
        brojAutobusa--;
    }
    bool voznoStanje()
    {
        if (godiste>2000)
            return true;
        return false;
    }
    friend ostream& operator<<(ostream& out, const Autobus& a)
    {
        out<<"Autobus: "<<endl;
        out<<"REG. BROJ: "<<a.regBr<<endl;
        out<<"VRSTA: ";
        switch (a.vrsta)
        {
        case LAKO:
            out<<"LAKO"<<endl;
            break;
        case MOTORNO:
            out<<"MOTORNO"<<endl;
            break;
        case TERETNO:
            out<<"TERETNO"<<endl;
            break;
        case PRIKLJUCNO:
            out<<"PRIKLJUCNO"<<endl;
            break;
        }
        out<<"GODISTE: "<<a.godiste<<endl;
        out<<"BROJ MESTA: "<<a.brojMesta<<endl;
        out<<"BROJ AUTOBUSA: "<<a.brojAutobusa<<endl;
        return out;


    }

};



#endif // AUTOBUS_HPP_INCLUDED
