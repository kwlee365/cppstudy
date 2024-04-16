#include <iostream>

void mySwap(int &x, int &y) // int &x, int &y : reference parameters
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 10, b = 20;

    std::cout << "[Before] a: " << a << " ,b: " << b << std::endl;
    mySwap(a,b);
    std::cout << "[After] a: " << a << " ,b: " << b << std::endl;

    // [Before] a: 10 ,b: 20
    // [After] a: 20 ,b: 10
    // A reference is passed to the actual argument.
    // Potential for uninteded modifications to original data.

    //////////////////////////////////////////
    // Call by Reference - Const References //
    // void mySwap(const int &x, const int &y)
    // Passing arguments by const reference allows functions to access the original data without the ability to modify it.
    
    // Note: Avoids copying large data structures, reducing memory usage and processing time!!!
    return 0;
}