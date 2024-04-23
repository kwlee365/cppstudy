#include <iostream>
#include <string>
#define REG_ADDRESS 0x40021000

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

    /* (1) C-style type casting
    It can be problematic in C++ due to its lack of specificity */
    // ElectricPokemon* elecPokemon = new Pikachu();
    // Charmander* charmander = (Charmander*)elecPokemon;  // No compile-time error

    /*(2) Static cast
    it is a compile-time cast that performs an explicit conversion between compatible types.*/
    
    // double pi = 3.141592;    // Converting fundamental types
    // int intPi = static_cast<int>(pi); 
    // std::cout << "intPi: " << intPi << std::endl;

    // Pikachu pikachu;     // Upcasting in class hierarchies
    // ElectricPokemon* pokemon = static_cast<ElectricPokemon*>(&pikachu);
    
    // ElectricPokemon* elecPokemon = new Pikachu();    // Downcasting in class hierarchies
    // Pikachu* pikachu = static_cast<Pikachu*>(elecPokemon);
    // Pikamander* pikamander = static_cast<Pikamander*>(elecPokemon); // Wrong but would compile
    // Charmander* charmander = static_cast<Charmander*>(elecPokemon); // ERROR: invalid static_cast from type 'ElectricPokemon*' to type 'Charmander*'

    /*(3) Dynamic cast
    it is a runtime cast to convert pointers and references to related classes
    it checks the validity of a cast that might be difficult to check at compile time, especially a down cast
    if the cast fails, it returns null ptr or throws an exception
    if the source class or the destination class has no virtual table, dynamic_cast may not be used.
    if the upcasting or casting to unrelated types, dynamic_cast can be used but is unnecessary. */
    
    // ElectricPokemon* pokemon = new Pikachu();
    // Pikachu* pikachu = dynamic_cast<Pikachu*>(pokemon); 

    // Pikamander* pikamander = dynamic_cast<Pikamander*>(pokemon); 
    // if (pikamander) { std::cout << "type casting succeeds" << std::endl;}
    // else { std::cout << "type casting doesn't succeed" << std::endl;}

    /* (4) const cast
    const_cast removes the const qualifier from const pointers and references
    it can lead to undefined behavior compiler cahses */
    // const std::string str;
    // std::string& nonConstStr = const_cast<std::string&>(str);
    // nonConstStr.append("suffix");
    // std::cout << nonConstStr << std::endl;

    /* Reinterpret cast
    reinterpret_cast is used to convert a pointer type to another pointer type or convery pointers to or from integral types */
    std::cout << REG_ADDRESS << std::endl;
    uint32_t* reg = reinterpret_cast<uint32_t*>(REG_ADDRESS);
    std::cout << reg << std::endl;

    return 0;
}