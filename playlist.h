#ifndef CS180_23_KIRBY_PLAYLIST_H
#define CS180_23_KIRBY_PLAYLIST_H
#include <string>
#include <iostream>
using namespace std;

class Playlist {
private:
    string name;
    
public:
    Playlist(){}
    ~Playlist(){}
    Playlist(string playlistName){
        name = playlistName;
    }
    string getName(){
        return name;
    }
    void printParameters(){
        cout << "Playlist Name: " << name << endl;
    }
};


#endif //CS180_23_KIRBY_PLAYLIST_H
