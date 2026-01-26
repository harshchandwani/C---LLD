#include <iostream>

using namespace std;

class ISupportHandler{
protected:
    ISupportHandler* nextHandler;
public:
    ISupportHandler(){
        nextHandler = nullptr;
    }

    ~ISupportHandler(){

    }

    void setNextHandler(ISupportHandler* nextHandler){
        this->nextHandler = nextHandler;
    }
    virtual void handleRequest(int level){
        if(nextHandler != nullptr){
            nextHandler->handleRequest(level);
        }
        else{
            cout<<"We need to implement this"<<endl;
        }
    };
};

class SupportLevelOne : public ISupportHandler {
public:
    void handleRequest(int level){
        if(level <= 10){
            cout<<"Can handle the request"<<endl;
        }
        else{
            cout<<"Can not handle the request, passing it to the next handler"<<endl;
            ISupportHandler::handleRequest(level);
        }
    }
};

class SupportLevelTwo : public ISupportHandler {
public:
    void handleRequest(int level){
        if(level >= 10){
            cout<<"Can handle the request"<<endl;
        }
        else{
            cout<<"Can not handle the request, passing it to the next handler"<<endl;
        }
    }
};


int main(){
    SupportLevelOne* levelOne = new SupportLevelOne();
    SupportLevelTwo* levelTwo = new SupportLevelTwo();

    levelOne->setNextHandler(levelTwo);

    levelOne->handleRequest(10);
    levelOne->handleRequest(20);
    return 0;
}