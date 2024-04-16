#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Open a file for reading
    std::ifstream file("data1.txt");
    if (!file.is_open()){   // Check if the file is succesffuly open
        std::cerr << "Failed to open file" << std::endl;

        return 1;
    }

    std::string line;
    while (std::getline(file, line)){   // Returns a negative value if EOF
        std::cout << line << std::endl;
    }

    file.close();   // Close the file

    return 0;
}