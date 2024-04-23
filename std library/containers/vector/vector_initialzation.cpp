#include <iostream>
#include <vector>

int main()
{
    // Direct list initialization
    std::vector<int> vec1 = {1, 2, 3, 4, 5};

    // From an array
    int arr[] = {6,7,8,9,10};
    std::vector<int> vec2(std::begin(arr), std::end(arr));  // From initial address of arr to final address of arr

    // With a specific size and value
    std::vector<int> vec3(5, 100);  // size: 5, value: 100
    std::cout << vec3.at(0) << std::endl;
    std::cout << vec3.size() << std::endl;

    return 0;
}