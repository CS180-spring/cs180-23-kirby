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
    void addSong(string& songName, string& songNumber, string& artistName, string& albumName, string& genreName);
    void removeSong(string& genre, string& artist, string& album, string& song);
    bool searchSong(string& genre, string& artist, string& album, string& song);
    bool searchAlbum(string& genre, string& artist, string& album);
    bool searchArtist(string& genre, string& artist);
    bool searchGenre(string& genre){
        return genres.find(genre) != genres.end();
    }
    void printArtist(string& genreName, string& artistName);
    void addGenre(string& genreName);
    void addArtist(string& genreName, string& artistName);
    void addAlbum(string& genreName, string& artistName, string& albumName);
    void addSong(string& genreName, string& artistName, string& albumName, string& songName, int& songNumber);
};


#endif //CS180_23_KIRBY_KIRBYDB_H
