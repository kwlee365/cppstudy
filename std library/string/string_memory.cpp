#include <iostream>
#include <string>

using namespace std;

int main()
{
    string myString = "Hello, world!";

    cout << "Initial size: " << myString.size() << endl;
    cout << "Initial capacity: " << myString.capacity() << endl;
    cout << "Initial memory address: " << (void*)myString.c_str() << endl;

    // Append a small string that doesn't exceed the current capacity
    myString += "!!";
    cout << "\n After small append" << endl;
    cout << "Size: " << myString.size() << endl;
    cout << "Capacity: " << myString.capacity() << endl;
    cout << "Memory address: " << (void*)myString.c_str() << endl;

    // Append a large string to force reallocation
    myString.append("A large string!!");
    cout << "\n After large append" << endl;
    cout << "Size: " << myString.size() << endl;
    cout << "Capacity: " << myString.capacity() << endl;
    cout << "Memory address: " << (void*)myString.c_str() << endl;

    // If appending characters to the string requires more space than current capacity of the char array,
    // the array might be reallocated to a new memory location with a larger size to accommodate the additional characters.

    return 0;
}