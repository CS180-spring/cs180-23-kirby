#include <iostream>
#include <string>
#include "kirbydb.h"

using namespace std;

int main() {
    kirbydb database;
    cout << "Creating a new song called Monsters by Imagine Dragon" << endl;
    string songName = "Monsters";
    string artistName = "Imagine Dragons";
    string albumName = "Single";
    string genreName = "Pop";
    database.addSong(songName, artistName, albumName, genreName);
    Song* currentSongPointer
    return 0;
}