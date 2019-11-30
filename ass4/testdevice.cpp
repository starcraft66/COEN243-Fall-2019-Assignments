#include <iostream>
#include <array>
#include "edevice.hpp"

int main(int argc, char *argv[])
{
    std::array<EDevice, 2> devices;
    for(int i = 0; i < 2; i++)
    {
        int model_number, year_built;
        std::string category, color;
        double price;
        bool status;
        std::cout << "Entering information for device #" << i + 1 << std::endl;
        bool valid = false;
        while(!valid)
        {
            std::cout << "Enter a category (\"Smartphone\", \"Tablet\", \"Laptop\" or \"Smartwatch\"): ";
            std::cin >> category;
            if(category == "Smartphone" || category == "Tablet" || category == "Laptop" || category == "Smartwatch")
            {
                valid = true;
            }
        }
        std::cout << "Enter a model number (int): ";
        std::cin >> model_number;
        std::cout << "Enter a color (string): ";
        std::cin >> color;
        std::cout << "Enter a status (1/0 for true/false): ";
        std::cin >> status;
        std::cout << "Enter a build year: ";
        std::cin >> year_built;
        std::cout << "Enter a price: ";
        std::cin >> price;
        devices[i] = EDevice(category, model_number, color, status, year_built, price);
    }
    int i = 0;
    for(auto device : devices)
    {
        i++;
        std::string color;
        double price;
        bool status;
        std::cout << "Device information for device #" << i << ":" << std::endl;
        std::cout << "Category: " << device.GetCategory() << std::endl;
        std::cout << "Model Number: " << device.GetModelNumber() << std::endl;
        std::cout << "Year Built: " << device.GetYearBuilt() << std::endl;
        std::cout << "Status: " << device.GetStatus() << std::endl;
        std::cout << "Enter a status to modify (1/0 for true/false):" << std::endl;
        std::cin >> status;
        device.SetStatus(status);
        std::cout << "Enter a color to modify:" << std::endl;
        std::cin >> color;
        device.SetColor(color);
        std::cout << "Enter a price to modify:" << std::endl;
        std::cin >> price;
        device.SetPrice(price);
    }
}