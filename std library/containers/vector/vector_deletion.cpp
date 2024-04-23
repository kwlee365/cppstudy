#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {10, 20, 30, 40, 50};
    std::cout << vec.at(4) << std::endl;

    // Delete the last element
    vec.pop_back();     // {10, 20, 30, 40}
    // std::cout << vec.at(4) << std::endl;    // out of range error!

    // Delete the element at the third position
    std::cout << vec.at(2) << std::endl;    // 30
    vec.erase(vec.begin() + 2);     // {10, 20, 40}
    std::cout << vec.at(2) << std::endl;    // 40

    return 0;
}