#include <iostream>
#include "youtubeplaylist.hpp"

using namespace std;

int main()
{
    Video v1, v2("VideoName", 10, "1080p");
    v1.getNaziv();
    v1.getTrajanje();
    v1.getRezolucija();
    v1.setNaziv("NovNaziv");
    v1.setTrajanje(20);
    v1.setRezolucija("720p");

    VideoList list;
    list.dodajVideo(v1);
    list.dodajVideo(v2);
    list.obrisiVideo("NovNaziv");

    YoutubePlaylist yt1, yt2("Test", "TestAutor");
    yt2.dodajVideo(v1);
    yt2.dodajVideo(v2);
    yt2.najduziVideo();
    cout<<yt2<<endl;

    return 0;
}
