#include <iostream>
using namespace std;

// Target class: what client is expecting
class Shape{
public:
    virtual void draw() = 0;
    virtual ~Shape() {};
};

// Legacy model
class LegacyRectangle{
public:
    void draw(int width, int height){
        cout<<"drawing rectangle of height "<<height<<" and width"<<width<<endl;
    }
};

// Adapter 
class Adapter: public Shape{
private:
    LegacyRectangle* rec;
public:
    Adapter(LegacyRectangle* rec){
        rec = rec;
    };

    // override draw
    void draw() override {
        // translate shape into rectangle
        rec->draw(1,1);
    }
};

int main(){
    // intialize legacy
    LegacyRectangle* rec = new LegacyRectangle();
    Shape* adapter = new Adapter(rec);

    adapter->draw();

    delete adapter;
    delete rec;

    return 0;
}