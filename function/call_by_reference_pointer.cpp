#include <iostream>

void mySwap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 10, b = 20;

    std::cout << "[Before] a: " << a << " ,b: " << b << std::endl;
    mySwap(&a,&b);
    std::cout << "[After] a: " << a << " ,b: " << b << std::endl;

    // [Before] a: 10 ,b: 20
    // [After] a: 20 ,b: 10

    // The address of an argument is passed to a function, 
    // allowing direct access and modification of the original variable 
    return 0;
}