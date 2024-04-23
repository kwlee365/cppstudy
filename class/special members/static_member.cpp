#include<iostream>
#include<new>
#include<initializer_list>
#include <map>

template <typename T>
class SimpleVector{

private:
    T* array;
    int size;
    int capacity;
    void resize();

public:

    SimpleVector(int initialCapacity);
    SimpleVector(std::initializer_list<T> elements);    
    ~SimpleVector();   
    void addElement(T element);
    int getSize() const;

    T& operator[](int index);
    SimpleVector<T> operator+(SimpleVector<T>& rhs);   
    SimpleVector<T>& operator+=(SimpleVector<T>& rhs);   
    SimpleVector<T>& operator++();   
    SimpleVector<T> operator++(int);   
    SimpleVector<T>& operator<<(const T& element);   
    bool operator==(SimpleVector<T>& rhs) const;
    bool operator<(SimpleVector<T>& rhs) const;
    operator bool() const;
    T* begin();
    T* end();

    static std::map<T, int> elementCount;
    static void printElementCount();
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
    elementCount[element]++;
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

// Operator Overloading 
template <typename T>   
T& SimpleVector<T>::operator[](int index)   
{
    return array[index];
}

template <typename T>   
SimpleVector<T> SimpleVector<T>::operator+(SimpleVector& rhs)   
{
    SimpleVector<T> result(size);
    for (int i = 0; i < size; ++i)
    {
        result.addElement(array[i] + rhs[i]);
    }
    return result;
}

template <typename T>  
SimpleVector<T>& SimpleVector<T>::operator+=(SimpleVector& rhs)   
{
    for (int i = 0; i <size ; ++i)
    {
        array[i] += rhs.array[i];   
    }
    return *this;   
}

template <typename T>  
SimpleVector<T>& SimpleVector<T>::operator++()    
{
    for (int i = 0; i < size; ++i)
    {
        ++array[i];
    }

    return *this;
}

template <typename T>  
SimpleVector<T> SimpleVector<T>::operator++(int)    
{
    SimpleVector<T> temp(size);
    for (int i = 0; i < size; i++)
    {
        temp.addElement(array[i]);
        ++array[i];
    }
    return temp;   
}    

template <typename T>   
SimpleVector<T>& SimpleVector<T>::operator<<(const T& element) 
{
    addElement(element);
    return *this;
}

template <typename T>  
bool SimpleVector<T>::operator==(SimpleVector<T>& rhs) const
{
    if (size != rhs.getSize()) return false;
    for (int i = 0; i < size; ++i)
    {
        if (array[i] != rhs[i]) return false;
    }

    return true;
}

template <typename T>   
bool SimpleVector<T>::operator<(SimpleVector<T>& rhs) const
{
    return size < rhs.getSize();
}

template <typename T>   
SimpleVector<T>::operator bool() const     
{
    return size > 0;    
}

template <typename T>   
T* SimpleVector<T>::begin()
{
    return array;
}

template <typename T>    
T* SimpleVector<T>::end()  
{
    return array + size;
}

// Operator overloading ad Non-member Function 
template<typename T>   
SimpleVector<T>& operator<<(SimpleVector<T>& lhs, SimpleVector<T>& rhs)
{
    for (int i = 0; i < rhs.getSize(); ++i)
        lhs.addElement(rhs[i]);
    return lhs;
}

///////////////////
// Static Member //
// Static members belong to the class, rather than any object instance
// -> shared among all instances of the class
// -> can be accessed without creating an instance of the class
// -> declared with the static specifier
// -> need to be initialized outside the class
template <typename T>
std::map<T, int> SimpleVector<T>::elementCount = {};

////////////////////
// Static Methods //
// Static methods operate on static members or perform class-wide functions without needing an object instance
// -> cannot access non-static members that are specific to an object instance
template <typename T>
void SimpleVector<T>::printElementCount()
{
    for (auto pair : elementCount)
    {
        std::cout << pair.first << ": " << pair.second << std::endl; 
    }
}

int main()
{
    SimpleVector<int> vec1 = {1,2,3};
    SimpleVector<int> vec2 = {2,3,4};
    SimpleVector<int> vec3 = {3,4,5};

    SimpleVector<int>::printElementCount();

    std::cout << SimpleVector<int>::elementCount.size() << std::endl;

    return 0;
}