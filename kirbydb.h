//
// Created by Jorge Aguilar on 4/25/23.
//

#ifndef CS180_23_KIRBY_KIRBYDB_H
#define CS180_23_KIRBY_KIRBYDB_H
using namespace std;
#include "Genre.h"
#include <vector>
class kirbydb {
private:
    vector<Genre*> genres;
public:
    void addSong(string genre, string artist, string album, string song, int trackNumber);
    void removeSong(string genre, string artist, string album, string song);
    bool searchSong(string genre, string artist, string album, string song);
    bool searchAlbum(string genre, string artist, string album);
    bool searchArtist(string genre, string artist);
    bool searchGenre(string genre){
        for(Genre* currGenre : genres){
            if(currGenre->getGenre() == genre){
                return true;
            }
        }
        return false;
    }
    void addGenre(string& name) {
        Genre* newGenre = new Genre(name);
    }
};


#endif //CS180_23_KIRBY_KIRBYDB_H
