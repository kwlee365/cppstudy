#include<iostream>
#include<new>
#include<initializer_list>

template <typename T>
class SimpleVector{

private:
    int size;
    int capacity;
    void resize();

public:
    T* array;

    SimpleVector(int initialCapacity);
    SimpleVector(std::initializer_list<T> elements);    // 생성자는 복수로 생성이 가능.
    ~SimpleVector();    // 소멸자는 오직 1개만 존재.
    void addElement(T element);
    int getSize() const;
};

// Out-of-class definition //
// The implementation of each method is detailed outside the class body.
// Each method is preceded by the template declaration.
// Method names are prefixed with the class name (SimpleVector), template arguments (T), and scope resolution operator (::)
// Attributes within class can be accessed without any specifier


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
    SimpleVector<double> doubleVec = {1.0, 2.0};
    doubleVec.addElement(3.0);
    for (int i = 0; i < doubleVec.getSize(); i++) std::cout << doubleVec.array[i] << std::endl;
    doubleVec.addElement(4.0);
    for (int i = 0; i < doubleVec.getSize(); i++) std::cout << doubleVec.array[i] << std::endl;
    doubleVec.addElement(5.0);
    for (int i = 0; i < doubleVec.getSize(); i++) std::cout << doubleVec.array[i] << std::endl;

    return 0;
}