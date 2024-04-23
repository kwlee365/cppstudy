#include <iostream>

int main()
{
    int arr[3] = {1,2,3};

    // Static arrays are fixed-size arrays whose size is known at compile time.
    // A contiguous memory block is allocated on the stack.
    std::cout << "arr[0]: " << arr[0] << std::endl;
    std::cout << "arr[1]: " << arr[1] << std::endl;
    std::cout << "arr[2]: " << arr[2] << std::endl;

    std::cout << "&arr[0]: " << &arr[0] << std::endl;
    std::cout << "&arr[1]: " << &arr[1] << std::endl;
    std::cout << "&arr[2]: " << &arr[2] << std::endl;

    return 0;
}