//
// Created by Jorge Aguilar on 4/24/23.
//

#ifndef CS180_23_KIRBY_ARTIST_H
#define CS180_23_KIRBY_ARTIST_H
#include "Album.h"
#include <string>
#include <iostream>
#include <vector>
#include<unordered_map> 

class Artist {
private:
    string name;
    unordered_map<string, Album*> albums;
public:
    Artist(string& name){
        this->name = name;
    }
    string getArtist(){return name;};
    void addAlbum(string& albumName){
        if(!albums[albumName]){
            albums[albumName] = new Album(albumName);
        }
        else{
            cout << "Album Already Exists In Database! Nothing Done." << endl;
        }
    }
    void addSong(string& albumName, string& songName, int& songNumber){
        if(!albums[albumName]){
            albums[albumName] = new Album(albumName);
        }
        albums[albumName]->addSong(songName, songNumber);
    }
    void printAlbums(){
        for(auto currAlbum : albums){
            currAlbum.second->printAlbum();
        }
    }
    void printAlbum(string& albumName){
        for(auto currAlbum : albums){
            currAlbum.second->printAlbum();
        }
    }
};


#endif //CS180_23_KIRBY_ARTIST_H
