#include <iostream>
#include <string>

// Base class
class BasePokemon{
protected:
    std::string name;
    int hp;
    enum Type {ELECTRIC, FIRE, ELECTROFIRE} type;

public:
    BasePokemon(std::string name, int hp, Type type) : name(name), hp(hp), type(type) {}
    std::string getName() const {return name;}
    Type getType() const {return type;}
    int getHp() const {return hp;}
    virtual void attack(BasePokemon& opponent) = 0;
    /*
    Abstract Class is a class that cannot be instantiated directly and is designed to be subclasses.
    Includes at least one pure virtual function, which is a virtual function with no implementation and "= 0" at the end.
    A class inheriting from an abstract class must override all its pure virtual functions
    */
    void decreaseHp(int amount){
        hp -= amount;
    }
};

// sub-Base class
class ElectricPokemon : virtual public BasePokemon{
public:
    int electricLevel;

    ElectricPokemon(std::string name, int hp, int electricLevel) : BasePokemon(name, hp, ELECTRIC), electricLevel(electricLevel) {}
};

class FirePokemon : virtual public BasePokemon{
public:
    int flameLevel;

    FirePokemon(std::string name, int hp, int flameLevel) : BasePokemon(name, hp, FIRE), flameLevel(flameLevel) {}
};

// derived class (BasePokemon -> ElectricPokemon -> Pikachu)
class Pikachu : public ElectricPokemon{
public:
    std::string cry;
    Pikachu() : BasePokemon("Pikachu", 100, ELECTRIC), ElectricPokemon("Pikachu", 100, 10), cry("Pika pika!") {}
    void attack(BasePokemon& opponent) override
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
};

class Charmander : public FirePokemon{
public:
    int height;
    Charmander() : BasePokemon("Charmander", 200, FIRE), FirePokemon("Charmander", 200, 5), height(15) {}
    void attack(BasePokemon& opponent) override
    {
        if (opponent.getType()==FIRE)
        {
            opponent.decreaseHp(flameLevel + 2);
        }
        else
        {
            opponent.decreaseHp(flameLevel);
        }
    }
};

class Pikamander : public ElectricPokemon, public FirePokemon{
public:
    friend class Pikachu;   // A friend class is a class that is given special access to the private and protected members of another class
                            // May compromise the principle of encapsulation
    friend class Charmander;
    Pikamander() : BasePokemon("Pikamander", 300, ELECTROFIRE), ElectricPokemon("Pikamander", 200, 10), FirePokemon("Pikamander", 100, 5) {}
    void attack(BasePokemon& opponent) override
    {
        opponent.decreaseHp(electricLevel + flameLevel);
    }
};

int main()
{
    using namespace std;

    /*
    class ElectricPokemon : virtual public BasePokemon{
    class FirePokemon : virtual public BasePokemon{
    -> virtual inheritance : only one copy of the base class is inherited
    -> when the most derived class is instantiated it calls the base class's constructor.
    -> Only one copy of the members of the virtual base class is inherited
    */
    Pikachu pikachu;
    cout << pikachu.getType() << endl;

    Charmander charmander;
    cout << charmander.getType() << endl;

    Pikamander pikamander;
    cout << pikamander.getType() << endl;
    cout << pikamander.getHp() << endl; // base class를 선언할 때 할당된 hp에 값이 할당됨.
                                        // sub-base class를 선언할 때, base virtual inheritance에 의해 사용되지 않기 때문
    cout << pikamander.electricLevel << endl;
    cout << pikamander.flameLevel << endl;
    pikamander.attack(pikachu);
    std::cout << pikachu.getName() << " now has " << pikachu.getHp() << " HP left." << std::endl;

    return 0;
}