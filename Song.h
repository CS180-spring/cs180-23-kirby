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
    string getName(){
        return name; //duplicate for jorge
    }
    string returnName(){
        return name;
    }
    string returnArtist(){
        return artist;
    }
    string returnAlbum(){
        return album;
    }
    string returnGenre(){
        return genre;
    }
};


#endif //CS180_23_KIRBY_SONG_H