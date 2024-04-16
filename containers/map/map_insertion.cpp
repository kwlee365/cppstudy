#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> ageMap;

    // Insert //
    ageMap.insert({"Alice", 30});
    ageMap["Bob"] = 25;
    ageMap.insert(make_pair("Charlie", 40));

    ageMap.insert({"Alice", 35});   // Ignored (when, the Alice is already assigned in the given map)
    ageMap["Alice"] = 35;   // Update the value

    // Print //
    cout << ageMap["Alice"] << endl;
    cout << ageMap["Bob"] << endl;
    cout << ageMap["Charlie"] << endl;
    cout << ageMap["Kwanwoo"] << endl;

    // When attempting to access a non-existing key,
    // a new key-value pair is created with the defalut value of the value type. (0 for int)

    return 0;
}