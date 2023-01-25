#include <iostream>

using namespace std;

#include "parking.hpp"

int Autobus::brojAutobusa=0;

int main()
{

    /// Klasa Vozilo je apstraktna - zato je ne testiramo u mainu

    /// Klasa Autobus
    cout<<endl<<"Autobus - test"<<endl;

    Autobus a;
    Autobus a1("NS 123", MOTORNO, 2007, 10);
    Autobus a2("NS 232", MOTORNO, 1999, 10);
    Autobus a3("BG 113", MOTORNO, 2009, 10);
    Autobus a4("SU 456", MOTORNO, 2003, 10);
    Autobus a5("NI 909", MOTORNO, 2009, 10);

    cout<<"Autobus a1 ";
    a1.voznoStanje()?cout<<"je u voznom stanju":cout<<"nije u voznom stanju";
    cout<<endl;
    cout<<a1<<endl;

    cout<<"----------------------------------"<<endl;

    /// Klasa Parking
    cout<<endl<<"Parking - test:"<<endl;
    Parking p("Ispred FTN-a");

    if (p.uparkiraj(a1)) cout<<"Parkiran!"<<endl; else cout<<"Nije parkiran..."<<endl;
    if (p.uparkiraj(a2)) cout<<"Parkiran!"<<endl; else cout<<"Nije parkiran..."<<endl;
    if (p.uparkiraj(a3)) cout<<"Parkiran!"<<endl; else cout<<"Nije parkiran..."<<endl;
    if (p.uparkiraj(a4)) cout<<"Parkiran!"<<endl; else cout<<"Nije parkiran..."<<endl;
    if (p.uparkiraj(a5)) cout<<"Parkiran!"<<endl; else cout<<"Nije parkiran..."<<endl;

    cout<<endl<<"Ispis novih"<<endl;

    p.ispisiNove();




    return 0;
}
