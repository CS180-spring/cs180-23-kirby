#include <iostream>
#include <string>
#include "kirbydb.h"
#include "addsong.cpp"
#include "terminal.cpp"

using namespace std;

int main() {
    kirbydb database;
    string outputfile = "output.csv";
    int terminalinput = 10000; //some large value
    string userinput;
    Song* currentSongPointer; //Used to access current song pointer

    system("clear");
    cout << "Initialized KirbyDB database" << endl;
    cout << "Default Export File is output.csv" << endl;

    while(terminalinput > -10){ //arbitrary number to stay in loop
        terminalprint();
        cout << "\nThere are currently " << database.returnSongNum() << " songs in the database." << endl;
        cin >> terminalinput;
        if(terminalinput == 1){
            system("clear");
            addPrint();
            cin >> terminalinput;
            if(terminalinput == 1){
                system("clear"); //only works on linux systems
                cin.ignore();
                addonesong(database);
            }
            else if(terminalinput == 2){
                system("clear");
                cin.ignore();
                importfromfile(outputfile, database);
            }
            else{
                cout << "Invalid Option. Returning to Terminal." << endl;
            }
        }
        else if(terminalinput == 2){
            system("clear");
            cout << "Enter the name of the song to delete: " << endl;
            cin >> userinput;
            database.removeSong(userinput);
        }
        else if(terminalinput == 3){
            system("clear");
            cout << "Enter the name of the song to search: " << endl;
            cin >> userinput;
            if(database.searchSong(userinput)){
                currentSongPointer = database.returnSong(userinput);
                currentSongPointer->printParameters();
            }
            else{
                cout << "Song does not exist" << endl;
            }
        }
        else if(terminalinput == 4){
            //create playlist
        }
        else if(terminalinput == 6){
            database.listsonglist();
            cout << endl;
        }
        else if(terminalinput == 0){
            cout << "Exiting Program" << endl;
            break;
        }
    }

    return 0;
}