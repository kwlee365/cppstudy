#include <new>
#include <iostream>
#include <initializer_list>

class SimpleVector{

public:
    int* array;
    int size;
    int capacity;

    SimpleVector(std::initializer_list<int> elements) : size(0), capacity(elements.size())
    {
        array = new int[capacity];
        for (auto element : elements)
        {
            addElement(element);
        }
    }

    ~SimpleVector()
    {
        delete[] array;
    }
    
    void addElement(int element)
    {
        if(size == capacity)
            resize();
        array[size] = element;
        size++;
    }

    void resize()
    {
        std::cout << "Resize the vector object" << std::endl;
        capacity = capacity * 2;

        int* newArray = new int [capacity];
        for(int i = 0; i< size; i++)
            newArray[i] = array[i];
        delete[] array;
        array = newArray;
    }

    int getSize() const
    {
        return size;
    }

};

int main()
{
    SimpleVector vec = {1,2,3,4,5}; // A constructor can take a curly brace-enclosed list of values using std::initializer_list

    std::cout << vec.getSize() << std::endl;
    std::cout << vec.capacity << std::endl;
    std::cout << std::endl;

    vec.addElement(10);
    std::cout << vec.getSize() << std::endl;
    std::cout << vec.capacity << std::endl;

    return 0;
}