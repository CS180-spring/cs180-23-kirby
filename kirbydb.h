//
// Created by Jorge Aguilar on 4/25/23.
//

#ifndef CS180_23_KIRBY_KIRBYDB_H
#define CS180_23_KIRBY_KIRBYDB_H
using namespace std;
#include "Genre.h"
#include <unordered_map>
class kirbydb {
private:
    unordered_map<string, Genre*> genres;
public:
    void listKirbyDB(){}
    void addSong(string genre, string artist, string album, string song, int trackNumber);
    void removeSong(string genre, string artist, string album, string song);
    bool searchSong(string genre, string artist, string album, string song);
    bool searchAlbum(string genre, string artist, string album);
    bool searchArtist(string genre, string artist);
    bool searchGenre(string genre){
        unordered_map<string, Genre*>::iterator foundgenre = genres.find (genre);
        if(foundgenre == genres.end()){
            return false;
        }
        else{
            return true;
        }
    }
    void addGenre(string& name) {
        Genre* newGenre = new Genre(name);
        genres.insert({name, newGenre});
    }
    Genre* returnGenre(string genre){
        unordered_map<string, Genre*>::iterator foundgenre = genres.find (genre);
        return (*foundgenre).second; //returns the genre found
    }
};


#endif //CS180_23_KIRBY_KIRBYDB_H
