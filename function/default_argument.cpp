#include <iostream>

int divide (int a, int b= 2)
{
    int r = a/b;
    return r;
}

int main()
{
    std::cout << divide(12) << std::endl;
    std::cout << divide(20, 4) << std::endl;
}