#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void searchartist(vector<vector<string>>& content, string artist){
    // iterate through db
    for(int i = 0; i < content.size(); i++){
        for(int j = 0; j < content[i].size(); j++){
            // output specific row matching artist
            if(content[i][1] == artist){
                cout << content[i][1] << endl;
            }
        }
    }
}