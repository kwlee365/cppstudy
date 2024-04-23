#include <iostream>
#include <map>
#include <string>

// Input : reference Map
// Output : reference middle element of the Map
int& middleElement(std::map<std::string, int> &m)
{
    int index = m.size() / 2;
    auto it = m.begin();

    for (int i = 0; i < index; i++)
        it++;

    return it->second;
}

int main()
{
    std::map<std::string, int> m = {
        {"a", 1},
        {"b", 2},
        {"c", 3},
    };

    int middle_element_prev = 0;
    middle_element_prev = middleElement(m);
    std::cout << "middle_element_prev : " << middle_element_prev  << std::endl;

    std::cout << std::endl;

    middleElement(m) = 10;  // middleElement returns the reference, so we can assign the int to 'it->second'.

    for (auto& p : m){  // p is the reference element of the Map m 
        std::cout << p.first << ": "
                  << p.second << std::endl;
    }

    // Reference return //
    // Avoid unnecessary copying, especially beneficial for large data type.

    return 0;
}