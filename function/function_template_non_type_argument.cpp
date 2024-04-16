#include <iostream>

// Non-type template arguments allow you to pass values as arguments to templates.
template <std::size_t N>
int* createAndInitializeArray(){
    int* arr = new int[N];
    for (std::size_t i = 0; i < N; ++i)
    {
        arr[i] = i;
    }

    return arr;
}

int main()
{
    int* array1 = createAndInitializeArray<3>();
    for (int i = 0; i < 3; i++) std::cout << array1[i] << " ";
    std::cout << std::endl;

    int* array2 = createAndInitializeArray<5>();
    for (int i = 0; i < 5; i++) std::cout << array2[i] << " ";
    std::cout << std::endl;

    int* array3 = createAndInitializeArray<7>();
    for (int i = 0; i < 7; i++) std::cout << array3[i] << " ";
    std::cout << std::endl;

    return 0;
}