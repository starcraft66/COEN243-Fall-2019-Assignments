#include <iostream>
#include <array>
#include <iomanip>
#include "house.hpp"

int main(int argc, char *argv[])
{
    std::array<House, 2> houses;
    for(int i = 0; i < 2; i++)
    {
        int age, rooms;
        std::string type;
        std::cout << "Entering information for house #" << i + 1 << std::endl;
        if(i == 0)
        {
            type = "Attached";
        }
        else
        {
            type = "Detached";
        }
        std::cout << "Enter how old the house is (int): ";
        std::cin >> age;
        std::cout << "Enter the number of rooms the house has (int): ";
        std::cin >> rooms;
        houses[i] = House(age, type, rooms);
    }
    int i = 0;
    for(auto house : houses)
    {
        i++;
        int age;
        std::cout << "Device information for house #" << i << ":" << std::endl;
        std::cout << "Age: " << house.GetAge() << std::endl;
        std::cout << "Rooms: " << house.GetRooms() << std::endl;
        std::cout << "Type: " << house.GetType() << std::endl;
        std::cout << "Enter a house age to modify it (int):" << std::endl;
        std::cin >> age;
        house.SetAge(age);
        std::cout << "Estimated value of this house: " << std::fixed << std::setprecision(2) << house.EstimatePrice() << std::endl;
    }
}