#include <iostream>
#include <iomanip>

int main()
{
    double number = 123456789.123456789;
    std::cout << std::setprecision(4) << std::scientific << number << std::endl;
    // 1.235e+08
    // Sometimes, a floating-point number is displayed in scientific notation

    std::cout << std::setprecision(4) << std::fixed << number << std::endl;
    // 123456789.1235
    // fixed ensures that numbers are displayed in fixed-point notation.

    return 0;
}