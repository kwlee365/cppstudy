#include <iostream>

int main()
{
    int *arr = new int[3]{1, 2, 3};

    // Arithmetic operations on a pointer are based on the pointer type.
    std::cout << "arr + 0: " << arr + 0 << std::endl;   // 정수 변수는 4 바이트씩 주소가 증가.
    std::cout << "arr + 1: " << arr + 1 << std::endl;
    std::cout << "arr + 2: " << arr + 2 << std::endl;

    // 4 바이트씩 더한 자리에 해당하는 값 가져오기.
    std::cout << "*(arr + 0): " << *(arr + 0) << std::endl;   // 정수 변수는 4 바이트씩 주소가 증가.
    std::cout << "*(arr + 1): " << *(arr + 1) << std::endl;
    std::cout << "*(arr + 2): " << *(arr + 2) << std::endl;

    return 0;
}