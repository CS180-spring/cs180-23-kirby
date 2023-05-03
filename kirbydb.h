#ifndef CS180_23_KIRBY_KIRBYDB_H
#define CS180_23_KIRBY_KIRBYDB_H
using namespace std;
#include <unordered_map>
#include "Song.h"
class kirbydb {
private:
    unordered_map<string, Song*> songlist;
    unordered_map<string, Song*> artistlist;
    unordered_map<string, Song*> genrelist;
public:
    //Functions to be implemented
    void addSong(string songName, string artistName, string albumName, string genreName){
        Song* newSong = new Song(songName, artistName, albumName, genreName);
        songlist.insert({songName, newSong});
    }
    Song* returnSong(string songname){
        unordered_map<string,Song*>::iterator got = songlist.find (songname);
        return got->second;
    }
    //Haven't touched below this
    void removeSong(string songName, string artistName, string albumName, string genreName);
    bool searchSong(string songName, string artistName, string albumName, string genreName);
    bool searchAlbum(string genre, string artist, string album);
    bool searchArtist(string genre, string artist);
    bool searchGenre(string genre);
};


#endif //CS180_23_KIRBY_KIRBYDB_H
