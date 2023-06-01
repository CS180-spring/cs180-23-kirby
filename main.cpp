#include <iostream>
#include <string>
#include "kirbydb.h"
#include "addsong.cpp"
#include "terminal.cpp"
int main()
{
    kirbydb database;
    string outputfile = "output.csv";

    int terminalinput = 10000; // some large value
    string buffertext;

    string dbfile = "kirbydb.csv";
    // int terminalinput = 10000; // some large value

    string userinput;
    Song *currentSongPointer; // Used to access current song pointer

    system("clear");
    dbinitialize(dbfile, database);
    playlistinitialize(database);
    cout << "Initialized KirbyDB database" << endl;
    cout << "Default Export File is output.csv" << endl << endl;

    while (terminalinput != 0)
    { // arbitrary number to stay in loop
        terminalprint();
        cout << "\nThere are currently " << database.returnSongNum() << " songs in the database." << endl;
        cin >> terminalinput;
        if (terminalinput == 1)
        {
            system("clear");
            addPrint();
            cin >> terminalinput;
            if (terminalinput == 1)
            {
                system("clear"); // only works on linux systems
                cin.ignore();
                addonesong(database);
            }
            else if (terminalinput == 2)
            {
                system("clear");
                cin.ignore();
                importfromfile(outputfile, database);
            }
            else
            {
                cout << "Invalid Option. Returning to Terminal." << endl;
            }
        }
        else if (terminalinput == 2)
        {
            system("clear");
            cout << "Enter the name of the song to delete: " << endl;
            cin.ignore();
            getline(cin, userinput);
            if(database.searchSong(userinput)){
                //Iterate through all playlist to ensure the song no longer exists anywhere
                database.removePlaylistSong(userinput);
                //Delete the song
                database.removeSong(userinput);
            }
            else{
                cout << "Song not found" << endl;
            }
        }
        else if (terminalinput == 3)
        {
            system("clear");
            searchPrint();
            cin.ignore();
            cin >> terminalinput;
            if(terminalinput == 1){
                cout << "Enter the name of the song to search: " << endl;
                cin.ignore();
                getline(cin, userinput);
                if(database.searchSong(userinput)){
                    currentSongPointer = database.returnSong(userinput);
                    currentSongPointer->printParameters();
                }
                else{
                    cout << "Song does not exist" << endl;
                }
            }
            else if(terminalinput == 2){
                cout << "Enter the name of the artist to search: " << endl;
                cin.ignore();
                getline(cin, userinput);
                // if(database.searchArtist(userinput)){
                database.printArtist(userinput);
                // }
                // else{
                //     cout << "Artist does not exist" << endl;
                // }
            }
            else if(terminalinput == 3){
                cout << "Enter the name of the album to search: " << endl;
                cin.ignore();
                getline(cin, userinput);
                // if(database.searchArtist(userinput)){
                database.printAlbum(userinput);
                // }
                // else{
                //     cout << "Artist does not exist" << endl;
                // }
            }
        }
        else if (terminalinput == 6)
        {
            cin.ignore();
            database.addPlaylist();
        }
        else if (terminalinput == 5)
        {
            cin.ignore();
            database.listPlaylist();
        }
        else if (terminalinput == 7)
        {
            cout << "Enter the name of the playlist to edit: " << endl;
            cin.ignore();
            getline(cin, userinput);
            database.modifyPlaylistSongs(userinput);
        }
        else if (terminalinput == 4)
        {
            database.listsonglist();
        }

        else if (terminalinput == 9)
        {

            database.exportsonglist(outputfile);
            database.exportplaylist();
            cout << "Songs Exported" << endl;
        }
        else if (terminalinput == 4)
        {
            database.listsonglist();
            cout << endl;
        }
        else if (terminalinput == 8)
        {
            cin.ignore();
            database.modifyPlaylistSongOrder();
            cout << endl;
        }
        else if (terminalinput == 0)
        {
            cout << "Exiting Program" << endl;
            break;
        }
        cout << "Press any key to continue" << endl;
        cin >> buffertext;
        system("clear");
    }
    database.exportsonglist(dbfile);
    return 0;
}
