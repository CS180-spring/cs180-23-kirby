#include <iostream>
#include <string>
#include "kirbydb.h"

using namespace std;

void terminalprint(){
    cout << "Options: " << endl;
    cout << "1. Add Song" << endl;
    cout << "2. Delete Song" << endl;
    cout << "3. Search Song" << endl;
    cout << "4. View all songs in database" << endl;
    cout << "5. View Playlist/s" << endl;
    cout << "6. Create Playlist" << endl;
    cout << "7. Edit Playlist" << endl;
    cout << "8. Change Playlist Song Order" << endl;
    cout << "9. Export Changes to File" << endl;
    cout << "0. Exit Program" << endl;
}

void addPrint(){
    cout << "1. Add Song Manually" << endl;
    cout << "2. Import Song from File" << endl;
}

void searchPrint(){
    cout << "1. Search by Song" << endl;
    cout << "2. Search by Artist" << endl;
    cout << "3. Search by Album" << endl;
}

