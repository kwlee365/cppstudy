#include <string>
#include <map>

int main()
{
    // Initialize an empty map
    std::map<std::string, int> map1;
    // std::map<key, value>
    // when declaring a map, the data types of both the keys and the values should be specified.

    // Initializer list
    std::map<std::string, int> map2 ={
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 22},
    };

    return 0;
}