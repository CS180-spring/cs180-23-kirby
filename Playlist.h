#ifndef CS180_23_KIRBY_PLAYLIST_H
#define CS180_23_KIRBY_PLAYLIST_H
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Song.h"
#include "kirbydb.h"
using namespace std;

class Playlist
{
private:
    string playlistName;
    unordered_map<string, vector<Song*>> playlist;
    kirbydb& db;
public:
    Playlist(string name){
        playlistName = name;
    }
    void addSong(string songName){
        Song* song = db.returnSong(songName);
        this->playlist[playlistName].push_back(song);
    }
};

#endif
