#include <iostream>
#include <iomanip>  // for setprecision

int main()
{
    double pi = 3.14159265;

    std::cout << "Pi: " << pi << std::endl; 
    // Pi: 3.14159

    std::cout << "Pi with 3 decimal places: " << std::setprecision(3) << pi << std::endl; 
    // Pi with 3 decimal places: 3.14
    // setprecision from iomanip sets the number of digits.
    
    std::cout << "Pi with 3 decimal places: " << std::setprecision(3) << std::fixed << pi << std::endl; 
    // Pi with 3 decimal places: 3.142
    // fixed together setprecision control the number of floating digits.

    return 0; 
 }