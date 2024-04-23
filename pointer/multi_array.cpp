#include <iostream>

int main()
{
    int arr[2][2] = {1,2,3,4};

    std::cout << "arr[0][0]: " << arr[0][0] << std::endl;
    std::cout << "arr[0][1]: " << arr[0][1] << std::endl;
    std::cout << "arr[1][0]: " << arr[1][0] << std::endl;
    std::cout << "arr[1][1]: " << arr[1][1] << std::endl;

    std::cout << "&arr[0][0]: " << &arr[0][0] << std::endl;
    std::cout << "&arr[0][1]: " << &arr[0][1] << std::endl;
    std::cout << "&arr[1][0]: " << &arr[1][0] << std::endl;
    std::cout << "&arr[1][1]: " << &arr[1][1] << std::endl;

    // A multi-dimensional static array is also allocated in a contiguous memory block.
    return 0;
}