#include <iostream>
#include <map>
#include <string>

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

    // Find returns an iterator pointing to the found element if it exists //
    if (ageMap.find(name) != ageMap.end()){
        int age = ageMap[name];
        cout << name << ": " << age << endl;
    }
    else
    {
        cout << name << " is not defined in the ageMap." << endl;
    }

    auto it = ageMap.find("Charlie");
    if (it != ageMap.end())
    {
        cout << it->first << ": " << it->second << endl;    
        cout << (*it).first << ": " << (*it).second << endl;    
        // 'auto it' is the iterator of the map and it can be accessed using '->' like pointer.
    }

    return 0;
}