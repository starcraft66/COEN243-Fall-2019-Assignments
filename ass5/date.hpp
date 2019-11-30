#ifndef DATE_H_
#define DATE_H_
#include <string>
class Date
{
public:
    Date(int = 1, int = 1, int = 2000); // sets day, month, year
    void setDate(int, int, int); // sets the date
    void printDate() const; // prints date to the screen
    std::string GetMonthInLetters() const;
    void PrintFormattedDate() const;
private:
    int day;
    int month;
    int year;
};
#endif