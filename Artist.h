//
// Created by Jorge Aguilar on 4/24/23.
//

#ifndef CS180_23_KIRBY_ARTIST_H
#define CS180_23_KIRBY_ARTIST_H
#include "Album.h"
#include <string>
#include <iostream>
#include <vector>

class Artist {
private:
    string name;
    vector<Album*> albums;
public:
    Artist(string& name){
        this->name = name;
    }
    string getArtist(){return name;};
    void addAlbum(string& albumName, string& songName, int& trackNumber);
};


#endif //CS180_23_KIRBY_ARTIST_H
