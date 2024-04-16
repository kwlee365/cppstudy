#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;

    // Adding elements using push_back
    vec.push_back(10);
    std::cout << vec.at(0) << std::endl;    // 10
    vec.push_back(20);
    std::cout << vec.at(1) << std::endl;    // 20
    vec.push_back(30);
    std::cout << vec.at(2) << std::endl;    // 30

    std::cout << vec.at(3) << std::endl;    
    // terminate called after throwing an instance of 'std::out_of_range'
    // what():  vector::_M_range_check: __n (which is 3) >= this->size() (which is 3)

    return 0;
}