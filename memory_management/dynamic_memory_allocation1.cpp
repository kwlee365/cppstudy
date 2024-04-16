#include <iostream>
#include <new>  // For std::bad_alloc

int main()
{
    int *array;
    int n;
    std::cin >> n;

    try
    {
        array = new int[n]; // new function: if memory allocation failed, new throw "std::bad _alloc" as an exception

        for (int i = 0; i < n; i++)
            array[i] = i;

        for (int i = 0; i < n; i++)
            std::cout << array[i] << " ";

        delete[] array; // free
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;

        // -10
        // Memory allocation failed: std::bad_array_new_length

        return 1;
    }
    
    return 0;
}