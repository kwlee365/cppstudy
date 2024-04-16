#include <iostream>
#include <string>

template <typename T1, typename T2>
void printPair(T1 a, T2 b)
{
    std::cout << "(" << a << ", " << b << ")" << std::endl;
}

int main()
{
    printPair<double, std::string>(2.5, "orange");
    printPair(2.5, "orange");

    return 0;
}