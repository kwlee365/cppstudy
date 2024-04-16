#include <iostream>

void mySwap(int x, int y)
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
    // [After] a: 10 ,b: 20
    // Because, x, y, temp in the mySwap are local variables.
    return 0;
}