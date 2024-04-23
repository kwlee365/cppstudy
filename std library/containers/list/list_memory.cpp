#include <iostream>
#include <list>

int main()
{
    std::list<int> lst = {1, 2, 3, 4, 5};
    for(std::list<int>::iterator it = lst.begin(); it!= lst.end(); ++it) std::cout << &(*it) << " ";
    std::cout << &(*lst.end()) << std::endl;

    for(std::list<int>::reverse_iterator rit = lst.rbegin(); rit!= lst.rend(); ++rit) std::cout << &(*rit) << " ";
    std::cout << &(*lst.rend()) << std::endl;

    // List elements are assigned in the Heap.
    // List 'end' and 'rend' have the same address.
    // Typically, end() and rend() may point to sentinel node or an invalid node.
}