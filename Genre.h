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
    
    void addArtist(string& artistName, string& album, string& song, int& trackNumber);

    Genre(string name){
        name = "default";
    }
    string getGenre(){
        return name;
    } //fixing rn
};


#endif //CS180_23_KIRBY_GENRE_H
