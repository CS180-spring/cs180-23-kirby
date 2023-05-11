#include <iostream>
#include <string>
#include "kirbydb.h"
#include "addsong.cpp"
#include "terminal.cpp"

using namespace std;

int main() {
    kirbydb database;
    string outputfile = "output.csv";
    string terminalinput = "n/a"; //input, as long as it is not exit
    string userinput;
    Song* currentSongPointer; //Used to access current song pointer

    system("clear");
    cout << "Initialized KirbyDB database" << endl;
    cout << "Default Export File is output.csv" << endl;


    while(terminalinput != "exit"){ //arbitrary number to stay in loop
        newterminalprint();
        cin >> terminalinput;
        if(terminalinput == "add"){
            cin.ignore();
            addonesong(database);
        }
        else if(terminalinput == "import"){

            cin.ignore();
            importfromfile(outputfile, database);
        }
        else if(terminalinput == "delete"){
            cout << "Enter the name of the song to delete: " << endl;
            cin >> userinput;
            database.removeSong(userinput);
        }
        else if(terminalinput == "search"){
            searchPrint();
            cin >> terminalinput;
            if(terminalinput == "1"){
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
            else if(terminalinput == "2"){
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
            else if(terminalinput == "3"){
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
        else if(terminalinput == "4"){
            //create playlist
        }
        else if(terminalinput == "songlist"){
            database.listsonglist();
        }
        else if(terminalinput == "export"){
            database.exportsonglist();
            cout << "Songs Exported" << endl;
        }
        else if(terminalinput == "exit"){
            cout << "Exiting Program" << endl;
        }
        else if(terminalinput == "sizedb"){
            cout << "There are currently " << database.returnSongNum() << " songs in the database." << endl;
        }
        else{
            cout << "Invalid Input" << endl;
        }
    }

    return 0;
}