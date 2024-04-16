#include <iostream>
#include <string>

int main()
{
    // Strings can be concatenated using the '+' operator
    std::string firstName = "Lee";
    std::string lastName = "Kwanwoo";

    std::string fullName = firstName + " " + lastName;
    
    std::cout << "fullName: " << fullName << std::endl;
    std::cout << std::endl;
    
    // String can be appended to another using the += operator or the append method.
    std::string name = "Oussama";
    name += " Khatib";
    std::cout << "Prof's name is " << name << std::endl;
    std::cout << std::endl;

    std::string name2 = "Shuji";
    name2.append(" Kajita");
    std::cout << "Biped legend is " << name2 << std::endl;

    return 0;
}