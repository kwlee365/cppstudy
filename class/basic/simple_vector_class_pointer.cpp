#include<iostream>
#include<new>
#include<initializer_list>
#include<memory>    // unique_ptr

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


int main()
{
    // Declare a pointer without a real object;
    SimpleVector<int> *intVecPtr1 = nullptr;
    std::cout << intVecPtr1 << std::endl;
    std::cout << std::endl;

    // Declare a pointer that points to an local object
    SimpleVector<int> intVec(10);
    SimpleVector<int> *intVecPtr2 = &intVec;
    std::cout << &intVec << std::endl;
    std::cout << intVecPtr2 << std::endl;
    std::cout << std::endl;

    // Declare a pointer and assign a dynamic object
    SimpleVector<int> *intVecPtr3 = new SimpleVector<int>(10);
    std::cout << intVecPtr3 << std::endl;
    std::cout << std::endl;
    delete intVecPtr3;

    // Create a new object using an initializer list
    SimpleVector<int> *intVecPtr4 = new SimpleVector<int>({1,2,3});
    SimpleVector<int> *intVecPtr5 = new SimpleVector<int>{1,2,3};
    std::cout << intVecPtr4 << std::endl;
    std::cout << intVecPtr5 << std::endl;

    // Accessing Members
    intVecPtr4->addElement(10);
    std::cout << (*intVecPtr4).array[0] << std::endl;
    std::cout << (*intVecPtr4).array[1] << std::endl;
    std::cout << (*intVecPtr4).array[2] << std::endl;
    std::cout << (*intVecPtr4).array[3] << std::endl;   // Only public members can be accessed

    delete intVecPtr4;
    delete intVecPtr5;  // Without a smart pointer

    // With a smart pointer
    std::unique_ptr<SimpleVector<int>> intVecPtr6(new SimpleVector<int>(10));
    std::unique_ptr<SimpleVector<int>> intVecPtr7 = std::make_unique<SimpleVector<int>>(10);    // no need to delete
    return 0;
}