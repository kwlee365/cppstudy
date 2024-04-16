#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream file("data2.txt");
    int number = 0;

    // Without the getline function,
    // ifstream extracts characters from the input buffer
    // until whitespace appears or as expected by the data type.
    while (file >> number)
    {
        std::cout << number << std::endl;
    }

    file.close();

    return 0;
}