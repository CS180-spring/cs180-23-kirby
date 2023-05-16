#ifndef CS180_23_KIRBY_PLAYLIST_H
#define CS180_23_KIRBY_PLAYLIST_H

#include "Song.h"
#include <vector>
#include <string>
using namespace std;

class playList
{
private:
    string name;
    vector<Song *> songList;

public:
    playList() {}
    ~playList() {}
    playList(string pLname)
    {
        name = pLname;
    }
    void addsongtoP(Song *s)
    {
        }
};
#endif // CS180_23_KIRBY_PLAYLIST_H