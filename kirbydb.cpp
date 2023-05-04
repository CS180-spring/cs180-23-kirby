//
// Created by Jorge Aguilar on 4/25/23.
//

#include "kirbydb.h"

void kirbydb::addGenre(string& genreName){
    if(!genres[genreName]){
        genres[genreName] = new Genre(genreName);
    }
    else{
        cout << "Genre Already Exists In Database! Nothing Done" << endl;
    }
    return;
}
void kirbydb::addArtist(string& genreName, string& artistName){
    if(!genres[genreName]){
        genres[genreName] = new Genre(genreName);
    }
    genres[genreName].addArtist(artistName);
    return;
}
void kirbydb::addAlbum(string& genreName, string& artistName, string& albumName){
    if(!genres[genreName]){
        genres[genreName] = new Genre(genreName);
    }
    genres[genreName].addAlbum(artistName, albumName);
    return;
}
void kirbydb::addSong(string& genreName, string& artistName, string& albumName, string& songName, string& songNumber){
    if(!genres[genreName]){
        genres[genreName] = new Genre(genreName);
    }
    genres[genreName].addSong(songName, songNumber, artistName, albumName);
    return;
}



