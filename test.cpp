#include <iostream>
#include <string>
#include "kirbydb.h"
#include "addsong.cpp"

using namespace std;

int main() {
    kirbydb database;
    cout << "Creating a new song called Monsters by Imagine Dragon" << endl;
    string songName = "Monsters";
    string artistName = "Imagine Dragons";
    string albumName = "Single";
    string genreName = "Pop";
    database.addSong(songName, artistName, albumName, genreName);
    Song* currentSongPointer = database.returnSong(songName);
    cout << "Song Pointer Created." << endl;
    currentSongPointer->printParameters();
    cout << "Add a new song (custom)" << endl;
    addonesong(database);
    cout << "How many songs are in the database right now?" << endl;
    cout << database.returnSongNum() << endl;
    cout << "What was the song name?" << endl;
    cin >> songName;
    currentSongPointer = database.returnSong(songName);
    currentSongPointer->printParameters();
    cout << "Deleting Song Monsters(with a typo)" << endl;
    songName = "Monstrs";
    database.removeSong(songName);
    cout << "How many songs are in the database right now?" << endl;
    cout << database.returnSongNum() << endl;
    return 0;
}