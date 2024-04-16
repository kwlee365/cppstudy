#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Range-based for loops //
    for (int val : vec){
        std::cout << val << std::endl;
    }

    std::cout << std::endl;

    for (auto val : vec){   
    // Range-based loops are often used with the auto keyword to deduce the data type
        std::cout << val << std::endl;
    }

    std::cout << std::endl;

    // Iterator //
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << std::endl;
        // Iterator is an object that internally points to an element within a container.
        // Many container classes define their own iterator type
        // Iterators from different containers are designed to serve similar functionalities and support similar syntax to pointers
    }

    std::cout << std::endl;

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << std::endl;
        // Iterator is an object that internally points to an element within a container.
        // Many container classes define their own iterator type
        // Iterators from different containers are designed to serve similar functionalities and support similar syntax to pointers
    }

    

    return 0;
}