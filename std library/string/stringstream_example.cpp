#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::stringstream parser("42,3.14,Hello World");

    int intValue;
    double doubleValue;
    std::string strValue;
    char ignoreChar; // used to ignore the commas.

    std::cout << parser.str() << std::endl; // .str() : stringstream -> string

    parser >> intValue >> ignoreChar >> doubleValue >> ignoreChar;
    std::getline(parser, strValue);

    std::cout << "intValue: " << intValue << std::endl;
    std::cout << "doubleValue: " << doubleValue << std::endl;
    std::cout << "strValue: " << strValue << std::endl;

    return 0;
}