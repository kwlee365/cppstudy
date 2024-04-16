#include <iostream>

int main()
{
    // cout infers the output format from the type of the output data.
    int age = 5;

    std::cout << age << std::endl;
    // 5
    std::cout << &age << std::endl;
    // 0x61fe1c
    std::cout << "Hello world! " << std::endl;
    // Hello world!


    return 0;
}