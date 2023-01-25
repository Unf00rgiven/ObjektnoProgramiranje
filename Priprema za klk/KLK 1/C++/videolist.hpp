#ifndef VIDEOLIST_HPP_INCLUDED
#define VIDEOLIST_HPP_INCLUDED

#include "list.hpp"
#include "video.hpp"

class VideoList{
    protected:
        List<Video> listaVidea;

    public:
        VideoList() : listaVidea() {}

        bool dodajVideo(Video& video){
            for(int i = 1; i<= listaVidea.size(); i++){
                Video pomocni;
                listaVidea.read(i, pomocni);

                if(pomocni.getNaziv() == video.getNaziv()){
                    return false;
                }
            }

            return listaVidea.add(listaVidea.size()+1, video);
        }

        bool obrisiVideo(const DinString& naziv){
            int indexZaBrisanje = -1;

            for(int i = 1; i <= listaVidea.size(); i++){
                Video pomocni;
                listaVidea.read(i, pomocni);

                if(pomocni.getNaziv() == naziv){
                    indexZaBrisanje = i;
                    break;
                }
            }

            if(indexZaBrisanje == -1)
                return false;
            else
                return listaVidea.remove(indexZaBrisanje);
        }
};

#endif // VIDEOLIST_HPP_INCLUDED
