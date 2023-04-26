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
    int number;
public:
    string getName(){return name;}
    Song(string& songName, int& trackNumber){
        name = songName;
        number = trackNumber;
    }
};


#endif //CS180_23_KIRBY_SONG_H
