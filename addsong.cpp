#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int manualadd(string outputfile, int begin){
    string userinput;
    string parameters;
    ofstream output;
    output.open(outputfile, ofstream::app);

    if(begin == 0){
        cout << "Please enter the parameters, separated by , and ending with a newline" << endl;
        cin >> userinput;
        output << userinput;
    }
    cout << "Insert Song, followed by a newline: " << endl;
    cin >> userinput;
    output << userinput;

    return 0;
}

int importfromfile(string outputfile, int begin){
    string inputfile;
    cout << "Name of Input File: \n";
    cin >> inputfile;
    ifstream input(inputfile);
    while (!input) {
        cerr << "Error: Input File does not exist!" << endl;
        cin >> inputfile;
        ifstream input(inputfile);
    }
    ofstream output;
    output.open(outputfile, ofstream::app);

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    // Write some data to the file
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
    //Export Changes to Output File
    for(int i = 0; i < content.size(); i++){
		for(int j = 0; j < content[i].size(); j++){
            if(j < content[i].size() - 1){
                output << content[i][j] << ",";
            }
            else{
                output << content[i][j] << endl;
            }
		}
	}
    

    // Close the file
    output.close();

    cout << "\nSongs Imported \n" << endl;
    return 0;
}