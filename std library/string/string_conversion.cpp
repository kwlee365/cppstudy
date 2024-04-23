#include <iostream>
#include <string>

int main()
{
    // std::stoi //
    // std::stod //
    std::string number = "4c2";
    int intNum = std::stoi(number); // string to integer
    double doubleNum = std::stod(number);   // string to double

    // Result : 4.

    std::cout << "intNum: " << intNum << std::endl;
    std::cout << "doubleNum: " << doubleNum << std::endl;

    // std::to_string //
    double doubleValue = 123.456;
    std::string doubleStr = std::to_string(doubleValue);

    std::cout << "doubleStr: " << doubleStr << std::endl;

    return 0;
}