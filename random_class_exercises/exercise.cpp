#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {
    int balance = 400;
    int amount = 0;
    int cost = 0;
    std::string ans;
    
    std::cout << "How much money would you like to withdraw? ";
    std::cin >> amount;
    if (balance <= 0)
    {
        std::cout << "You may not withdraw any money.";
        return 1;
    }
    if (amount > 500)
    {
        std::cout << "You may not withdraw over 500$.";
        return 1;
    }
    else if (amount > 300)
    {
        cost = amount * 1.04;
    }
    else
    {
        cost = amount;
    }
    if (amount > balance)
    {
        std::cout << "Insufficient balance. You will be charged a 25$ fee to continue. Continue? (Y/N) ";
        std::cin >> ans;
        if (ans == "Y")
        {
            balance = balance - amount - 25.00;
        }
    }
    else
    {
        balance -= cost;
    }
    std::cout << "Your remaining balance is " << balance << std::endl;
    return 0;
}
