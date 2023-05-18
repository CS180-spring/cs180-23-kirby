#ifndef CS180_23_KIRBY_KIRBYDB_H
#define CS180_23_KIRBY_KIRBYDB_H
using namespace std;
#include <string>
#include <locale>
#include <unordered_map>
#include <vector>
#include "Song.h"
#include <fstream>
#include <utility>
#include <iostream>
class kirbydb
{
private:
    unordered_map<string, Song *> songlist;
    unordered_map<string, vector<Song *> > playlist;
    // Up for change below(Search by artist, genre)
    unordered_map<string, Song *> artistlist;
    unordered_map<string, Song *> genrelist;

    //
    unsigned int songnum;

public:
    // Functions to be implemented
    kirbydb()
    {
        songnum = 0;
    }
    ~kirbydb() {}
    void listsonglist()
    {
        for (auto x : songlist)
        {
            cout << x.first << endl;
        }
    }
    void addSong(string songName, string artistName, string albumName, string genreName)
    {
        Song *newSong = new Song(songName, artistName, albumName, genreName);
        songlist[songName] = newSong;
        songnum++;
    }
    Song *returnSong(string songname)
    {
        unordered_map<string, Song *>::iterator got = songlist.find(songname);
        return got->second;
    }
    void removeSong(string songName)
    {
        unordered_map<string, Song *>::iterator got = songlist.find(songName);
        if (got == songlist.end())
        {
            cout << "Song does not exist!" << endl;
            return;
        }
        // Found the song. Now delete it!
        Song *deletepointer = got->second;
        delete deletepointer;
        songlist.erase(songName);
        songnum--;
        cout << "Song deleted." << endl;
    }
    int returnSongNum()
    {
        // Used to check if the database is empty
        return songnum;
    }
    // Haven't touched below this
    bool searchSong(string songName)
    {
        unordered_map<string, Song *>::iterator got = songlist.find(songName);
        if (got == songlist.end())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void addPlaylist()
    {
        string userinput;
        char decision;

        cout << "Enter the name of the playlist: " << endl;

        cin >> userinput;
        string playlistName = userinput;
        while (playlist.count(userinput))
        {
            cout << "Playlist by that name already exists. Do you want to modify the playlist instead? (y or n)" << endl;
            cin >> decision;
            if (decision == 'y')
            {
                modifyPlaylistName(userinput);
            }
            if (decision == 'n')
            {
                return;
            }
            cout << "Do you want to replace the current playlist? This cannot be undone. (y or n)" << endl;
            cin >> decision;
            if (decision == 'n')
            {
                cout << "Enter a different playlist name: " << endl;
                cin >> userinput;
            }
        }

        vector<Song *> newPlaylist;
        cin.ignore();
        while (true)
        {
            cout << endl
                 << endl;
            listsonglist();

            cout << "Enter the name of the song to add or enter 'done' to finish: " << endl;
            getline(cin, userinput);
            if (userinput == "done")
            {
                break;
            }
            else if (searchSong(userinput))
            {
                newPlaylist.push_back(returnSong(userinput));
            }
            else
            {
                system("clear");
                cout << "Song or Command Does Not Exist" << endl;
            }
        }
        this->playlist[playlistName] = newPlaylist;
    }

    void modifyPlaylistName(string playList)
    {
        string userinput;
        char decision;  
        
        if (playlist.count(playList))
        {
            cout << "Enter the new name of this playlist: ";
            getline(cin, userinput);

            if (!(playlist.count(userinput)))
            {
                auto oldPlaylist = playlist.find(playList);
                playlist.erase(oldPlaylist->first);
                playlist[userinput] =  oldPlaylist->second;
            }
            else{
                cout << "Playlist " << userinput << "already exists" << endl;
            }
        }
        else
        {
            cout << "Playlist " << playList << "does NOT exists" << endl;
        }
    }
    void modifyPlaylistSongs(string userinput)
    {
        char decision;
        string outputfile = "output.csv";
        vector<Song *> currPlaylist;
        if (playlist.count(userinput))
        {
            cout << "Would you like to add a song from the database or import from file" << endl;
            cin >> userinput;
            if (userinput == "add")
            {
                cin.ignore();
                listsonglist();
                getline(cin, userinput);
                currPlaylist.push_back(returnSong(userinput));
            }
            else if (userinput == "import")
            {
                cin.ignore();
                // importfromfile(outputfile, database);
                currPlaylist.push_back(returnSong(userinput));
            }
        }
        else
        {

            cout << "Playlist " << userinput << "does NOT exists" << endl;
        }
    }
    void listPlaylist()
    {
        if (playlist.size() == 0)
        {
            cout << "No Playlist Created" << endl;
        }
        for (auto x : playlist)
        {
            cout << x.first << ": " << endl;
            int num = 1;
            for (auto song : x.second)
            {
                cout << "   " << num++ << ". " << song->getName() << endl;
            }
        }
    }
    bool searchArtist(string artistName)
    {
        int songcount = 0;
        cout << "Bool Search Artist: " << artistName << "." << endl;
        for (auto x : songlist){
            if (x.second->returnArtist() == artistName){
                cout << "Found Artist" << endl;
                songcount++;
            }
        }
        if (songcount > 0){
            return true;
        }
        else{
            return false;
        }
    }
    bool searchAlbum(string albumName)
    {
        int songcount = 0;
        for (auto x : songlist)
        {
            if (x.second->returnAlbum() == albumName)
            {
                // cout << "Found Album" << endl;
                songcount++;
            }
        }
        if (songcount > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool searchGenre(string genreName);

    void printArtist(string artist)
    {
        if (searchArtist(artist)){
            cout << "Songs by " << artist << ": " << endl;
            for (auto x : songlist)
            {
                if (x.second->returnArtist() == artist)
                {
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
            cout << "Songs in " << album << ": " << endl;
            for (auto x : songlist)
            {
                if (x.second->returnAlbum() == album)
                {
                    cout << x.first << endl;
                }
                // cout << x.second->returnArtist() << endl;
            }
        }
        else{
            cout << "Album does not exist" << endl;
        }
    }

    void exportsonglist()
    {
        ofstream output;
        output.open("output.csv");
        for (auto x : songlist)
        {
            output << x.second->returnName() << "," << x.second->returnArtist() << "," << x.second->returnAlbum() << "," << x.second->returnGenre() << endl;
        }
    }

    void modifyPlaylistSongOrder(){
        char decision;
        int song1, song2;
        string userinput;
        listPlaylist();
        cout << "Which playlist would you like to modify?" << endl;
        getline(cin, userinput);
        if(!playlist.count(userinput)){
            cout << "Playlist does not exist" << endl;
            return;
        }
        if(playlist[userinput].size() < 2){
            cout << "Unable to modify playslist song order. At least two songs are required to modify playlist." << endl;
            return;
        }
        while(true){
            listPlaylistSongs(userinput);
            cout << "Which songs would you like to change the order of? Enter '0' to end." << endl;
            cin >> song1 >> song2;

            
            if(song1 == 0 || song2 == 0){
                return;
            }
            else if(song1 < 0 || song2 < 0 || song1 > playlist[userinput].size() || song2 > playlist[userinput].size()){
                cout << "One or more of these entries does not exist. Please pick a track within the given playlit range ("
                    << 1 << "-" << playlist[userinput].size() << ")." << endl;
            }
            else{
                swap(playlist[userinput][song1 - 1],playlist[userinput][song2 - 1]);
                cout << "Done!" << endl;
            }

        }
        
    }
    // Infers playlist already exists.
    void listPlaylistSongs(string currPlaylist){
        cout << "Playlist: " << currPlaylist << endl;
        int count = 1;
        for(auto song : playlist[currPlaylist]){
            cout << " " << count++ << ". " << song->getName() << endl;
        }
    }
};

#endif // CS180_23_KIRBY_KIRBYDB_H
