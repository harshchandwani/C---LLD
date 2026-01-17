#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include <vector>
#include "../models/Restaurant.h"

class ResturantManager{
private:
    vector<Restaurant> restaurants;
    // will maintain a single instance for the managers
    static ResturantManager* instance;

    RestaurantManager(){
        // can not intialize
    }
public:
    static ResturantManager* getInstance(){
        if(!instance){
            return new RestaurantManager();
        }
        else{
            return instance;
        }
    }

    // add restaurant
    void addRestaurant(Restaurant* res){
        restaurants.push_back(res);
    }

    // search by loc
    vector<Restaurant*> searchByLoc(const string loc) const {
        vector<Restaurant*> res;
        for(auto it: restaurants){
            if(loc == it->getLoc()){
                res.push_back(it);
            }
        }

        return it;
    }
};


ResturantManager* ResturantManager::instance = nullptr;
#endif