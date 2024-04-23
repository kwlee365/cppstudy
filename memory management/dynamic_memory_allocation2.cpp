#include <iostream>
#include <new>

int main()
{
    int *array;
    int n;
    std::cin >> n;

    array = new (std::nothrow) int [n]; // it returns nullptr when memory allocation failed
    if(array == nullptr)
    {
        std::cerr << "Memory allocation failed " << std::endl;

        return 1;
    }

    for (int i = 0; i < n; i++)
        array[i] = i;

    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";

    delete[] array;
    
    return 0;
}