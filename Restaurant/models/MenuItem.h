#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
using namespace std;

class MenuItem {
private:
    string code;
    string name;
    int price;

public:
    MenuItem(string code, string name, int price){
        this->code = code;
        this->name = name;
        this->price = price;
    }

    ~MenuItem(){
        cout<<"Destroying Menu"<<endl;
    }

    // getters and setters
    string getCode() const {
        return this->code;
    }

    void setCode(string& code){
        this->code = code;
    } 

    string getName() const {
        return this->name;
    }

    void setName(string& name){
        this->name = name;
    }

    int getPrice() const {
        return this->price;
    }

    void setPrice(int& price){
        this->price = price;
    }  
};

#endif // MENUITEM_H