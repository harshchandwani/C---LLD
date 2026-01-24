#include <iostream>
#include "IAudioOutputDevice.hpp"
#include "../externalAPI/BluetoothSpeakerAPI.hpp"
#include "../models/song.h"
class BluetoothSpeakerAdapter: IAudioOutputDevice {
private:
    BluetoothSpeakerAPI* bluetoothSpeaker;
public:
    BluetoothSpeakerAdapter(BluetoothSpeakerAPI* api) {
        bluetoothSpeaker = api;
    }
    void playAudio(Song* song) override {
        bluetoothSpeaker->playAudioViaBluetooth(song->getName());
    }
}