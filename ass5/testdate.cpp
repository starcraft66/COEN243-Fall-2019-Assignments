#include <iostream>
#include <array>
#include <iomanip>
#include "date.hpp"

int main(int argc, char *argv[])
{
    Date* d1 = new Date(22, 7, 1998);
    Date* d2 = new Date(19, 8, 1999);

    std::cout << d1->GetMonthInLetters() << std::endl;
    d1->PrintFormattedDate();
    std::cout << d2->GetMonthInLetters() << std::endl;
    d2->PrintFormattedDate();
}