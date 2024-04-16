#include <iostream>
#include <vector>

int main()
{
    std::vector<int>* myVector = new std::vector<int>();

    myVector->push_back(10);
    myVector->push_back(20);
    // ptr->member : A shorthand for (*ptr).member


    std::cout << "Range-based for loop" << std::endl;
    for (auto it : *myVector)
    {
        std::cout << it << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Access array elements" << std::endl;
    for (int i = 0; i< (*myVector).size(); i++)
    {
        std::cout << (*myVector)[i] << std::endl;
    }
    // (*ptr).member : Dereference the object first and then access a member using .
    std::cout << std::endl;

    std::cout << "Iterator" << std::endl;
    for (std::vector<int>::iterator it = myVector->begin(); it != myVector->end(); ++it){
        std::cout << *it << std::endl;
    }

    delete myVector;    // delete dynamic memory allocation

    return 0;
}