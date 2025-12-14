#include <iostream>
using namespace std;

class Command{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() {};
};
class Light{
public:
    void on(){
        cout<<"Light turned on"<<endl;
    }

    void off(){
        cout<<"Turn the light off"<<endl;
    }
};

class LightCommand: public Command{
private:
    Light* light;
public:

    LightCommand(Light* light){
        light = light;
    }
    void execute(){
        light->on();
    }
    void undo(){
        light->off();
    }
};



class RemoteController{
    private: 
        static const int num = 4;
        Command* commands[num];
        int status[num];
    public:
        RemoteController(){
            for(int i = 0; i < num; i++){
                commands[i] = nullptr;
                status[i] = false;
            }
        }

        // set command
        void setCommand(int index, Command* command){
            if(index < 0 || index >= num) return;
            commands[index] = command;
        }

        void pressButton(int index){
            if(index < 0 || index >= num){
                return;
            }

            if(status[index] == false){
                commands[index]->execute();
            }
            else{
                commands[index]->undo();
            }
        }

        ~RemoteController(){
            for(int i = 0; i < num; i++){
                commands[i] = nullptr;
                status[i] = false;
            }
        }
};

int main(){
    Light* light = new Light();
    RemoteController* remoteController = new RemoteController();
    remoteController->setCommand(0, new LightCommand(light));

    // turn on light
    remoteController->pressButton(0);
}
