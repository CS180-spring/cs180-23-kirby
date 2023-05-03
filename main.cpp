#include <iostream>
#include <string>
#include "kirbydb.h"

using namespace std;

int main() {
    kirbydb database;
    string nameAdd = "Rap";
    database.addGenre(nameAdd);
    if(database.searchGenre(nameAdd)){
        cout << "Yes" << endl;;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}