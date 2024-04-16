#include <iostream>
#include <set>

int main()
{
    std::set<int> mySet = {2, 4, 1, 5, 3};
    for (auto elem : mySet) std::cout << elem << " ";
    std::cout << std::endl;

    // Add
    mySet.insert(6);
    for (auto elem : mySet) std::cout << elem << " ";
    std::cout << std::endl;
    
    // Remove
    mySet.erase(4); // By value
    for (auto elem : mySet) std::cout << elem << " ";
    std::cout << std::endl;
    
    // Find
    auto it = mySet.find(2);    // returns iterator that points elements '2'.
    if(it != mySet.end())
        mySet.erase(it);    // By iterator
    for (auto elem : mySet) std::cout << elem << " ";
    std::cout << std::endl;

    return 0; 
}