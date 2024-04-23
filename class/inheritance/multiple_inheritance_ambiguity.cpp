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

class Pikamander : public BasePokemon, public ElectricPokemon, public FirePokemon{

public:
    Pikamander() : BasePokemon("Pikamander", 300), ElectricPokemon(10), FirePokemon(5) {}
};

int main()
{
    Pikamander pikamander;
    std::cout << "Pikamander's type: " << pikamander.getType() << std::endl;

    /*
    -> An ambiguity arises when multiple parents of a derived class have a member with the same name.

    multiple_inheritance_ambiguity.cpp: In function 'int main()':
    multiple_inheritance_ambiguity.cpp:48:54: error: request for member 'getType' is ambiguous
        std::cout << "Pikamander's type: " << pikamander.getType() << std::endl;
                                                        ^~~~~~~
    multiple_inheritance_ambiguity.cpp:36:10: note: candidates are: 'Type FirePokemon::getType()'
        Type getType() {return type;}
            ^~~~~~~
    multiple_inheritance_ambiguity.cpp:26:10: note:                 'Type ElectricPokemon::getType()'
        Type getType() {return type;}
            ^~~~~~~
    */

    return 0;
}