#ifndef VIDEO_HPP_INCLUDED
#define VIDEO_HPP_INCLUDED

#include "dinstring.hpp"

class Video{
    private:
        DinString naziv;
        int trajanje;
        DinString rezolucijaVidea;

    public:
        Video() : naziv(""), trajanje(0), rezolucijaVidea(""){}
        Video(const DinString& naz, int tr, const DinString& rez) : naziv(naz), trajanje(tr), rezolucijaVidea(rez) {}

        DinString getNaziv(){ return naziv; }
        int getTrajanje(){ return trajanje; }
        DinString getRezolucija(){ return rezolucijaVidea; }

        void setNaziv(DinString novNaziv){ naziv = novNaziv; }
        void setTrajanje(int novoTrajanje){ trajanje = novoTrajanje; }
        void setRezolucija(DinString novaRezolucija){ rezolucijaVidea = novaRezolucija; }
};

#endif // VIDEO_HPP_INCLUDED
