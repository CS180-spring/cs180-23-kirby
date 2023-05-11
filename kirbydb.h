#ifndef CS180_23_KIRBY_KIRBYDB_H
#define CS180_23_KIRBY_KIRBYDB_H
using namespace std;
#include <unordered_map>
#include "Song.h"
#include "playlist.h"
class kirbydb {
private:
    unordered_map<string, Song*> songlist;
    unordered_map<string, Playlist*> playlistList;
    //Up for change below(Search by artist, genre)
    unordered_map<string, Song*> artistlist;
    unordered_map<string, Song*> genrelist;
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
    //void listplaylistlist(){
    //    for (auto x: playlistlist){
    //        cout << x.first << endl;
    //    }
    //}
    void addPlaylist(string playlistName){
        Playlist* newPlaylist = new Playlist(playlistName); 
        playlistList.insert({playlistName, newPlaylist});
        songnum++;
    }
    void addToPlaylist(string songName){
        if(playlistList.empty()){
            cout << "No playlist to add to!" << endl;
            return;
        }
        auto previousEntryIterator = std::prev(playlistList.end());

        Playlist* previousEntry = previousEntryIterator->second;
        previousEntryIterator->second = new Playlist(previousEntry->getName() + ", " + songName); 
    }
    bool searchAlbum(string genre, string artist, string album);
    bool searchArtist(string genre, string artist);
    bool searchGenre(string genre);
};


#endif //CS180_23_KIRBY_KIRBYDB_H
