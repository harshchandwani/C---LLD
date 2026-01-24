#include <iostream>
using namespace std;
class BluetoothSpeakerAPI{
public:
    void playAudioViaBluetooth(const string& data){
        cout<<"PLaying the audio from bluetooth device"<<data<<endl;
    }
}