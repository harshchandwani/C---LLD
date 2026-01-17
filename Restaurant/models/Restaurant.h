#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <vector>
#include "MenuItem.h"
using namespace std;

class Restaurant {
private:
    static int nextRestaurantId;
    int id;
    string name;
    string loc;
    vector<MenuItem> menuItems;

public:
    Restaurant(const string& name, const string& loc){
        this->id = nextRestaurantId++;
        this->name = name;
        this->loc = loc;
    }

    ~Restaurant(){
        cout<<"Destroying Restaurant"<<endl;
        menuItems.clear();
    }

    // getters and setters
    string getName() const {
        return this->name;
    }

    void setName(const string& name) {
        this->name = name;
    }

    string getLoc() const {
        return this->loc;
    }

    void setLoc(const string& loc){
        this->loc = loc;
    }

    vector<MenuItem> getMenuItems(){
        return this->menuItems;
    }

    void addMenuItem(const MenuItem &item) {
        menuItems.push_back(item);
    }
};


// this is called when we intialize the class
int Restaurant::nextRestaurantId = 0;
#endif