#include <iostream>
#include <vector>
#include <numeric>  // for std::accumulate

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Sum all elements in the vector
    // std::accumulate is the function to compute the sum of the elements of a container.
    int sum = std::accumulate(vec.begin(), vec.end(), 0);

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
