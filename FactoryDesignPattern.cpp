#include <iostream>
using namespace std;

class Toy {
public:
    virtual void play() = 0;
    virtual ~Toy() {}
};

class Car : public Toy {
public:
    void play() override {
        cout << "Car goes vroom\n";
    }
};

class Doll : public Toy {
public:
    void play() override {
        cout << "Doll says hi\n";
    }
};

// Factory: creates toys based on input
class ToyFactory {
public:
    static Toy* createToy(const string& type) {
        if (type == "car") {
            return new Car();
        } else if (type == "doll") {
            return new Doll();
        }
        return nullptr;
    }
};

int main() {
    Toy* t1 = ToyFactory::createToy("car");
    t1->play();

    Toy* t2 = ToyFactory::createToy("doll");
    t2->play();

    delete t1;
    delete t2;
    return 0;
}
