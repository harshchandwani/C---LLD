#include <iostream>

using namespace std;

class IImage{
public:
    virtual void display() = 0;
};

class RealImage : public IImage {
private:
    string fileName;

public:
    RealImage(string fileName){
        this->fileName = fileName;
        cout<<"This is creating a new file"<<endl;
    }

    void display() override {
        cout<<"Here is the file"<<fileName<<endl;
    }
};

class ProxyImage : public IImage {
private:
    RealImage* realImage;
    string fileName;
public:
    ProxyImage(string fileName){
        this->fileName = fileName;
        this->realImage = nullptr;
    }

    void display() override {
        if(!realImage){
            this->realImage = new RealImage(this->fileName);
        }
        realImage->display();
    }
};

int main(){
    IImage* img = new ProxyImage("Photot.jppg");
    img->display();
    img->display();

    return 0;
}