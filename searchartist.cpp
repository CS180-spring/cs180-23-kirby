#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void searchartist(vector<vector<string>>& content, string artist){
    // vector to store artist songs
    vector<string> row;
    // vector to show all artists songs
    vector<vector<string>> artistsongs;

    for(int i = 0; i < content.size(); i++){
        for(int j = 0; i < content[i].size(); i++){
            if(content[i][j] == artist){
                row.push_back(content[i][j]);
            }
            artistsongs.push_back(row);
        }
    }

    //print 
    for(int i = 0; i < artistsongs.size(); i++){
        for(int j = 0; i < artistsongs.size(); i++){
            cout << artistsongs[i][j] << endl;
        }
    }
    
}