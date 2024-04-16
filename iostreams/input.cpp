#include <iostream>

int main()
{
    int age;
    double salary;
    char grade;

    /////////////
    // cin (1) //
    // std::cin >> age;
    // std::cin >> salary;
    // std::cin >> grade;

    /////////////
    // cin (2) //
    std::cin >> age >> salary >> grade; // cin can be used to chain multiple input operations.
                                        // "cin > age" object returns the cin object itself.

    std::cout << "Age: " << age << std::endl;
    std::cout << "Salary: " << salary << std::endl;
    std::cout << "Grade: " << grade << std::endl;
    
    /////////// Result ///////////
    // 20 (enter) 300 (enter) 6  
    // Age: 20
    // Salary: 300
    // Grade: 6
    
    // 20 300 6 
    // Age: 20
    // Salary: 300
    // Grade: 6

    // 20abc 300 6 
    // Age: 20
    // Salary: 0
    // Grade: 0

    return 0;
}