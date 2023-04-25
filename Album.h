//
// Created by Jorge Aguilar on 4/24/23.
//

#ifndef CS180_23_KIRBY_ALBUM_H
#define CS180_23_KIRBY_ALBUM_H
#include "Song.h"
#include <string>
#include <iostream>
#include <unordered_map>
class Album {
private:
    string name;
    int releaseYear;
    unordered_map<string, Song*> songs;

public:
    string getAlbumName(){return name;}
    int getReleaseYear(){return releaseYear;}
    void addSong(string& songName);

};


#endif //CS180_23_KIRBY_ALBUM_H
