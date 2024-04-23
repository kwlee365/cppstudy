#include <iostream>
#include <string>

int main()
{
    // Initialization 
    std::string str1;   // empty;
    std::string str2 = "String2";   // copy initialization
    std::string str3("String3");    // direct initialization

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;

    return 0;
}