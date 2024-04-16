#include<map>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    map<string, int> ageMap = 
    {
        {"Alice",   30},
        {"Bob",     25},
        {"Charlie", 22},
    };

    string name = "Bob";

    // Range-based for loop for simple iteration //
    // Traverses in ascending order of the keys
    for (std::pair<std::string, int> pair : ageMap) // pair is variable.
    {
        std::cout << pair.first << " is " << pair.second << " years old. " << std::endl;
    }

    std::cout << std::endl;

    // Iterator //
    for (std::map<std::string, int>::iterator it = ageMap.begin(); it != ageMap.end(); ++it)    // it is iterator
    {
        std::cout << it->first << " is " << it->second << " years old. " << std::endl;
    }

    std::cout << std::endl;

    for (auto it = ageMap.begin(); it != ageMap.end(); ++it)    // it is iterator
    {
        std::cout << it->first << " is " << it->second << " years old. " << std::endl;
    }

    return 0;
}