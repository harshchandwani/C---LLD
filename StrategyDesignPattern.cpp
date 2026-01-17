#include <iostream>
using namespace std;

// ----------------------
// Interfaces
// ----------------------
class Talk {
public:
    virtual void talk() = 0;
    virtual ~Talk() {};
};

class Walk {
public:
    virtual void walk() = 0;
    virtual ~Walk() {};
};

// ----------------------
// Concrete Strategies
// ----------------------
class Talkable : public Talk {
public:
    void talk() override { // 'override' is good practice in C++11+
        cout << "This robot can talk" << endl;
    }
};

class NoTalk : public Talk {
public:
    void talk() override {
        cout << "This robot can not talk" << endl;
    }
};

class Walkable : public Walk {
public:
    void walk() override {
        cout << "This robot can walk" << endl;
    }
};

class NoWalk : public Walk {
public:
    void walk() override {
        cout << "This robot can not walk" << endl;
    }
};

// ----------------------
// Context (The Robot)
// ----------------------
class Robot {
private:
    // FIX 1: Renamed variables to avoid collision with function names
    Walk* walkBehavior; 
    Talk* talkBehavior;

public:
    Robot(Walk* w, Talk* t) {
        this->walkBehavior = w;
        this->talkBehavior = t;
    }

    // Optional: Destructor to clean up memory if Robot owns the strategies
    ~Robot() {
        delete walkBehavior;
        delete talkBehavior;
    }

    void walk() {
        // Delegating to the specific strategy
        walkBehavior->walk(); 
    }

    void talk() {
        talkBehavior->talk();
    }
};

int main() {
    // We create strategies
    Talkable* talking = new Talkable();
    NoWalk* nowalking = new NoWalk();

    // We pass them to the robot
    Robot* robot = new Robot(nowalking, talking);

    robot->talk();
    robot->walk();

    // FIX 2: Clean up the robot 
    // (The Robot's destructor will clean up 'talking' and 'nowalking' for us)
    delete robot; 

    return 0;
}