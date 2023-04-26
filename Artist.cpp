//
// Created by Jorge Aguilar on 4/24/23.
//

#include "Artist.h"

void Artist::addAlbum(string& albumName, string& songName, int& trackNumber){
    for(auto album : albums){
        if(album->getAlbumName() == albumName){
            album->addSong(string& songName);
        }
    }
}