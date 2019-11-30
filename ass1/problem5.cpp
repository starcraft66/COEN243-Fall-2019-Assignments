#include <iostream>
#include <array>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::array<int, 3> tosort;
    std::cout << "Enter the first number: ";
    std::cin >> tosort[0];
    std::cout << "Enter the second number: ";
    std::cin >> tosort[1];
    std::cout << "Enter the third number: ";
    std::cin >> tosort[2];
    std::sort(tosort.begin(), tosort.end());
    std::reverse(tosort.begin(), tosort.end());
    std::cout << "The sorted numbers are " << tosort[0] << ", " << tosort[1] << ", " << tosort[2] << ".\n";
    return 0;
}