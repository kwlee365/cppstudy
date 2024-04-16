#include <iostream>
#include <vector>
#include <memory>

int main()
{
    // Memory leaks: allocated memory is not freed even after it is no longer needed
    // Dangling pointers: Pointers that point to a memory locations that have been freed

    // unique Pointer : cannot be copied to share ownership with other variables
    //                : Automatically releases the allocated memory when it goes out of scope.

    std::unique_ptr<std::vector<int>> vecPtr(new std::vector<int>());

    // Insertion //
    vecPtr->push_back(10);
    vecPtr->push_back(20);

    for (auto item : *vecPtr)
        std::cout << item << " ";
    std::cout << std::endl;

    // Assignment //
    (*vecPtr)[0] = 30;

    for (auto item : *vecPtr)
        std::cout << item << " ";

    return 0;
}