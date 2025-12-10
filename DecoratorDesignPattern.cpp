#include <iostream>

using namespace std;

// component interface: defines the interface for objects that can have responsibilities added to them dynamically
class Character {
public:
    virtual string getAbilities() const = 0;
    virtual ~Character() {} // virtual destructor
};

// concrete component: defines an object to which additional responsibilities can be attached
class BasicCharacter : public Character {
public:
    string getAbilities() const override {
        return "Basic Abilities";
    }
};

// Abstract Decorator: maintains a reference to a Character object and defines an interface that conforms to Character's interface
class CharacterDecorator : public Character {
protected:
    Character* character; // pointer to the component being decorated
public:
    CharacterDecorator(Character* charac){
        this->character = charac;
    }
};

class HeightUpDecorator: public CharacterDecorator {
public:
    HeightUpDecorator(Character* charac) : CharacterDecorator(charac) {}

    string getAbilities() const override {
        return character->getAbilities() + ", Height Up";
    }
};

class PowerUpDecorator: public CharacterDecorator {
public:
    PowerUpDecorator(Character* charac): CharacterDecorator(charac) {}
    string getAbilities() const override {
        return character->getAbilities() + ", Power Up";
    }
};

int main(){
    Character* myCharacter = new BasicCharacter();
    cout<< "Initial Abilities: " << myCharacter->getAbilities() << endl;

    myCharacter = new HeightUpDecorator(myCharacter);
    cout<< "After Height Up: " << myCharacter->getAbilities() << endl;

}