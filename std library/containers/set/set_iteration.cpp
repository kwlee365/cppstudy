#include <iostream>
#include <set>

int main()
{
    std::set<int> mySet = {4, 2, 3, 5, 1};

    // Iterate using a range-based for loop
    for (auto elem : mySet)
    {
        std::cout << elem << " ";   // sorted by balanced binary search tree
    }

    std::cout << std::endl;

    for (std::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it)
    {
        std::cout << *it << " ";   // sorted by balanced binary search tree
    }


    return 0; 
}