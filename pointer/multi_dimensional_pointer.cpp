#include <iostream>

int main()
{
    int nRows = 2, nCols = 3;

    int **arr = new int*[nRows];
    for (int i = 0; i < nRows; i++)
    {
        arr[i] = new int [nCols];
    }

    std::cout << "arr + 0 " << arr + 0 << std::endl;
    std::cout << "arr + 1 " << arr + 1 << std::endl;    // 8 바이트씩 더해짐.

    std::cout << "*(arr + 1): " << *(arr + 1) << std::endl;
    std::cout << "*(arr + 1) + 2: " << *(arr + 1) + 2 << std::endl;
    
    std::cout << "*(*(arr + 1) + 2): " << *(*(arr + 1) + 2) << std::endl;

    std::cout << "arr[1][2]: " << arr[1][2] << std::endl; 
    return 0;
}