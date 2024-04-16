#include <iostream>
#include <limits>

int main()
{
    int number;
    std::cout << "Enter a number: ";

    if(!(std::cin >> number))
    {
        std::cout << "That was not a number!" << std::endl;
        std::cin.clear();   // clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
    }
    else
    {
        std::cout << "You entered " << number;
    }

    return 0;
}