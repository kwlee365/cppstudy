#include<map>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    map<string, int> ageMap = 
    {
        {"Alice",   30},
        {"Bob",     25},
        {"Charlie", 22},
    };

    string name = "Bob";

    if (ageMap.find(name) != ageMap.end()){
        int age = ageMap[name];
        cout << name << ": " << age << endl;
    }
    else
    {
        cout << name << " is not defined in the ageMap." << endl;
    }

    // Deletion //
    // Erasing a existing element
    ageMap.erase("Bob");

    if (ageMap.find(name) != ageMap.end()){
        int age = ageMap[name];
        cout << name << ": " << age << endl;
    }
    else
    {
        cout << name << " is not defined in the ageMap." << endl;
    }

    // Erasing a non-existing element
    ageMap.erase("Frank");
    // Note: No error is thrown when attempting to erase a non-existing key.
    return 0;
}