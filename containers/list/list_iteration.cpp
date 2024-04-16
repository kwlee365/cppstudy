#include <iostream>
#include <list>

int main()
{
    std::list<int> lst = {1,2,3,4,5};

    // Forward iteration
    std::cout << "Forward: ";
    for(std::list<int>::iterator it = lst.begin(); it!= lst.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    // Backward iteration
    std::cout << "Backward: ";
    for(std::list<int>::reverse_iterator rit = lst.rbegin(); rit!= lst.rend(); ++rit)
    {
        std::cout << *rit << " ";
    }

}