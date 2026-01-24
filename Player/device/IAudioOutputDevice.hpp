#include <iostream>
#include "../models/song.h"

class IAudioOutputDevice{
public:
    virtual ~IAudioOutputDevice() {}
    virtual void playAudio(Song* song) = 0;
};