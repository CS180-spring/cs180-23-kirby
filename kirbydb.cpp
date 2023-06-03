#include "kirbydb.h"

void kirbydb::listsonglist(){
    for (auto x : songlist){
        cout << x.first << endl;
    }
}

void kirbydb::addSong(string songName, string artistName, string albumName, string genreName){
    if(!searchSong(songName)){
        Song *newSong = new Song(songName, artistName, albumName, genreName);
        songlist[songName] = newSong;
        songnum++;
    }
    //Do nothing if song is a duplicate
}
void kirbydb::removeSong(string songName)
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
    // cout << "Song deleted." << endl;
}
int kirbydb::returnSongNum()
    {
        // Used to check if the database is empty
        return songnum;
    }

bool kirbydb::searchSong(string songName)
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
bool kirbydb::searchArtist(string artistName)
    {
        int songcount = 0;
        // cout << "Bool Search Artist: " << artistName << "." << endl;
        for (auto x : songlist)
        {
            if (x.second->returnArtist() == artistName)
            {
                cout << "Found Artist" << endl;
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

bool kirbydb::searchAlbum(string albumName)
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

void kirbydb::printArtist(string artist)
{
    if (searchArtist(artist))
    {
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
    else
    {
        cout << "Artist does not exist" << endl;
    }
}

void kirbydb::printAlbum(string album)
{
    if (searchAlbum(album))
    {
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
    else
    {
        cout << "Album does not exist" << endl;
    }
}

void kirbydb::exportsonglist(string filename)
{
    ofstream output;
    output.open(filename);
    for (auto x : songlist)
    {
        output << x.second->returnName() << "," << x.second->returnArtist() << "," << x.second->returnAlbum() << "," << x.second->returnGenre() << endl;
    }
}