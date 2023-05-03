#include <iostream>
#include <string>
#include "kirbydb.h"

using namespace std;

int main() {
    kirbydb database;
    cout << "Creating a new Genre called rap" << endl;
    string genreName = "rap";
    database.addGenre(genreName);
    cout << "Does it exist?: ";
    if(database.searchGenre(genreName)){
        cout << "Yes" << endl;;
    }
    else{
        cout << "No" << endl;
    }
    Genre* newData = database.returnGenre(genreName);
    cout << "Created new data to access genre object" << endl;
    newData->getGenre();

    return 0;
}