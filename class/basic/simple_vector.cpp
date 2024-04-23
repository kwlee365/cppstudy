#include <iostream>
#include <new>

class SimpleVector{

// public : members are accessible from any part of the program 
// protected : members are accessible within the class, by derived classes, and friend classes
// private : members are accessible only within the class 
// -> set attributes and methods as private if they do not need to be modified
// -> public method can access private attributes within the class
public: 
    int* array;     // Points to elements
    int size;       // Number of elements
    int capacity;   // Capacity of the array

    // Constructor //
    SimpleVector(int initialCapacity) : size(0), capacity(initialCapacity)  // Initializer list directly initializes attributes, offering syntactical and performance benefits (const and reference variables can be assigned only within initializer list.)
    {
        array = new int [capacity];
    }
    // Special method within a class that is called implicitly when the class is instantiated.
    // Has the same name as the class.
    // Returns nothing and has no return type specified.
    // If no constructors are explicitly defined, the class automatically includes a default constructor that accepts no arguments and performs no actions.
    // But the implicit defalut constructor is not available if any constructor is explicitly defined within the class.

    // Destructor //
    ~SimpleVector() 
    {
        delete[] array;
    }
    // A destructor aimes to clean up resources when an object's lifetime ends.
    // A class can have only one destructor definition.
    // The destructor is  called when an automatic (on-stack) object goes out of scope or a dynamic (on-heap) object's memory is released via delete.

    void addElement(int element)    // From within class methods, no need to specify the namespace or class name to access the object's attributes and methods.
    {
        if(size == capacity)
            resize();
        array[size] = element;
        size++;
    }

    void resize()
    {
        capacity = capacity * 2;

        int* newArray = new int [capacity];
        for(int i = 0; i< size; i++)
            newArray[i] = array[i];
        delete[] array;
        array = newArray;
    }

    int getSize() const // The const specifier after a function declaration indicates that the function promises not to modify any member variables.
    {
        return size;
    }
};

int main()
{
    SimpleVector vec(10);   // Instance (= Object) 생성 (Class의 도면을 바탕으로 생성된 vector instance)
    vec.addElement(5);  // Outside a class, need to specify the object and use the dot operator to access the object's attributes and methods.

    std::cout << vec.getSize() << std::endl;
    std::cout << std::endl;

    // Class memory size //
    // When a class is initiated, a memory block is allocated.
    // Within this block, space for the attributes specific to this object is designated.
    std::cout << &vec << std::endl;
    std::cout << &vec.array << std::endl;
    std::cout << &vec.size << std::endl;
    std::cout << &vec.capacity << std::endl;
    std::cout << std::endl;

    std::cout << sizeof(vec) << std::endl;
    std::cout << sizeof(vec.array) << std::endl;
    std::cout << sizeof(vec.size) << std::endl;
    std::cout << sizeof(vec.capacity) << std::endl;
    // 16 = 8 + 4 + 4

    return 0;
}