#include <iostream>

int main()
{
    int arr[3] = {1, 2, 3};

    std::cout << "arr: "  << arr << std::endl;
    std::cout << "*arr: " << *arr << std::endl;
    std::cout << "&(*arr): " << &(*arr) << std::endl;
    std::cout << "&arr: " << &arr << std::endl;

    // The name of a static array acts as a pointer to the first element.
    // An array name cannot change the address it points to
    // The name is not a variable that "stores" an address and there is no seperate "storage" for the address the name refers to
    // When attempting to print &arr, it prints the address of the entire array.
    
    return 0;
}