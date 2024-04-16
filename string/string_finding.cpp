#include <iostream>
#include <string>

int main()
{
    // Find the position of the substring //
    std::string fullName = "Lee Kwanwoo";
    size_t pos = fullName.find("Kwanwoo");  // size_t is an unsigned integer type that is used to represent sizes and counts

    // 0 1 2 3 4 
    // L e e   Kwanwoo
    if(pos != std::string::npos)    // string::npos is a constant static member of the string class representing the largest possible value for size_t;
    {
        std::cout << "Found 'Kwanwoo' at position: " << pos << std::endl;
    }
    else
    {
        std::cout << "Where is Kwanwoo...?" << std::endl;   // find() returns string::npos if it fails to find a substring.
    }
    
    // Find the substring of given position //
    std::string str = "Oussama Khatib";
    std::cout << str.substr(8, 6) << std::endl;

    // Replace the substring
    std::string replacedString = str.replace(8, 6, "Kwanwoo");
    std::cout << replacedString << std::endl;

    return 0;
}