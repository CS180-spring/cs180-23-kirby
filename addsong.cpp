#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int importfromfile(string outputfile, kirbydb &database)
{
    string inputfile;
    // cout << "Name of Input File: \n";
    cin >> inputfile;
    ifstream input(inputfile);
    while (!input)
    {
        cout << "Error: Input File does not exist!" << endl;
        cout << "You typed: " << inputfile << endl;
        cin >> inputfile;
        ifstream input(inputfile);
    }
    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    // Read data from file, and add to vector
    while (getline(input, line))
    {
        row.clear();
        stringstream str(line);
        while (getline(str, word, ','))
        {
            row.push_back(word);
        }
        content.push_back(row);
    }
    // Content is now inside vector. Add to database
    for (int i = 0; i < content.size(); i++)
    {
        database.addSong(content[i][0], content[i][1], content[i][2], content[i][3]);
        // cout << content[i][0] << content[i][1] << content[i][2] << cooontent[i][3] << endl;
    }
    cout << "Songs Imported" << endl;
    return 0;
}

void addonesong(kirbydb &database)
{ // pass in by reference
    string songname, artistname, albumname, genrename;
    cout << "Insert Song Information:" << endl;
    cout << "Insert Song Name:" << endl;

    getline(cin, songname);

    cout << "Insert Song Artist:" << endl;
    getline(cin, artistname);
    cout << "Insert Song Album:" << endl;
    getline(cin, albumname);
    cout << "Insert Song Genre:" << endl;
    getline(cin, genrename);
    database.addSong(songname, artistname, albumname, genrename);

    return;
}

// void exportfromfile(kirbydb &database){
//     ofstream output;
//     output.open("output.csv");
//     cout << "Export Changes to file \n" << endl;
//             for (auto x : songlist){
//                 output <<
//             }
// }
