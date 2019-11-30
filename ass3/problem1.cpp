#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <numeric>

int minimum(std::vector<int> grades)
{
    return *std::min_element(grades.begin(), grades.end());
}

int maximum(std::vector<int> grades)
{
    return *std::max_element(grades.begin(), grades.end());
}

double average(std::vector<int> grades)
{
    return 1.0 * std::accumulate(grades.begin(), grades.end(), 0) / grades.size();
}

int median(std::vector<int> grades)
{
    std::sort(grades.begin(), grades.end());
    size_t n = grades.size() / 2;
    // optimize by only sorting the index we really need
    std::nth_element(grades.begin(), grades.begin() + n, grades.end());
    int middle = grades[n];
    if (grades.size() % 2 == 1)
    {
        // Return the middle if there is an odd number of grades
        return middle;
    }
    else
    {
        // There is an even number of grades and the "middle" was rounded up
        // so we need to find the value before that and average them together
        std::nth_element(grades.begin(), grades.begin() + n - 1, grades.end());
        return 0.5 * (middle + grades[n - 1]);
    }
}

int A(std::vector<int> grades)
{
    std::sort(grades.begin(), grades.end());
    std::vector<int>::iterator cutoff = std::upper_bound(grades.begin(), grades.end(), 80);
    return std::distance(cutoff, grades.end());
}

int B(std::vector<int> grades)
{
    std::sort(grades.begin(), grades.end());
    std::vector<int>::iterator cutoff_min = std::upper_bound(grades.begin(), grades.end(), 70);
    std::vector<int>::iterator cutoff_max = std::upper_bound(grades.begin(), grades.end(), 80);
    return std::distance(cutoff_min, cutoff_max);
}

int C(std::vector<int> grades)
{
    std::sort(grades.begin(), grades.end());
    std::vector<int>::iterator cutoff_min = std::upper_bound(grades.begin(), grades.end(), 55);
    std::vector<int>::iterator cutoff_max = std::upper_bound(grades.begin(), grades.end(), 70);
    return std::distance(cutoff_min, cutoff_max);
}

int D(std::vector<int> grades)
{
    std::sort(grades.begin(), grades.end());
    std::vector<int>::iterator cutoff_min = std::upper_bound(grades.begin(), grades.end(), 40);
    std::vector<int>::iterator cutoff_max = std::upper_bound(grades.begin(), grades.end(), 55);
    return std::distance(cutoff_min, cutoff_max);
}

int E(std::vector<int> grades)
{
    std::sort(grades.begin(), grades.end());
    std::vector<int>::iterator cutoff_min = std::upper_bound(grades.begin(), grades.end(), 40);
    return std::distance(grades.begin(), cutoff_min);
}

int main(int argc, char *argv[])
{
    int number;
    // I might be bending the rules here but the assignment doesn't make sense
    // We want the user to provide N number of grades but array sizes must be defined as const
    // Variable length arrays aren't a part of the C++ standard so we will go with a Vector
    std::vector<int> grades;
    std::cout << "How many grades would you like to enter? ";
    std::cin >> number;
    for (int i = 0; i < number; i++)
    {
        std::cout << "Enter grade #" << i + 1 << " ";
        int grade;
        std::cin >> grade;
        grades.push_back(grade);
    }
    std::cout << minimum(grades) << std::endl;
    std::cout << maximum(grades) << std::endl;
    std::cout << average(grades) << std::endl;
    std::cout << median(grades) << std::endl;
    // The instructions were unclear regarding the inclusion or exclusion of the bounds of
    // these grades so I interpreted it as [lowest, highest) with the exception of 100 and
    // 0 which are always included.
    std::cout << A(grades) << std::endl;
    std::cout << B(grades) << std::endl;
    std::cout << C(grades) << std::endl;
    std::cout << D(grades) << std::endl;
    std::cout << E(grades) << std::endl;
}