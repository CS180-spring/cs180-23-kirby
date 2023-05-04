#include <iostream>
#include <string>
#include "kirbydb.h"
// #include "addsong.cpp"

using namespace std;

int main() {
    kirbydb database;
    cout << "Creating a new song called Monsters by Imagine Dragon" << endl;
    string songName = "Monsters";
    string artistName = "Imagine Dragons";
    string albumName = "Single";
    string genreName = "Pop";
    int trackNumber = 1;
    database.addSong(genreName, artistName, albumName, songName, trackNumber);
    cout << "Printing Artist." << endl;
    database.printArtist(genreName, artistName);
    return 0;
}