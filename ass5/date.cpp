#include <iostream>
#include <string>
#include <iomanip>
#include "date.hpp"
using namespace std;

// Constructor
Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

// sets date
void Date::setDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

// prints date
void Date::printDate() const
{
    cout << month << "/" << day << "/" << year << "\n";
}

string Date::GetMonthInLetters() const
{
    switch(month)
    {
        case 1:
            return "January";
        case 2:
            return "Febuary";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Invalid";
    }
}

void Date::PrintFormattedDate() const
{
    cout << setfill('0') << GetMonthInLetters() << " " << setw(2) << day << ", " << setw(4) << year << endl;
}