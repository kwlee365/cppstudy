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

    // Virtual functions are member functions in a base class that can be overriden in derived classes
    // The 'virtual' keyword is used in a base class to indicate that a function is intended to be overriden in derived classes
    virtual void attack(Pokemon& opponent){ 
        std::cout << "[Base class] " << name << " attacks " << opponent.getName() << std::endl;
    }

};

// Derived class (1)
class Pikachu : public Pokemon{ 
    int electricLevel;  

public:
    Pikachu() : Pokemon("Pikachu", 100, ELECTRIC), electricLevel(10) {} 
    ~Pikachu() {}   
    
    // The 'override' keyword is applied to a function in a derived class to explicitly state that the function is intended to override a virtual function from the base class.
    void attack(Pokemon& opponent) override
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

    void attack(Pokemon& opponent) override
    {
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

Pokemon* createPokemon(std::string name){
    if (name == "Pikachu"){
        return new Pikachu();
    }
    else if (name == "Charmander"){
        return new Charmander();
    }
    else{
        return nullptr;
    }
}

int main()
{
    Pokemon *pokemon1 = new Pikachu();
    Pokemon *pokemon2 = new Charmander();

    pokemon1->attack(*pokemon2);
    std::cout << pokemon2->getName() << " now has " << pokemon2->getHp() << " HP left." << std::endl;

    pokemon2->attack(*pokemon1);
    std::cout << pokemon1->getName() << " now has " << pokemon1->getHp() << " HP left." << std::endl;
    
    /*
    Objects of derived class will invoke the overriding function, even when accessed through a base class reference or pointer.
    Charmander now has 192 HP left.
    Pikachu now has 93 HP left. 
    */   


    delete pokemon1;
    delete pokemon2;

    return 0;
}