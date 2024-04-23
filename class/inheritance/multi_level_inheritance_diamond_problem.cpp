#include <iostream>
#include <string>

// Base class
class BasePokemon{
protected:
    std::string name;
    int hp;
    enum Type {ELECTRIC, FIRE} type;

public:
    BasePokemon(std::string name, int hp, Type type) : name(name), hp(hp), type(type) {}
    Type getType() const {return type;}
    int getHp() const {return hp;}
};

// sub-Base class
class ElectricPokemon : public BasePokemon{
public:
    int electricLevel;

    ElectricPokemon(std::string name, int hp, int electricLevel) : BasePokemon(name, hp, ELECTRIC), electricLevel(electricLevel) {}
};

class FirePokemon : public BasePokemon{
public:
    int flameLevel;

    FirePokemon(std::string name, int hp, int flameLevel) : BasePokemon(name, hp, FIRE), flameLevel(flameLevel) {}
};

// derived class (BasePokemon -> ElectricPokemon -> Pikachu)
class Pikachu : public ElectricPokemon{
public:
    std::string cry;
    Pikachu() : ElectricPokemon("Pikachu", 100, 10), cry("Pika pika!") {}
};

class Charmander : public FirePokemon{
public:
    int height;
    Charmander() : FirePokemon("Charmander", 200, 5), height(15) {}
};

class Pikamander : public ElectricPokemon, public FirePokemon{
public:
    Pikamander() : ElectricPokemon("Pikachu", 100, 10), FirePokemon("Charmander", 200, 5) {}
};

int main()
{
    using namespace std;

    Pikamander pikamander;
    cout << pikamander.getType() << endl;

    /*
    -> Since both ElectricPokemon and FirePokemon have members inherited from BasePokemon,
       Pikamander inherits BasePokemon's members multiple times
       In many cases, we may want to inherit the members of a common ancestor only once.

    multi_level_inheritance_diamond_problem.cpp: In function 'int main()':
    multi_level_inheritance_diamond_problem.cpp:55:24: error: request for member 'getType' is ambiguous
        cout << pikamander.getType() << endl;
                            ^~~~~~~
    multi_level_inheritance_diamond_problem.cpp:13:10: note: candidates are: 'BasePokemon::Type BasePokemon::getType() const'
        Type getType() const {return type;}
            ^~~~~~~
    multi_level_inheritance_diamond_problem.cpp:13:10: note:                 'BasePokemon::Type BasePokemon::getType() const'
    */

    return 0;
}