#include <iostream>
#include <vector>
#include <memory>

int main()
{
    // Memory leaks: allocated memory is not freed even after it is no longer needed
    // Dangling pointers: Pointers that point to a memory locations that have been freed

    // Shared Pointer : can be copied or assigned, enabling shared ownership with other 'std::shared_ptr'
    //                : Automatically releases the allocated memory the last std::shared_ptr owing it is destroyed or reset.

    std::shared_ptr<std::vector<int>> vecPtr1(new std::vector<int>());
    std::shared_ptr<std::vector<int>> vecPtr2(new std::vector<int>());
    

    // Insertion //
    vecPtr1->push_back(1);
    vecPtr2->push_back(2);

    for (auto item : *vecPtr1) std::cout << item << " ";    // 1
    std::cout << std::endl;
    for (auto item : *vecPtr2) std::cout << item << " ";    // 2
    std::cout << std::endl;

    vecPtr2 = vecPtr1;
    vecPtr1->push_back(3);
    vecPtr2->push_back(4);

    for (auto item : *vecPtr1) std::cout << item << " ";    // 1 3 4
    std::cout << std::endl;
    for (auto item : *vecPtr2) std::cout << item << " ";    // 1 3 4

    return 0;
}