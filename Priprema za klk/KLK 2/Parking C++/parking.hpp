#ifndef PARKING_HPP_INCLUDED
#define PARKING_HPP_INCLUDED

#include "autobus.hpp"
#include "list.hpp"

class Parking
{
private:
    DinString naziv;
    List<Autobus*> parkirani;
public:
    Parking(const DinString& ime)
    {
        naziv=ime;
    }
    bool uparkiraj(Autobus& a)
    {
        if (a.voznoStanje())
        {
            return parkirani.add(parkirani.size()+1, &a);
        }
        return false;
    }

    void ispisiNove()
    {
        cout<<"Naziv "<<naziv<<endl<<endl;
        if (parkirani.empty())
        {
            cout<<"Parking je prazan!"<<endl<<endl;
            return;
        }
        Autobus *a;
        parkirani.read(1, a);
        int najmladji = a->getGodiste();

        for (int i=2; i<=parkirani.size(); i++)
        {
            parkirani.read(i, a);
            if (a->getGodiste()>najmladji)
            {
                najmladji=a->getGodiste();
            }
        }
        for (int i=1; i<=parkirani.size(); i++)
        {
            parkirani.read(i, a);
            if (a->getGodiste()==najmladji)
                cout<<*a<<endl;
        }

    }

};



#endif // PARKING_HPP_INCLUDED
