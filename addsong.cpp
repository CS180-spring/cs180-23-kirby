#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


int importfromfile(string outputfile, int begin, vector<vector<string>>& content){
    string inputfile;
    cout << "Name of Input File: \n";
    cin >> inputfile;
    ifstream input(inputfile);
    while (!input) {
        cerr << "Error: Input File does not exist!" << endl;
        cin >> inputfile;
        ifstream input(inputfile);
    }
    
    vector<string> row;
    string line, word;

    //Read data from file, and add to vector
    if(begin != 0){
        getline(input, line);
    }
    while(getline(input, line)){
        row.clear();
        stringstream str(line);
        while(getline(str, word, ',')){
            row.push_back(word);
        }
        content.push_back(row);
    }
    

    cout << "\nSongs Imported \n" << endl;
    return 0;
}

// int manualadd(string outputfile, int begin, vector<vector<string>>& content){
//     string userinput;
//     string parameters;
//     vector<string> row;

//     if(begin == 0){
//         cout << "Please declare the parameters separated a newline. To end input, enter /" << endl;
//         cin >> userinput;
//         while(userinput != "/"){
//             row.push_back(userinput);
//             cin >> userinput;
//         }
//         content.push_back(row);
//     }
//     else{
//         for(int i = 0; i < content.size(); i++){
//             cout << "Insert " << content[0][i] << endl;
//             cin >> userinput;
//             row.push_back(userinput);
//         }
//         cout << "getting out of input loop" << endl;
//         content.push_back(row);
//     }

//     return 0;
// }