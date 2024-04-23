#include <list>
#include <string>

int main()
{
    // Default initialization (empty list)
    std::list<std::string> list1;

    // Direct initialization
    std::list<std::string> list2 = {"app", "bee", "cat"};

    // Initializa with a specific number of elements with a specific value
    std::list<std::string> list3(5, "dog"); // size : 5, value: "dog"

    return 0;
}