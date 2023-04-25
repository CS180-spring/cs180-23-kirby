//
// Created by Jorge Aguilar on 4/25/23.
//

void Album::addSong(string& songName, int& trackNumber){
    if(songs[songName]){
        cout << "Song Already Available. Nothing Addded." << endl;
        return;
    }
    songs[songName] = new Song(songName, trackNumber);
    return
}