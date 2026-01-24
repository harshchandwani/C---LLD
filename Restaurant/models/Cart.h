#ifndef CART_H
#define CART_H

#include <vector>
#include "./Restaurant.h"
#include "./MenuItem.h"
class Cart{
private:
    Restaurant* restaurant;
    vector<MenuItem> menuItems;
public:
    Cart(){
        this->restaurant = nullptr;
    }

    void addToCart(const MenuItem* item){
        menuItems.push_back(item);
    }

    int totalCost() const {
        int cost = 0;
        for(int i = 0; i < menuItems.size(); i++){
            cost += menuItems[i].getPrice();
        }

        return cost;
    }

    bool isEmpty(){
        return menuItems.size() == 0;
    }

    // getter and setters
    void setRestaurant(Restaurant* res){
        this->restaurant = res;
    }

    Restaurant getRestaurant() const {
        return this->restaurant;
    }

    const vector<MenuItem> getMenuItems() const {
        if(restaurant != nullptr){
            return this->menuItems;
        }
        else{
            return nullptr;
        }
    }




    
};

#endif