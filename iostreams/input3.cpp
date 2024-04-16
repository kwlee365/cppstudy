#include <iostream>
#include <string>

int main()
{
    // For reading lines of text, using getline over "cin >>".
    std::string myStr;
    std::cout << "Enter the lines of text: ";
    std::getline(std::cin, myStr);
    std::cout << "Here is the lines that you wrote: ";
    std::cout << myStr;

    return 0;
}