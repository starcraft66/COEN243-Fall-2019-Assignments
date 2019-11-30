#include <iostream>
#include <array>

int main(int argc, char *argv[]) {
    std::array<std::array<int, 3>, 4> grid;
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            grid[i][j] = i + j;
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
