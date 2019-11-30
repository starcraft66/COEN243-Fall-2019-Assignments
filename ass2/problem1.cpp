#include <iostream>
#include <cstring>
#include <limits>

int main(int argc, char *argv[])
{
    int height = 0, width = 0, houses = 0;
    std::string name;
    std::cout << "‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐\nHouse Drawing Program\n‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐\n";
    std::cout << "What is your name? ";
    std::cin >> name;
    std::cout << "Well " << name << ", welcome to the house drawing program.\n";
    for (;;)
    {
        std::cout << "Do you want me to draw a simple house for you? (yes/no) ";
        std::string choice;
        std::cin >> choice;
        if (choice == "yes")
        {
            houses++;
            for (;;)
            {
                std::cout << "Enter height of the house you want me to draw: ";
                if (std::cin >> height) {
                    break;
                } else {
                    std::cout << "Please enter a valid number!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
                }
            }
            for (;;)
            {
                std::cout << "Please enter an odd number for the width of the house (must be odd numbers and bigger than 1): ";
                if (std::cin >> width) {
                    break;
                } else {
                    std::cout << "Please enter a valid number!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            int tries = 0;
            while (width % 2 == 0 || width < 2)
            {
                tries++;
                if (tries >= 3)
                {
                    std::cout << "It seems you are having troubles entering odd numbers! Program ends now.\n";
                    return 1;
                }
                std::cout << "You entered " << width << " for the width. Not an odd number!\n\n";
                std::cout << "Please enter an odd number for the width of the house (must be odd numbers and bigger than 1): ";
                std::cin >> width;
            }
            for (int i = 1; i <= width; i += 2)
            {
                int padding = (width - i)/2;
                int stars = width - 2*padding;
                for (int j = 0; j < padding; j++)
                {
                    std::cout << " ";
                }
                for (int j = 0; j < stars; j++)
                {
                    std::cout << "*";
                }
                for (int j = 0; j < padding; j++)
                {
                    std::cout << " ";
                }
                std::cout << std::endl;        
            }
            for (int i = 1; i <= height; i++)
            {
                std::cout << "|";
                for (int j = 0; j < width - 2; j++)
                {
                    std::cout << " ";
                }
                std::cout << "|\n";
            }
            for (int i = 1; i <= width; i++)
            {
                std::cout << "-";
            }
            std::cout << std::endl;
            //return 0;
        }
        else
        {
            std::cout << "Hope you like your " << houses << " houses!\n";
            break;
        }
    }
    return 0;
}