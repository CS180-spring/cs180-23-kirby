//
// Created by Jorge Aguilar on 4/25/23.
//
#include "Genre.h"

void Genre::addArtist(string& artistName, string& album, string& song){
    if(this->artist[artistName]){
        this->artist[artistName]->addAlbum(string& albumName, string& songName);
        return;
    }
    artist[artistName] = new Artist(artistName);
    artist[artistName]->addAlbum(string& albumName, string& songName);
    return;
}
