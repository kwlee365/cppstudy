#include <iostream>
#include <string>

class BasePokemon{

protected:
    std::string name;
    int hp;

public:
    BasePokemon(std::string name, int hp) : name(name), hp(hp) {}
    virtual ~BasePokemon() {}
    int getHp() const {return hp;}
    std::string getName() const {return name;}
};

enum Type {ELECTRIC, FIRE};

class ElectricPokemon{

public:
    Type type;
    int electricLevel;

    ElectricPokemon(int level) : electricLevel(level), type(ELECTRIC) {}
    Type getType() {return type;}
};

class FirePokemon{

public:
    Type type;
    int flameLevel;

    FirePokemon(int level) : flameLevel(level), type(FIRE) {}
    Type getType() {return type;}
};

class Pikachu : public BasePokemon, public ElectricPokemon{ 
/* 
Multiple inheritance allows a derived class to inherit from multiple base classes
List all base classes to inherit from.
Pikachu inherits attributes and methods from both parents.
*/
public:
    std::string cry;
    Pikachu() : BasePokemon("Pikachu", 100), ElectricPokemon(10), cry("Pika Pika!") { }
};

class Charmander : public BasePokemon, public FirePokemon{  
/*
The constructor of the parent classes are called in the order in which they appear in the base class list
Not in the order they are listed in the derived class's constructor initialization list
Destructors are called in the reverse order of the construction calls
*/
public:
    int height;
    Charmander() : BasePokemon("Charmander", 200), FirePokemon(5), height(15){}
};

int main()
{
    Pikachu pikachu;
    Charmander charmander;

    using namespace std;

    cout << pikachu.getHp() << endl;    // BasePokemon
    cout << pikachu.electricLevel << endl;  // ElectricPokemon
    cout << pikachu.cry << endl;    // Pikachu

    cout << charmander.getHp() << endl; // BasePokemon
    cout << charmander.flameLevel << endl;  // FirePokemon
    cout << charmander.height << endl;  // Charmander

    return 0;
}