#include <iostream>
#include <iomanip>

int main()
{
    int number = 5;
    std::cout << std::setfill('0') << std::setw(8) << number << std::endl;
    // 00000005
    // setfill together with setw control the total width and the number of 0s for padding.
    return 0;
}