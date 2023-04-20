#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "main.cpp"

// params being passed are the DB(kirby vector)
// and the strong title that we want to delete
void deleteSong(vector<vector<string>> &vect, string song)

{
    int check = 0 for (int i = 1; i < vect.size(); i++)
    {
        // comment
        if (song == vect[i][0])
        {
            vect.erase(vect.begin() + i);
            check = 1;
        }
    }
    if (check == 0)
    {
        cout << "sorry the entered song title does not exist in our database" << endl;
    }
}
