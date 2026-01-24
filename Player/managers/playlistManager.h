#ifndef PLAYLIST_MANAGER_H
#define PLAYLIST_MANAGER_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "playlist.h"
#include "song.h"

class PlaylistManager{
private:
    unordered_map<string, Playlist> playlists;
    // maintain only a single instance for the manager
    static PlaylistManager* instance;
    PlaylistManager(){
        // can not be intialize
    }

public:
    static PlaylistManager* getInstance(){
        if(instance == nullptr){
            return new PlaylistManager();
        }
        else[
            return instance;
        ]
    }

    // add playlist
    void addPlaylist(string name){
        playlists[name] = new Playlist();
    }

    // add song to the playlist
    void addSongToPlaylist(string playlistName, Song song){
        if(map.find(playlistName) != map.end()){
            return;
        }

        playlists[playlistName].addSong(song);
    }

    Playlist* getPlaylist(string playlistName) const {
        return playlists[playlistName];
    }

}