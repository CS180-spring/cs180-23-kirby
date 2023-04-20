#include <iostream>
#include "kirbydb.h"
#include "searchartist.cpp"

using namespace std;

//Reads CSV files, store data inside a vector.
//Does not account for duplicates.
int main() {
    kirbydb database;
    string nameAdd = "Rap";
    database.addGenre(nameAdd);
    if(database.searchGenre(nameAdd)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
//    int begin = 0; //Represents the very first imported file; Otherwise, ignore the first line(Dictates the columns)
//    int userinput = 1000;
//    string outputfile;
//    vector<vector<string>> kirbydb;
    //Database Vector. All data is stored via kirbydb[i][j]. 
    //i is the row #, while j is the words in said row.

    //Default Output File = output.csv
//    ofstream output;
//    output.open("output.csv");
//
//    while(userinput > 0){
//        userinput = 1000;
//        cout << "Options: " << endl;
//        cout << "1. Import from CSV File" << endl;
//        // cout << "2. Add a Song Manually" << endl;
//        cout << "9. Export Changes to file" << endl;
//        cout << "0 to Exit Program" << endl;
//        cin >> userinput;
//
//        if(userinput == 1){
//            importfromfile(outputfile, begin, kirbydb);
//            begin++;
//        }
//        // if(userinput == 2){
//        //     manualadd(outputfile, begin, kirbydb);
//        //     begin++;
//        // }
//        if(userinput == 9){
//            cout << "Export Changes to file \n" << endl;
//            for(int i = 0; i < kirbydb.size(); i++){
//		        for(int j = 0; j < kirbydb[i].size(); j++){
//                    if(j < kirbydb[i].size() - 1){
//                        output << kirbydb[i][j] << ",";
//                    }
//                    else{
//                        output << kirbydb[i][j] << endl;
//                    }
//		        }
//	        }
//        }
//    }
//
//    // Close the file
//    output.close();
    
    return 0;
}