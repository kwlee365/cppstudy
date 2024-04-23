#include <iostream>

////////////////
// Base Class //
class Pokemon{

protected:  // Accessed from derived classes but not from outside
    std::string name;
    int hp;
    enum Type {ELECTRIC, FIRE} type;    // user defined type that can take symbolic names

public:
    Pokemon(std::string name, int hp, Type type) : name(name), hp(hp), type(type) {}
    ~Pokemon() {}

    std::string getName() {return name;}
    int getHp() {return hp;}
    Type getType() {return type;}

    void decreaseHp(int amount){
        hp -= amount;
    }

    void attack(Pokemon& opponent){ // call by reference allows for taking an argument without copying the opponent object nor using a pointer
        std::cout << "[Base class] " << name << " attacks" << opponent.getName() << std::endl;
    }

};

///////////////////////
// Derived class (1) //
class Pikachu : public Pokemon{ // The Pikachu class inherits from the Pokemon class
    // Access control for inheritance
    // public : adhere to the same class level for each member in the base class
    // protected : increase the access level of public members in the base calss to protected
    // private : make all members in the base class private

    int electricLevel;  // without any access specifier, member are private by default
                        // Attributes that are declared in the base calss may not be declared again
                        // If a derived class declares a variable with the same name as one in the base class, the two are seperate variables.

public:
    Pikachu() : Pokemon("Pikachu", 100, ELECTRIC), electricLevel(10) {} // Calls a constructor of the base class explicitly within its initializer list
                                                                        // This cannot be done inside the body, because the base part should be initialized first
                                                                        // If no explicit call is made within the initializer list, the compiler attempts to call the base class's constructor implicitly.
    ~Pikachu() {}   // The base class destructor is not inherited.
                    // When a derived class object is destroyed, its own destructor is called first, followed by the base class's destructor
    
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

};

///////////////////////
// Derived class (2) //
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
};

int main()
{
    Pikachu pikachu;
    Charmander charmander;

    std::cout << "Pikachu's HP: " << pikachu.getHp() << std::endl;
    std::cout << "Charmander's HP: " << charmander.getHp() << std::endl;

    pikachu.attack(charmander);
    std::cout << "Pikachu's HP: " << pikachu.getHp() << std::endl;
    std::cout << "Charmander's HP: " << charmander.getHp() << std::endl;

    charmander.attack(pikachu);
    std::cout << "Pikachu's HP: " << pikachu.getHp() << std::endl;
    std::cout << "Charmander's HP: " << charmander.getHp() << std::endl;

    // Pikachu's HP: 100
    // Charmander's HP: 200
    // Pikachu's HP: 100
    // Charmander's HP: 192
    // Pikachu's HP: 93
    // Charmander's HP: 192
    // No call to base class's attack()!

    return 0;
}