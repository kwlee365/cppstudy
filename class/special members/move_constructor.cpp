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

    SimpleVector(const SimpleVector<T>& other);
    SimpleVector<T>& operator=(const SimpleVector<T>& other);

    SimpleVector(SimpleVector<T>&& other) noexcept;
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

// Copy Constructor
template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector<T>& other) : size(0), capacity(other.capacity), array(new T[other.capacity])   // 다른 SimpleVector를 call by reference로 입력 받음.
{
    // Copy the elements  
    for (int i = 0; i < other.size; ++i)
        addElement(other.array[i]);
}

// Copy Assignment Operator
template <typename T>
SimpleVector<T>& SimpleVector<T>::operator=(const SimpleVector<T>& other)
{
    if (this != & other)
    {
        delete[] array;

        capacity = other.capacity;
        array = new T[capacity];
        size = 0;

        for (int i = 0; i < other.size; ++i) {
            addElement(other.array[i]);
        }
    }

    return *this;
}

// Move Constructors // 
// A special constructor that is called when an object is initialized with a temporary object
// Initialized an object with a temporary object or a local object returned by value from a function
// Pass a temporary object by value to a function
template <typename T>
SimpleVector<T>::SimpleVector(SimpleVector<T>&& other) noexcept : array(other.array), size(other.size), capacity(other.capacity)
{
    // Define a constructor that accepts an rvalue reference (&&) to an object of the same class along with the noexcept specifier
    // noexcept promises that the constructor will not throw an exception, allowing for compiler optimization
    other.array = nullptr;  // Temporal object의 값들을 저장하고, temp object는 free
    other.size = 0;
    other.capacity= 0;
}


int main()
{
    SimpleVector<int> vec = SimpleVector<int>{1, 2};

    for (int i = 0; i < vec.getSize(); i++) std::cout << vec[i] << std::endl;    
    
    return 0;
}