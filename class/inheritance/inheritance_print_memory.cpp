#include <iostream>

// Base Class
class Pokemon{

protected: 
    std::string name;
    int hp;
    enum Type {ELECTRIC, FIRE} type;    

public:
    Pokemon(std::string name, int hp, Type type) : name(name), hp(hp), type(type) {}
    ~Pokemon() {}

    std::string getName() {return name;}
    int getHp() {return hp;}
    Type getType() {return type;}

    void decreaseHp(int amount){
        hp -= amount;
    }

    void attack(Pokemon& opponent){ 
        std::cout << "[Base class] " << name << " attacks" << opponent.getName() << std::endl;
    }

};

// Derived class (1)
class Pikachu : public Pokemon{ 
    int electricLevel;  

public:
    Pikachu() : Pokemon("Pikachu", 100, ELECTRIC), electricLevel(10) {} 
    ~Pikachu() {}   
    
    void attack(Pokemon& opponent)
    {
        if (opponent.getType()==FIRE)
        {
            opponent.decreaseHp(electricLevel - 2);
        }
        else
        {
            opponent.decreaseHp(electricLevel);
        }
    }

    void cry()
    {
        std::cout << "Pika Pika!" << std::endl;
    }

    void printMemory()
    {
        std::cout << "Pikachu: " << std::endl;
        std::cout << "this: " << this << std::endl;
        std::cout << "name: " << &name << std::endl;
        std::cout << "hp: " << &hp << std::endl;
        std::cout << "type: " << &type << std::endl;
        std::cout << "electricLevel: " << &electricLevel << std::endl;
        std::cout << "this size: " << sizeof(*this) << std::endl;
        std::cout << "name size: " << sizeof(name) << std::endl;
        std::cout << "hp size: " << sizeof(hp) << std::endl;
        std::cout << "type size: " << sizeof(type) << std::endl;
        std::cout << "electricLevel size: " << sizeof(electricLevel) << std::endl;
        std::cout << std::endl;
    }

};

// Derived class (2) 
class Charmander : public Pokemon {
    int flameLevel;

public:
    Charmander() : Pokemon("Charmander", 200, FIRE), flameLevel(5) {}
    ~Charmander() {}

    void attack(Pokemon& opponent){
        if (opponent.getType() == ELECTRIC)
        {
            opponent.decreaseHp(flameLevel + 2);
        }
        else
        {
            opponent.decreaseHp(flameLevel);
        }
    }

    void printMemory()
    {
        std::cout << "Charmander: " << std::endl;
        std::cout << "this: " << this << std::endl;
        std::cout << "name: " << &name << std::endl;
        std::cout << "hp: " << &hp << std::endl;
        std::cout << "type: " << &type << std::endl;
        std::cout << "flameLevel: " << &flameLevel << std::endl;
        std::cout << "this size: " << sizeof(*this) << std::endl;
        std::cout << "name size: " << sizeof(name) << std::endl;
        std::cout << "hp size: " << sizeof(hp) << std::endl;
        std::cout << "type size: " << sizeof(type) << std::endl;
        std::cout << "flameLevel size: " << sizeof(flameLevel) << std::endl;
        std::cout << std::endl;
    }

};

int main()
{
    Pikachu pikachu;
    Charmander charmander;

    pikachu.printMemory();
    charmander.printMemory();
    /*
    Pikachu: 
    this: 0x61fde0
    name: 0x61fde0
    hp: 0x61fe00
    type: 0x61fe04
    electricLevel: 0x61fe08
    this size: 48
    name size: 32
    hp size: 4
    type size: 4
    electricLevel size: 4

    Charmander:
    this: 0x61fdb0
    name: 0x61fdb0
    hp: 0x61fdd0
    type: 0x61fdd4
    flameLevel: 0x61fdd8
    this size: 48
    name size: 32
    hp size: 4
    type size: 4
    flameLevel size: 4

    When a class is instantiated, a contiguous memory block is allocated
    In this memory block, space for each attribute is allocated in the order they are declared within the class.
    */

    return 0;
}