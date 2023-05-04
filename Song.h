//
// Created by Jorge Aguilar on 4/24/23.
//

#ifndef CS180_23_KIRBY_SONG_H
#define CS180_23_KIRBY_SONG_H
#include <string>
#include <iostream>
using namespace std;

class Song {
private:
    string name;
    string artist;
    string album;
    string genre;
public:
    Song(){}
    ~Song(){}
    Song(string songName, string artistName, string albumName, string genreName){
        name = songName;
        artist = artistName;
        album = albumName;
        genre = genreName;
        // number = trackNumber;
    }
    void printParameters(){
        cout << "Song Name: " << name << endl;
        cout << "Artist Name: " << artist << endl;
        cout << "Album Name: " << album << endl;
        cout << "Genre Name: " << genre << endl;
        // cout << "Track Number: " << number << endl;
    }
};


#endif //CS180_23_KIRBY_SONG_H
