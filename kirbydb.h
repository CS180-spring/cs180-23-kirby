#ifndef _kirbydb_h_
#define _kirbydb_h_
using namespace std;
#include <string>
#include <locale>
#include <unordered_map>
#include <vector>
#include "Song.h"
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
class kirbydb
{
private:
    unsigned int songnum;
    unordered_map<string, Song *> songlist;
    unordered_map<string, vector<Song *>> playlist;

public:
    // Functions to be implemented
    kirbydb(){
        songnum = 0;
    }
    ~kirbydb() {}
    void listsonglist();
    void addSong(string songName, string artistName, string albumName, string genreName);
    Song *returnSong(string songname){
        unordered_map<string, Song *>::iterator got = songlist.find(songname);
        return got->second;
    }
    void removeSong(string songName);
    int returnSongNum();
    bool searchSong(string songName);
    bool searchArtist(string artistName);
    bool searchAlbum(string albumName);
    void printArtist(string artist);
    void printAlbum(string album);
    void exportsonglist(string filename);
    void exportplaylist()
    {
        ofstream output;
        output.open("dbplaylists.csv");
        for (auto x : playlist)
        {
            output << x.first;

            for (auto y : x.second)
            {

                output << "," << y->returnName();
            }
            output << endl;
        }
    }
    void addPlaylist(){
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

    void nooutputaddPlaylist(vector<string> importlist)
    {
        string playlistName = importlist[0];
        string currentsong;
        vector<Song *> newPlaylist;
        for (int i = 1; i < importlist.size(); i++)
        {
            currentsong = importlist[i];
            if (searchSong(currentsong))
            {
                newPlaylist.push_back(returnSong(currentsong));
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
                playlist[userinput] = oldPlaylist->second;
            }
            else
            {
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
        string choice; // called it this since userinput was used as param
        string outputfile = "output.csv";
        vector<Song *> currPlaylist;
        // currPlaylist = this->playlist[userinput];

        if (playlist.count(userinput))
        {
            cout << "Would you like to add a song from the database or import from file" << endl;
            cin >> choice;
            if (choice == "add")
            {
                // cin.ignore();
                // listsonglist();
                // getline(cin, userinput);
                // currPlaylist.push_back(returnSong(userinput));
                cin.ignore();
                while (true)
                {
                    cout << endl;

                    listsonglist();
                    cout << "Enter the name of the song to add or enter 'done' to finish: " << endl;

                    getline(cin, choice);

                    if (choice == "done")
                    {
                        break;
                    }
                    else if (searchSong(choice))
                    {
                        this->playlist[userinput].push_back(returnSong(choice));
                    }
                    else
                    {
                        system("clear");
                        cout << "Song or Command Does Not Exist" << endl;
                    }
                }
            }

            /*
            else if (userinput == "import")
            {
                cin.ignore();
                // importfromfile(outputfile, database);
                currPlaylist.push_back(returnSong(userinput));
            }
            */
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
    void modifyPlaylistSongOrder()
    {
        char decision;
        int song1, song2;
        string userinput;
        if (playlist.size() == 0){
            cout << "No Playlist Created" << endl;
        }
        else{
            listPlaylist();
            cout << "Which playlist would you like to modify?" << endl;
            getline(cin, userinput);
            if (!playlist.count(userinput))
            {
                cout << "Playlist does not exist" << endl;
                return;
            }
            if (playlist[userinput].size() < 2)
            {
                cout << "Unable to modify playslist song order. At least two songs are required to modify playlist." << endl;
                return;
            }
            while (true)
            {
                listPlaylistSongs(userinput);
                cout << "Which songs would you like to change the order of? Enter '0' to end." << endl;
                cin >> song1;
                if(song1 == 0){
                    return;
                }
                cin >> song2;
                if (song2 == 0)
                {
                    return;
                }
                else if (song1 < 0 || song2 < 0 || song1 > playlist[userinput].size() || song2 > playlist[userinput].size())
                {
                    cout << "One or more of these entries does not exist. Please pick a track within the given playlit range ("
                        << 1 << "-" << playlist[userinput].size() << ")." << endl;
                }
                else
                {
                    swap(playlist[userinput][song1 - 1], playlist[userinput][song2 - 1]);
                    cout << "Done!" << endl;
                }
            }
        }
    }
    // Infers playlist already exists.
    void listPlaylistSongs(string currPlaylist)
    {
        cout << "Playlist: " << currPlaylist << endl;
        int count = 1;
        for (auto song : playlist[currPlaylist])
        {
            cout << " " << count++ << ". " << song->getName() << endl;
        }
    }
    void removePlaylistSong(string songname){
        for(auto i : playlist){
            auto ispresent = [&songname](Song * currSong) { return currSong->getName() == songname;};
            auto index = find_if(i.second.begin(), i.second.end(), ispresent);
            if(index != i.second.end()){
                i.second.erase(index);
                listPlaylistSongs(i.first);

            }
        }
        --songnum;
        songlist.erase(songname);
    }
};

#endif //kirbydh.h