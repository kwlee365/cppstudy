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
        std::cout << "[Base class] " << name << " attacks " << opponent.getName() << std::endl;
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

////////////////////////
// Class substitution //
// Class substitution is a fundamental concept in OOP that allows objects of a derived class to be treated as objects of a base.
// A pointer to a base class can point to an object of its derived class and also access public members declared in the base class.
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
    Pokemon *pokemon1, *pokemon2;
    std::string pokemonName1, pokemonName2;

    std::cout << "Enter name for Pokemon 1 (Pikachu or Charmander): ";
    std::cin >> pokemonName1;
    pokemon1 = createPokemon(pokemonName1); // return 받은 것은 base class (= Pokemon)의 포인터, 실제로 가리키는 것은 derived class (= Pikachu)의 포인터
    if (pokemon1 == nullptr) {
        std::cout << "You typed the wrong pokemon name" << std::endl;
        return 0;
    }
    std::cout << "Enter name for Pokemon 2 (Pikachu or Charmander): ";
    std::cin >> pokemonName2;
    pokemon2 = createPokemon(pokemonName2);
    if (pokemon2 == nullptr) {
        std::cout << "You typed the wrong pokemon name" << std::endl;
        return 0;
    }
    std::cout << "Pokemon1: " << (*pokemon1).getName() << std::endl;
    std::cout << "Pokemon2: " << (*pokemon2).getName() << std::endl;

    pokemon1->attack(*pokemon2);
    std::cout << pokemon2->getName() << " now has " << pokemon2->getHp() << " HP left." << std::endl;

    pokemon2->attack(*pokemon1);
    std::cout << pokemon1->getName() << " now has " << pokemon1->getHp() << " HP left." << std::endl;
    
    delete pokemon1;
    delete pokemon2;

    /*
    [Base class] Pikachu attacksCharmander
    Charmander now has 200 HP left.
    [Base class] Charmander attacksPikachu
    Pikachu now has 100 HP left.
    -> Derived class의 attack() method가 호출되지 않은 것을 확인할 수 있음.
    -> attack() invokes the base class's method, not the derived classes' methods.
    -> How can we invoke a derived class's implementation of a method using a base class pointer?
    */
    
    return 0;
}