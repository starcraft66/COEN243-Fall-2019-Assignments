#include <iostream>
#include <iomanip>

#define TWO_DECIMAL(x) std::fixed << std::setprecision(2) << (x)
#define ONE_DECIMAL(x) std::fixed << std::setprecision(1) << (x)

int main(int argc, char *argv[])
{
    std::cout << "Celcius\t\tFarenheit\tKelvin\n";
    for (int i = 1; i <= 20; ++i)
    {
        std::cout << i << "\t\t" << ONE_DECIMAL(i * (9.0 / 5.0) + 32.0) << "\t\t" << TWO_DECIMAL(i + 273.15) << std::endl;
    }
    return 0;
}