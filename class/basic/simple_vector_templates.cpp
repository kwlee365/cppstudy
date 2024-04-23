#include <iostream>
#include <new>
#include <string>

template <typename T>   // Class templates allow classes to operate with generic types.
class SimpleVector{

public:
    T* array;
    int size;
    int capacity;

    SimpleVector(int initialCapacity) : size(0), capacity(initialCapacity)
    {
        array = new T [capacity];    
    }

    ~SimpleVector()
    {
        delete[] array;
    }


    void addElement(T element)
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

        T* newArray = new T [capacity];
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
    SimpleVector<double> vec(2);

    vec.addElement(1.0);
    for (int i = 0; i < vec.getSize(); i++) std::cout << vec.array[i] << std::endl;
    vec.addElement(2.0);
    for (int i = 0; i < vec.getSize(); i++) std::cout << vec.array[i] << std::endl;
    vec.addElement(3.0);
    for (int i = 0; i < vec.getSize(); i++) std::cout << vec.array[i] << std::endl;

    // Other type instantiation
    SimpleVector<int> intVec(10);
    SimpleVector<double> doubleVec(10);
    SimpleVector<std::string> stringVec(10);

    return 0;

}
