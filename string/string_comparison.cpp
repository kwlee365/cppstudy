#include <iostream>
#include <string>

int main()
{
    // string can be compared using the '==', '!=', '>','<' method.
    std::string str1 = "Apple";
    std::string str2 = "Banana";

    if (str1 == str2) { 
        std::cout << "str1 and str2 are the same." << std::endl;
    }
    else if (str1 > str2){
        std::cout << "str1 is bigger than str2 in terms of the lexicographical way." << std::endl;
    }
    else if (str1 < str2){
        std::cout << "str2 is bigger than str1 in terms of the lexicographical way." << std::endl;
    }
    else{
        std::cout << "Wait, what?" << std::endl;
    }

    // string can also be compared using the 'compare' method
    std::cout << str1.compare(str2) << std::endl;   // -1: str1 < str2
    std::cout << str2.compare(str1) << std::endl;   //  1: str2 > str1
    std::cout << str1.compare(str1) << std::endl;   //  0: str1 = str1
    return 0;
}