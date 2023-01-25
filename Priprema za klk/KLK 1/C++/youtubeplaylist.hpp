#ifndef YOUTUBEPLAYLIST_HPP_INCLUDED
#define YOUTUBEPLAYLIST_HPP_INCLUDED

#include "dinstring.hpp"
#include "videolist.hpp"

class YoutubePlaylist : public VideoList{
    private:
        DinString naziv;
        DinString autor;

    public:
        YoutubePlaylist() : naziv(""), autor("") {}
        YoutubePlaylist(const DinString& pNaziv, const DinString& pAutor) : naziv(pNaziv), autor(pAutor) {}

        int najduziVideo()const{
            if(listaVidea.empty()){
                return -1;
            }

            int indexMax = 1;
            Video max;
            listaVidea.read(indexMax, max);

            for(int i = 2; i <= listaVidea.size(); i++){
                Video pomocni;
                listaVidea.read(i, pomocni);

                if(pomocni.getTrajanje() > max.getTrajanje()){
                    indexMax = i;
                    listaVidea.read(i, max);
                }
            }

            return indexMax;
        }

        friend ostream& operator<<(ostream& out, const YoutubePlaylist& pl){
            out<<pl.naziv<<endl;
            out<<pl.autor<<endl;
            out<<pl.najduziVideo()<<endl<<endl;

            double prosecno = 0;
            for(int i = 1; i <= pl.listaVidea.size(); i++){
                Video pomocni;
                pl.listaVidea.read(i, pomocni);

                prosecno += pomocni.getTrajanje();
            }
            prosecno /= pl.listaVidea.size();

            for(int i = 1; i <= pl.listaVidea.size(); i++){
                Video pomocni;
                pl.listaVidea.read(i, pomocni);
                if(pomocni.getTrajanje() > prosecno){
                    out<<pomocni.getNaziv()<<endl;
                    out<<pomocni.getTrajanje()<<endl;
                    out<<pomocni.getRezolucija()<<endl<<endl;
                }
            }

            return out;
        }
};

#endif // YOUTUBEPLAYLIST_HPP_INCLUDED
