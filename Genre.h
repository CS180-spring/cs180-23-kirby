//
// Created by Jorge Aguilar on 4/24/23.
//

#ifndef CS180_23_KIRBY_GENRE_H
#define CS180_23_KIRBY_GENRE_H
#include "Artist.h"
#include <string>
#include <iostream>
#include <unordered_map>

class Genre {
    string name;
    unordered_map<string,Artist*> artists;
public:
    string getGenre(){return name;};
    void addArtist(string& artistName, string& album, string& song, int& trackNumber);

    Genre(string& name){
        this->name = name;
    }
};


#endif //CS180_23_KIRBY_GENRE_H
