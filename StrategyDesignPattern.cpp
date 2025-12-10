#include <iostream>
using namespace std;

// Behavior interface
class MoveStrategy {
public:
    virtual void move() = 0;
    virtual ~MoveStrategy() {}
};

// Concrete behaviors
class WheelMove : public MoveStrategy {
public:
    void move() override {
        cout << "Moving with wheels\n";
    }
};

class SlideMove : public MoveStrategy {
public:
    void move() override {
        cout << "Sliding forward\n";
    }
};

// Context that uses a strategy
class ToyCar {
private:
    MoveStrategy* strategy;
public:
    ToyCar(MoveStrategy* s) : strategy(s) {}

    void setStrategy(MoveStrategy* s) {
        strategy = s;
    }

    void performMove() {
        strategy->move();
    }
};

int main() {
    WheelMove wheels;
    SlideMove slide;

    ToyCar car(&wheels);
    car.performMove();

    car.setStrategy(&slide);
    car.performMove();

    return 0;
}
