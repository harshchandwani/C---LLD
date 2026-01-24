#include <iostream>
#include <string>
#include "../models/song.h"
#include "../externalAPI/IAudioOutputDevice.hpp"
class AudioEngine{
private:
    Song* currentSong;
    bool songIsPaused;
public:
    AudioEngine(){
        currentSong = nullptr;
        songIsPaused = false;
    }

    string getCurrentSongTitle() const {
        if(currentSong){
            return currentSong;
        }
        else{
            return "";
        }
    }

    bool isPaused() const {
        return songIsPaused;
    }

    // play
    void play(IAudioOutputDevice* audioDevice, Song* song){
        if(song == nullptr){
            throw runtime_error("song can not be null or empty");
        }

        if(songIsPaused && song == currentSong){
            songIsPaused = false;
            cout<<"resuming old song"<<endl;
            audioDevice->playAudio(song);
        }

        currentSong = song;
        songIsPaused = false;
        cout<<"Adding new song to play"<<endl;
        audioDevice->playAudio(song);
    }
    // pause
    void pause(){
        if(currentSong == nullptr){
            cout<<"No song is playing"<<endl;
        }

        if(songIsPaused){
            cout<<"song is already paused"<<endl;
        }

        songIsPaused = true;
        cout<<"paused the current playing song"<<currentSong->getName()<<endl;
    }
};
