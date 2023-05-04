//
// Created by Jorge Aguilar on 4/24/23.
//

#ifndef CS180_23_KIRBY_ALBUM_H
#define CS180_23_KIRBY_ALBUM_H
#include "Song.h"
#include <string>
#include <iostream>
#include <map>
class Album {
private:
    string name;
    map<int, string> songs;

public:
    string getAlbumName(){return name;}
    Album(string& albumName){
        name = albumName;
    }
    void addSong(string& songName, int& songNumber){
        if(songs.find(songNumber) == songs.end()){
            songs[songNumber] = songName;
        }
        else{
            cout << "Song Already Exists In Database! Nothing Done" << endl;
        }
    }
    void printAlbum(){
        cout << getAlbumName() << endl;
        if(songs.size() == 0){
            cout << "Album Empty" << endl;
            return;
        }
        for(auto currSong : songs){
            cout << currSong.first << ". " << currSong.second << endl;
        }
    }

};


#endif //CS180_23_KIRBY_ALBUM_H
