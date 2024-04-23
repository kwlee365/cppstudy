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

int main()
{
    using namespace std;

    Pikachu pikachu;
    cout << pikachu.getHp() << endl;
    cout << pikachu.electricLevel << endl;
    cout << pikachu.cry << endl;

    Charmander charmander;
    cout << charmander.getHp() << endl;
    cout << charmander.flameLevel << endl;
    cout << charmander.height << endl;

    /*
    Constructor calls: BasePokemon -> ElectricPokemon -> Pikachu (상위 class에서 하위 class로)
    Destructor calls: Pikachu -> ElectricPokemon -> BasePokemon (상위 class에서 하위 class로)
    */

    return 0;
}