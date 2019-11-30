#include <iostream>

int main(int argc, char *argv[])
{
    int grade;
    std::string letter;
    std::cout << "Enter the grade: ";
    std::cin >> grade;

    if (grade >= 90)
    {
        letter = "A+";
    }
    else if (grade >= 85)
    {
        letter = "A";
    }
    else if (grade >= 80)
    {
        letter = "A-";
    }
    else if (grade >= 75)
    {
        letter = "B+";
    }
    else if (grade >= 70)
    {
        letter = "B";
    }
    else if (grade >= 65)
    {
        letter = "C+";
    }
    else if (grade >= 60)
    {
        letter = "C";
    }
    else if (grade >= 55)
    {
        letter = "C-";
    }
    else if (grade >= 50)
    {
        letter = "D+";
    }
    else if (grade >= 45)
    {
        letter = "D";
    }
    else if (grade >= 40)
    {
        letter = "D-";
    }
    else
    {
        letter = "F";
    }

    std::cout << "The student's grade letter is " << letter << ".\n";
    return 0;
}