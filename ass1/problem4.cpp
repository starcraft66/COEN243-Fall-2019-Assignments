#include <iostream>

int main(int argc, char *argv[])
{
    int n, i, count = 0;
    std::cout << "Enter the number to be checked: ";
    std::cin >> n;
    if (n == 0)
    {
        std::cout << n << " is not prime\n";
        return (0);
    }
    else
    {
        for (i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                count++;
            }
        }
    }
    if (count > 1)
    {
        std::cout << n << " is not prime.\n";
    }
    else
    {
        std::cout << n << " is prime.\n";
    }
    return 0;
}