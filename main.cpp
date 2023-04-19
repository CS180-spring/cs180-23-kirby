#include <iostream>
#include "addsong.cpp"

using namespace std;


//The intent of this code is to #1 import a CSV file(a list of songs) and add it into the database(also a csv file); 
//There will be a way to manually add a song into the database too. 
//It does not currently account for duplicates. 
int main() {
    int begin = 0; //Represents the very first imported file; Otherwise, ignore the first line(Dictates the columns)
    int userinput = 1000;
    string outputfile;

    cout << "Enter the output file name (.csv)" << endl;
    cin >> outputfile;
    cout << endl;

    while(userinput > 0){
        userinput = 1000;
        cout << "Options: " << endl;
        cout << "1. Import from CSV File" << endl;
        cout << "2. Add a Song Manually" << endl;
        cout << "0 to Exit Program" << endl;
        cin >> userinput;
        
        if(userinput == 1){
            importfromfile(outputfile, begin);
            begin++;
        }
        if(userinput == 2){
            manualadd(outputfile, begin);
            begin++;
        }
        if(userinput == 0){
            cout << "Exiting Program" << endl;
        }
    }
    
    return 0;
}