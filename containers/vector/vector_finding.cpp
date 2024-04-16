#include <iostream>
#include <vector>
#include <algorithm>    // for std::find

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Find the first occurrence of 3 in the vector
    auto it = std::find(vec.begin(), vec.end(), 3);
    // std::find returns an iterator that points to the found element if it exists
    // otherwise, it returns last element (=vec.end())

    if (it != vec.end())
    {
        std::cout << "Found 3 at index: " << std::distance(vec.begin(), it) << std::endl;   // 2 
        // std::distance can be used to calculate the offset between iterators.
    }
    else
    {
        std::cout << "Element 3 not found." << std::endl;
    }

    return 0;
}