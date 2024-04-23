#include <iostream>
#include <list>

int main()
{
    std::list<int> lst = {1,2,3,4,5};
    for(std::list<int>::iterator it = lst.begin(); it!= lst.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;

    // Insertion : push_back, push_front, insert //

    lst.push_back(6);   // {1,2,3,4,5,6}
    for(std::list<int>::iterator it = lst.begin(); it!= lst.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;

    lst.push_front(7);   // {7,1,2,3,4,5,6}
    for(std::list<int>::iterator it = lst.begin(); it!= lst.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;

    auto it = lst.begin();  // 7
    std::advance(it, 4);    // 4
    lst.insert(it, 8);  // {7,1,2,3,8,4,5,6}
    for(std::list<int>::iterator it = lst.begin(); it!= lst.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;      

    // Delete : pop_back, pop_front, erase //
    // 'it' still points "4" 
    std::advance(it, -4);   // 1    
    lst.erase(it);  // {7,2,3,8,4,5,6}
    for(std::list<int>::iterator it = lst.begin(); it!= lst.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl; 

    lst.pop_back(); // {7,2,3,8,4,5}
    for(std::list<int>::iterator it = lst.begin(); it!= lst.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl; 

    lst.pop_front();    // {2,3,8,4,5,6}
    for(std::list<int>::iterator it = lst.begin(); it!= lst.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl; 


    return 0;
}