#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "./Restaurant.h"
#include "./Cart.h"
#include "./MenuItem.h"
#include "./User.h"

class Order{
private:
    int id;
    int orderId;
    Restaurant* restaurant;
    vector<MenuItem> menuItems;
    User user;
    int totalCost;
public:
    Order(){
        id = nullptr;
        restaurant = nullptr;
        menuItems = nullptr;
        user = nullptr;
        totalCost = 0;
    }

    int getOrderId() const {
        return this->id;
    }

    User* getUser() const {
        return this->user;
    }

    int getTotal() const {
        return this->totalCost;
    }

    vector<MenuItem> getMenuItem() const {
        return this->menuItems;
    }

    void setRestaurant(Restaurant* res){
        this->restaurant = res;
    }

    void addItems(vector<MenuItem> menuItem){
        for(auto it: menuItem){
            totalCost += it.getPrice();
        }

        this->menuItems = menuItem;
    }

    

};

int Order::orderId = 0;
#endif