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

//////////////////////////
// Operator Overloading //
template <typename T>   // v[i] accesses the ith element of v
T& SimpleVector<T>::operator[](int index)   // T& : Array의 index에 해당되는 reference 원소를 반환
{
    return array[index];
}

template <typename T>   // "v+v" returns the element-wise sum
SimpleVector<T> SimpleVector<T>::operator+(SimpleVector& rhs)   // return SimpleVector<T>
{
    SimpleVector<T> result(size);
    for (int i = 0; i < size; ++i)
    {
        result.addElement(array[i] + rhs[i]);
    }
    return result;
}

template <typename T>   // "v += v" adds v to v element-wise
SimpleVector<T>& SimpleVector<T>::operator+=(SimpleVector& rhs)    // return SimpleVector reference (lhs) using this pointer   
{
    for (int i = 0; i <size ; ++i)
    {
        array[i] += rhs.array[i];   // class type이 같아서 private이지만 접근 가능.
    }
    return *this;   // 본인 자체를 반환.
}

template <typename T>   // ++v increments each element of v by 1 in-place and returns the updated v
SimpleVector<T>& SimpleVector<T>::operator++()    // return SimpleVector reference (lhs) using this pointer  
{
    for (int i = 0; i < size; ++i)
    {
        ++array[i];
    }

    return *this;
}

template <typename T>   // v++ increments each element of v by 1 but returns a copy of v prior to the increment
SimpleVector<T> SimpleVector<T>::operator++(int)    // int has no meaning and is meant to distinguish between pre-icrement and post-increment operators
{
    SimpleVector<T> temp(size);
    for (int i = 0; i < size; i++)
    {
        temp.addElement(array[i]);
        ++array[i];
    }
    return temp;    // increment 이전의 vector를 반환.
}    

template <typename T>   // "v << e" appends a new element e to v
SimpleVector<T>& SimpleVector<T>::operator<<(const T& element)  // the argument must be declared const if we want to accept literals
{
    addElement(element);
    return *this;
}

template <typename T>   // "v == v'" checks if v and v' contain the same elements
bool SimpleVector<T>::operator==(SimpleVector<T>& rhs) const
{
    if (size != rhs.getSize()) return false;
    for (int i = 0; i < size; ++i)
    {
        if (array[i] != rhs[i]) return false;
    }

    return true;
}

template <typename T>   // "v < v'" checks if v has a smaller size than v'
bool SimpleVector<T>::operator<(SimpleVector<T>& rhs) const
{
    return size < rhs.getSize();
}

template <typename T>   // Evaluates a vector v to true if v is non-empty.
// Automatically takes place when SimpleVector object is encountered in a context where a bool is expected
SimpleVector<T>::operator bool() const     // const : method를 호출했을 때 object를 건들지 않겠다는 약속.
{
    return size > 0;    // 0보다 크면 true, 같으면 false;
}


// Define begin and end methods that returns pointers to the first and one past to the last element
template <typename T>   // array의 시작 주소
T* SimpleVector<T>::begin()
{
    return array;
}

template <typename T>    // array의 마지막 element에 하나를 더 이동한 주소.
T* SimpleVector<T>::end()  
{
    return array + size;
}

/////////////////////////////////////////////////
// Operator overloading ad Non-member Function //
template<typename T>    // Globally define the << operation on two SimpleVector objects as appending all elements of the RHS to the LHS
SimpleVector<T>& operator<<(SimpleVector<T>& lhs, SimpleVector<T>& rhs)
{
    for (int i = 0; i < rhs.getSize(); ++i)
        lhs.addElement(rhs[i]);
    return lhs;
}


int main()
{
    // [] operator
    SimpleVector<int> vec = {1, 2, 3, 4, 5};
    for (int i = 0; i < vec.getSize(); i++) std::cout << vec[i] << std::endl;
    std::cout << std::endl;

    vec[2] = 10;
    for (int i = 0; i < vec.getSize(); i++) std::cout << vec[i] << std::endl;
    std::cout << std::endl;

    // + operator
    SimpleVector<int> vec1 = {1, 2, 3, 4, 5};
    SimpleVector<int> vec2 = {3, 6, 4, 1, 3};
    SimpleVector<int> vec3 = vec1 + vec2;
    for (int i = 0; i < vec3.getSize(); i++) std::cout << vec3[i] << std::endl;
    std::cout << std::endl;

    // += operator
    vec1 += vec2;
    for (int i = 0; i < vec1.getSize(); i++) std::cout << vec1[i] << std::endl;
    std::cout << std::endl;

    // ++ prefix operator
    SimpleVector<int> vec4 = {1, 2, 3};
    for (int i = 0; i < vec4.getSize(); i++) std::cout << vec4[i] << std::endl;
    ++vec4;
    for (int i = 0; i < vec4.getSize(); i++) std::cout << vec4[i] << std::endl;
    std::cout << std::endl;

    // ++ postfix operator
    SimpleVector<int> vec5 = {1, 2, 3};
    std::cout << (vec++)[1] << std::endl;
    std::cout << vec[1] << std::endl;
    std::cout << std::endl;

    // << operator
    SimpleVector<int> vec6 = {1, 2, 3};
    vec6 << 4 << 5;
    for (int i = 0; i < vec6.getSize(); i++) std::cout << vec6[i] << std::endl;
    std::cout << std::endl;

    // == operator
    SimpleVector<int> vec7 = {1, 2, 3};
    SimpleVector<int> vec8 = {1, 2, 3};
    SimpleVector<int> vec9 = {4, 5, 6};
    if(vec7 == vec8) {std::cout << "run" << std::endl;}
    else {std::cout << "ignore" << std::endl;}
    if(vec7 == vec9) {std::cout << "run" << std::endl;}
    else {std::cout << "ignore" << std::endl;}
    std::cout << std::endl;

    // > operator
    SimpleVector<int> vec10 = {1, 2};
    SimpleVector<int> vec11 = {3, 4, 5};
    SimpleVector<int> vec12 = {6, 7};
    if(vec10 < vec11) {std::cout << "run" << std::endl;}
    else {std::cout << "ignore" << std::endl;}
    if(vec10 < vec12) {std::cout << "run" << std::endl;}
    else {std::cout << "ignore" << std::endl;}
    std::cout << std::endl;

    // bool operator
    SimpleVector<int> vec13 = {1, 2};
    SimpleVector<int> vec14(10);
    if(vec13) {std::cout << "run" << std::endl;}    // 조건문에 진입하면 컴파일러가 object를 bool type conversion
    else {std::cout << "ignore" << std::endl;}
    if(vec14) {std::cout << "run" << std::endl;}
    else {std::cout << "ignore" << std::endl;}
    std::cout << std::endl;
    
    // Range-based for Loop
    SimpleVector<int> vec15 = {1,2,3,4,5};
    std::cout << vec15.begin() << std::endl;
    std::cout << &vec15[0] << std::endl;
    std::cout << vec15.end() << std::endl;
    std::cout << &vec15[vec15.getSize()] << std::endl;    // array의 마지막 element에 하나를 더 이동한 주소.
    for (auto element : vec15) std::cout << element << std::endl;   // The compiler translates the range to a pointer moving from begin to end
    std::cout << std::endl;
    
    // Operator overloading as Non-member functions
    SimpleVector<int> vec16 = {1,2,3,4,5};
    SimpleVector<int> vec17 = {6,7,8,9,10};
    vec16 << vec17;
    for (auto element : vec16)
        std::cout << element << std::endl;

    return 0;
}