#include <iostream>

int main()
{
    int a = 5;
    int *aPtr = &a;

    std::cout << "&a: "    << &a << std::endl;
    std::cout << "aPtr: "  << aPtr << std::endl;
    std::cout << "a: "     << a << std::endl;
    std::cout << "*aPtr: " << *aPtr << std::endl;

    // Any pointer variable can be thought of as simply storing a memory address.
    // When the pointer type becomes important in the follwoing cases
    // 1. Dereference : How many bytes to read and how to interpret the bit pattern
    // 2. Arithmetic operations on pointers : How much to increase or decrease the address 
    // intPtr + 2 -> increases the address by 8 bytes (4 * 2)

    return 0;
}