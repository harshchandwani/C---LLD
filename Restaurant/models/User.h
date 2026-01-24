#ifndef USER_H
#define USER_H

#include "./Cart.h"
class User{
private:
    int id;
    int userId;
    string name;
    string address;
    Cart cart;
public:
    User(string name, string address){
        this->id = userId++;
        this->name = name;
        this->address = address;
        this->cart = new Cart();
    }

    ~User() {
        delete cart;
    }

    // getter and setter
    string getName() const {
        return this->name;
    }

    void setName(const sting name){
        this->name = name;
    }

    string getAddress() const {
        return this->address;
    }

    void setAddress(const string address){
        this->address = address;
    }

    Cart getCart(){
        return this->cart;
    }


};

int User::userId = 0;

#endif