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


    while(true){ //arbitrary number to stay in loop
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
            searchPrint();
            cin.ignore();
            cin >> terminalinput;
            if(terminalinput == 1){
                cout << "Enter the name of the song to search: " << endl;
                cin.ignore();
                addonesong(database);
            }
            else if(terminalinput == 2){
                cout << "Enter the name of the artist to search: " << endl;
                cin.ignore();
                importfromfile(outputfile, database);
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
        else if(terminalinput == 4){
            cin.ignore();
            database.addPlaylist();
            
        }
        else if(terminalinput == 5){
            cin.ignore();
            database.listPlaylist();
        }
        else if(terminalinput == 6){
            cout << "Enter the name of the playlist to edit: " << endl;
            cin.ignore();
            getline(cin, userinput);
            database.modifyPlaylistSongs(userinput);
        }
        else if(terminalinput == 7){
            database.listsonglist();
        }
        else if(terminalinput == 9){
            database.exportsonglist();
            cout << "Songs Exported" << endl;
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