#include <iostream>
#include <fstream>

int main()
{
    std::ofstream file("output.txt");
    if(!file.is_open()){    // check if the file is successfully open
        std::cerr << "Failed to open file" << std::endl;

        return 1;
    }

    file << "Hello, Data Science!" << std::endl;
    file << "Why are you here? Get off!!" << std::endl;
    file << "Ay caramba!" << std::endl;

    file.close();

    return 0;
}