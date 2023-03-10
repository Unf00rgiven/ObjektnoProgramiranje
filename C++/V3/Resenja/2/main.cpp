#include "phdstudent.hpp"

int main(){

    const char *s1 = "Petar";
    const char *s2 = "Petrovic";
    const char *s3 = "Jovan";
    const char *s4 = "Jovanovic";

    DinString ds1(s1), ds2(s2), ds3(s3), ds4(s4);

    Osoba os1(s1,s2), os2(ds3,ds4), os3(os2);
    Student st1(s1, s2, 1234), st2(ds1, ds2, 1234), st3(os2, 1234), st4(st2);
    PhDStudent phds1(s1, s2, 1234, 8.56), phds2(ds1, ds2, 1234, 8.56), phds3(os3, 1234, 8.77), phds4(st3, 8.77), phds5(phds4);


    cout << "Direktno predstavljanje objekata" << endl;
    cout << endl;
    cout << "Osoba: " << endl;
    os1.predstaviSe();

    cout << endl;
    cout << "Student: " << endl;
    st1.predstaviSe();

    cout << endl;
    cout << "PhDStudent: " << endl;
    phds1.predstaviSe();

    return 0;

}
