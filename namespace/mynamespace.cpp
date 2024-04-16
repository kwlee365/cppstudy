#include <iostream>

namespace myNamespace{
    int a,b;

    // Within this namespace, these variables can be accessed using their identifies a and b.
    void setValues(int newValueA, int newValueB)
    {
        a = newValueA;
        b = newValueB;
    }
}

int main()
{
    // But, when accessed from outside the myNamespace namespace,
    // they must be explicitly qualified using the scope resolution operator ::
    myNamespace::a = 5;
    myNamespace::b = 3;

    std::cout << "a: " << myNamespace::a << std::endl;
    std::cout << "b: " << myNamespace::b << std::endl;
    myNamespace::setValues(10, 20);

    std::cout << "a: " << myNamespace::a << std::endl;
    std::cout << "b: " << myNamespace::b << std::endl;

    return 0;
}