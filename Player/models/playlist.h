#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <vector>
#include "song.h"
using namespace std;

class Playlist {
private:
    static int nextId:
    string name;
    vector<Song> songs;
public:
    Playlist(string name){
        this->name = name;
    }

    void addSong(Song* song){
        songs.push_back(song);
    }  

    vector<Song> getSongs() const {
        return songs;
    }
};

int Playlist::nextId = 0;
#endif