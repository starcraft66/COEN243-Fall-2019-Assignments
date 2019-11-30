#include <iostream>

int main(int argc, char *argv[])
{
    int n1, n2;
    std::cout << "Enter the first number: ";
    std::cin >> n1;
    std::cout << "Enter the second number: ";
    std::cin >> n2;
    std::cout << "The results are:\n"
                 "Sum: "
              << n1 + n2 << "\n"
              << "Difference: " << n1 - n2 << "\n"
              << "Product: " << n1 * n2 << "\n"
              << "Division: " << n1 / n2 << "\n";
    return 0;
}