#include <iostream>
#include <iomanip>

void function1(int lower_bound, int upper_bound)
{
    std::cout << "List of numbers in this interval which are multiple of both 3 and 7:";
    for (int i = lower_bound; i <= upper_bound; i++)
    {
        if (i % 3 == 0 && i % 7 == 0)
        {
            std::cout << " " << i;
        }
    }
    std::cout << std::endl;
}

void function2(int lower_bound, int upper_bound, int &result)
{
    result = upper_bound - lower_bound;
}

double function3(int lower_bound, int upper_bound)
{
    double result = 0;
    for (int i = 0; i <= upper_bound - lower_bound; i++)
    {
        result += 1.0 / (double(lower_bound) + double(i));
    }
    return result;
}

int main(int argc, char *arvg[])
{
    int lower, upper;
    char character;
    std::cout << "Please enter two positive integer numbers: (Lower bound/Upper bound): ";
    std::cin >> lower;
    std::cin >> upper;
    std::cout << "Please enter a character: ";
    std::cin >> character;
    if (character == 'a')
    {
        function1(lower, upper);
    }
    else if (character == 'b')
    {
        int res = 0;
        function2(lower, upper, res);
        std::cout << "The difference between two numbers is " << res << "\n";
    }
    else if (character == 'c')
    {
        double res = function3(lower, upper);
        std::cout << std::fixed << std::setprecision(3) << "The value of sum is " << res << "\n";
    }
    else
    {
        std::cout << "Invalid input\n";
        return 1;
    }

}