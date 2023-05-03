//
// Created by Jorge Aguilar on 4/25/23.
//

#include "kirbydb.h"

void kirbydb::addSong(string& genre, string& artist, string& album, string& song, int trackNumber){
    //Checks if genre exists. If it does, add song under genre
    for(auto currGenre : this->Genres){
        if(currGenre->name == genre){
            currGenre->addArtist(artist, album, song);
            return;
        }
    }
    //If genre does not exist, create a new genre and add song
    Genre* newGenre = new Genre(genre);
    newGenre->addArtist(artist, album, song, trackNumber);
    return;
}
