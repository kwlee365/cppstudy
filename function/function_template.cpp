#include <iostream>

// Function templates enable the creation of functions that can work with any data type
template <typename T>
void mySwap (T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 5;
    int b = 10;

    mySwap<int>(a, b);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    
    mySwap(a, b);   // function arguments are not always required when invoking templated function
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    

    return 0;
}