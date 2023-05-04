//
// Created by Jorge Aguilar on 4/24/23.
//

#ifndef CS180_23_KIRBY_GENRE_H
#define CS180_23_KIRBY_GENRE_H
#include "Artist.h"
#include <string>
#include <iostream>
#include <unordered_map>

class Genre {
    string name;
    unordered_map<string,Artist*> artists;
public:
    string getGenre(){return name;};
    Genre(string& name){
        this->name = name;
    }
    void addArtist(string& artistName){
        if(artists.find(artistName) != artists.end()){
            cout << "Artist Already Exists In Database!" << endl;
            return;
        }
        artists[artistName] = new Artist(artistName);
        return;
    }
    void addAlbum(string& artistName, string& albumName){
        if(artists.find(artistName) == artists.end()){
            artists[artistName] = new Artist(artistName);
        }
        artists[artistName]->addAlbum(albumName);
        return;
    }
    void addSong(string& artistName, string& albumName, string& songName, int& songNumber){
        if(artists.find(artistName) == artists.end()){
            artists[artistName] = new Artist(songName);
        }
        artists[artistName]->addSong(albumName, songName, songNumber);
    }
    void printArtist(string& artistName){
        if(artists.find(artistName) == artists.end()){
            cout << "Artist Not In Database." << endl;
        }
        artists[artistName]->printAlbums();
    }
    void printAlbum(string& artistName, string& artistAlbum){
        if(artists.find(artistName) == artists.end()){
            cout << "Artist Not In Database." << endl;
        }
        artists[artistName]->printAlbum(artistAlbum);
    }
    
};


#endif //CS180_23_KIRBY_GENRE_H
