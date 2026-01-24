#ifndef SONG_H
#define SONG_H
#include <iostream>
using namespace std;

class Song {
private:
    static int nextId;
    string name;
    string path;
    string artist;
public:
    Song(string name, string path, string artist){
        this->id = nextId++;
        this->name = name;
        this->path = path;
        this->artist = artist;
    }
    string getName() const {
        return this->name;
    }
};

int Song::nextId = 0;
#endif