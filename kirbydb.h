#ifndef CS180_23_KIRBY_KIRBYDB_H
#define CS180_23_KIRBY_KIRBYDB_H
using namespace std;
#include <unordered_map>
#include "Song.h"
#include <fstream>
class kirbydb {
private:
    unordered_map<string, Song*> songlist;
    //Up for change below(Search by artist, genre)
    // unordered_map<string, Song*> artistlist;
    // unordered_map<string, Song*> genrelist;
    //
    unsigned int songnum;
public:
    //Functions to be implemented
    kirbydb(){
        songnum = 0;
    }
    ~kirbydb(){}
    void listsonglist(){
        for (auto x : songlist){
            cout << x.first << endl;
        }
    }
    void addSong(string songName, string artistName, string albumName, string genreName){
        Song* newSong = new Song(songName, artistName, albumName, genreName);
        songlist.insert({songName, newSong});
        songnum++;
    }
    Song* returnSong(string songname){
        unordered_map<string,Song*>::iterator got = songlist.find (songname);
        return got->second;
    }
    void removeSong(string songName){
        unordered_map<string,Song*>::iterator got = songlist.find (songName);
        if(got == songlist.end()){
            cout << "Song does not exist!" << endl;
            return;
        }
        //Found the song. Now delete it!
        Song* deletepointer = got->second;
        delete deletepointer;
        songlist.erase(songName);
        songnum--;
        cout << "Song deleted." << endl;
    }
    int returnSongNum(){
        //Used to check if the database is empty
        return songnum;
    }
    //Haven't touched below this
    bool searchSong(string songName){
        unordered_map<string,Song*>::iterator got = songlist.find (songName);
        if(got == songlist.end()){
            return false;
        }
        else{
            return true;
        }
    }
    bool searchArtist(string artistName){
        int songcount = 0;
        for(auto x : songlist){
            if(x.second->returnArtist() == artistName){
                // cout << "Found Artist" << endl;
                songcount++;
            }
        }
        if(songcount > 0){
            return true;
        }
        else{
            return false;
        }
    }
    bool searchAlbum(string albumName){
        int songcount = 0;
        for(auto x : songlist){
            if(x.second->returnAlbum() == albumName){
                // cout << "Found Album" << endl;
                songcount++;
            }
        }
        if(songcount > 0){
            return true;
        }
        else{
            return false;
        }
    }
    bool searchGenre(string genreName);

    void printArtist(string artist){
        if(searchArtist(artist)){
            cout << "Songs by " << artist << ": " << endl; 
            for (auto x : songlist){
                if(x.second->returnArtist() == artist){
                    cout << x.first << endl;
                }
                // cout << x.second->returnArtist() << endl;
            }
        }
        else{
            cout << "Artist does not exist" << endl;
        }
    }

    void printAlbum(string album){
        if(searchAlbum(album)){
            cout << "Songs by " << album << ": " << endl;
            for (auto x : songlist){
                if(x.second->returnAlbum() == album){
                    cout << x.first << endl;
                }
                // cout << x.second->returnArtist() << endl;
            }
        }
        else{
            cout << "Album does not exist" << endl;
        }
    }

    void exportsonglist(){
        ofstream output;
        output.open("output.csv");
        for (auto x : songlist){
            output << x.second->returnName() << "," << x.second->returnArtist() << ","<< x.second->returnAlbum() << "," << x.second->returnGenre() << endl;
        }
    }
};


#endif //CS180_23_KIRBY_KIRBYDB_H
