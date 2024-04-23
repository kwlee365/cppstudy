#include<iostream>
#include<new>
#include<initializer_list>
#include <stdexcept>  
#include <exception>

template <typename T>
class SimpleVector{

private:
    int size;
    int capacity;
    void resize();

public:
    T* array;

    SimpleVector(int initialCapacity);
    SimpleVector(std::initializer_list<T> elements);    
    ~SimpleVector();   
    void addElement(T element);
    int getSize() const;

    T& operator[](int index);
};

// Constructor
template <typename T>
SimpleVector<T>::SimpleVector(int initialCapacity) : size(0), capacity(initialCapacity)
{
    array = new T[capacity];
}

template <typename T>
SimpleVector<T>::SimpleVector(std::initializer_list<T> elements) : size(0), capacity(elements.size())
{
    array = new T[capacity];
    for (auto element : elements)
    {
        addElement(element);
    }
}

// Destructor
template <typename T>
SimpleVector<T>::~SimpleVector()
{
    delete[] array;
}

// Methods
template <typename T>
void SimpleVector<T>::addElement(T element)
{
    if(size==capacity)
        resize();

    array[size] = element;
    size++;
}

template <typename T>
int SimpleVector<T>::getSize() const
{
    return size;
}

template <typename T>
void SimpleVector<T>::resize()
{
    std::cout << "Resize the vector object" << std::endl;

    capacity = capacity * 2;
    T* newArray = new T [capacity];

    for (int i = 0; i < size; i++)
        newArray[i] = array[i];
    delete[] array;

    array = newArray;
}

// Custom Exception //
// 1. Inherits from std::exception or any class derived from it
// 2. Override the what() method to return an error message
class MyException : public std::exception {
    int index, size;
    std::string message;

public:
    MyException(int index, int size) : index(index), size(size){
        message = "MyException: Index " + std::to_string(index) + " is out of the array of size " + std::to_string(size);
    }
    const char * what() const noexcept override{
        return message.c_str();
    }
};

// Operator Overloading, Syntax
template <typename T>
T& SimpleVector<T>::operator[](int index)
{
    if(index < 0 || index >= size)
    {
        throw MyException(index, size);
    }

    return array[index];
}


int main()
{
    SimpleVector<int> vec{1,2};

    int index, value;
    std::cin >> index >> value;

    try{
        vec[index] = value;
    }
    catch(std::out_of_range& e){
        std::cout << "Out of range exception: " << e.what() << std::endl;
    }

    return 0;
}