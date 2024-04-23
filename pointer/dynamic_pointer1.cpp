#include <iostream>

int main()
{
    // (1) //
    int *aPtr = new int(5); // It will be stored in Stack.
                            // Dereference param will be stored in Heap.

    std::cout << "aPtr: " <<   aPtr << std::endl;   // Heap (변수의 값은 Heap에 저장)
    std::cout << "*aPtr: " << *aPtr << std::endl;
    std::cout << "&aPtr: " << &aPtr << std::endl;   // Stack (변수를 담고 있는 array pointer는 stack에 저장)
    std::cout << std::endl;

    delete aPtr;

    // (2) //
    int *arr = new int [3]{1,2,3};
    // Dynamic arrays can change size during runtime.
    // And contiguous memory is allocated on the Heap.
    std::cout << "arr[0]: " << arr[0] << std::endl;
    std::cout << "arr[1]: " << arr[1] << std::endl;
    std::cout << "arr[2]: " << arr[2] << std::endl;

    std::cout << "&arr[0]: " << &arr[0] << std::endl; // Stored in Heap
    std::cout << "&arr[1]: " << &arr[1] << std::endl;
    std::cout << "&arr[2]: " << &arr[2] << std::endl;
    std::cout << std::endl;
    // &arr[0]: 0xc2790 -> contiguous memory allociation
    // &arr[1]: 0xc2794
    // &arr[2]: 0xc2798

    // (3) //
    std::cout << "arr: "     << arr << std::endl;
    std::cout << "&arr: "    << &arr << std::endl;
    std::cout << "*arr: "    << *arr << std::endl;
    std::cout << "&(*arr): " << &(*arr) << std::endl;

    delete arr;

}