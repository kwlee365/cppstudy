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

int main()
{
   SimpleVector<int> vec1{1,2};
   SimpleVector<int> vec2 = vec1;   // Shallow copy: Class 안에 있는 모든 변수들을 동일하게 할당하는 것. 

   std::cout << &(vec1.array[0]) << std::endl;  // 0xf426c0
   std::cout << &(vec2.array[0]) << std::endl;  // 0xf426c0

   vec1.addElement(3);
   vec2.addElement(4);

   std::cout << &(vec1.array[0]) << std::endl;  // 0xf46a70 -> 기존의 array는 free
   std::cout << &(vec2.array[0]) << std::endl;  // 0xf426c0

   std::cout << "vec1: ";
   for (auto e : vec1) std::cout << e << " ";
   std::cout << std::endl;

   std::cout << "vec2: ";
   for (auto e : vec2) std::cout << e << " ";
   std::cout << std::endl;

    // vec1: 1 2 3
    // vec2: 15886992 0 4   : 기존의 array가 free되기 때문에, junk value들이 저장됨.   
    // -> Deep copy of resources is needed : 특정 변수의 예외 처리를 정의하여 복사
    return 0;
}