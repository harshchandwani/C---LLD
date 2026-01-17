#include <iostream>
#include "./models/Restaurant.h"
using namespace std;

int main(){
    Restaurant* res = new Restaurant("Harsh", "ludhiana");
    cout<<res->getLoc()<<endl;
    cout<<res->getName()<<endl;

    
    return 0;
}