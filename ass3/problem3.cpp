#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

void redo(std::array<int, 10> &board, std::vector<std::array<int, 2>> &history, int times);

void render(std::array<int, 10> &board)
{
    std::cout << "┏━┳━┳━┳━┳━┳━┳━┳━┳━┳━┓" << std::endl;
    for(int i = 0; i < board.size(); i++)
    {
        std::cout << "┃" << (board[i] == 0 ? " " : std::to_string(board[i]));
    }
    std::cout << "┃" << std::endl << "┗━┻━┻━┻━┻━┻━┻━┻━┻━┻━┛" << std::endl;
}

void left(std::array<int, 10> &board, std::vector<std::array<int, 2>> &history, int robot, int amount)
{
    auto current = std::find(board.begin(), board.end(), robot);
    size_t space_left = std::distance(board.begin(), current);
    int current_idx = space_left;
    if(amount <= space_left)
    {
        if(board[current_idx - amount] == 0)
        {
            std::swap(board[current_idx], board[current_idx - amount]);
            auto current1 = std::distance(board.begin(), std::find(board.begin(), board.end(), 1));
            auto current2 = std::distance(board.begin(), std::find(board.begin(), board.end(), 2));
            std::array<int, 2> history_entry = {static_cast<int>(current1), static_cast<int>(current2)};
            history.push_back(history_entry);
        }
        else
        {
            std::cout << "Space already occupied\n";
            // space already occupied
        }
    }
    else {
        std::cout << "Out of bounds! (" << amount << ">" << space_left << ")\n";
        // out of bounds
    }
}

void right(std::array<int, 10> &board, std::vector<std::array<int, 2>> &history, int robot, int amount)
{
    auto current = std::find(board.begin(), board.end(), robot);
    size_t space_left = std::distance(current, board.end()) - 1;
    int current_idx = board.size() - space_left - 1;
    if(amount <= space_left)
    {
        if(board[current_idx + amount] == 0)
        {
            std::swap(board[current_idx], board[current_idx + amount]);
            auto current1 = std::distance(board.begin(), std::find(board.begin(), board.end(), 1));
            auto current2 = std::distance(board.begin(), std::find(board.begin(), board.end(), 2));
            std::array<int, 2> history_entry = {static_cast<int>(current1), static_cast<int>(current2)};
            history.push_back(history_entry);
        }
        else
        {
            std::cout << "Space already occupied\n";
            // space already occupied
        }
    }
    else {
        std::cout << "Out of bounds! (" << amount << ">" << space_left << ")\n";
        // out of bounds
    }
}

void undo(std::array<int, 10> &board, std::vector<std::array<int, 2>> &history, int times)
{   
    if(times <= history.size())
    {
        for(int i = 0; i < times; i++)
        {
            int position1 = history[history.size() - 2 - i][0];
            int position2 = history[history.size() - 2 - i][1];
            int current_idx1 = std::distance(board.begin(), std::find(board.begin(), board.end(), 1));
            int current_idx2 = std::distance(board.begin(), std::find(board.begin(), board.end(), 2));
            board[current_idx1] = 0;
            board[current_idx2] = 0;
            board[position1] = 1;
            board[position2] = 2;
            render(board);
        }
        std::string choice;
        std::cout << "The board has been rolled back " << times << " moves. Would you like to redo? [y/N]: " << std::endl;
        std::cin >> choice;
        if (choice == "y" || choice == "Y")
        {
            redo(board, history, times);
        }
    }
    else
    {
        std::cout << "Out of bounds! (" << times << ">" << history.size() << ")\n";
    }
}

void redo(std::array<int, 10> &board, std::vector<std::array<int, 2>> &history, int times)
{
    if(times <= history.size())
    {
        for(int i = 0; i < times; i++)
        {
            int position1 = history[history.size() - times + i][0];
            int position2 = history[history.size() - times + i][1];
            int current_idx1 = std::distance(board.begin(), std::find(board.begin(), board.end(), 1));
            int current_idx2 = std::distance(board.begin(), std::find(board.begin(), board.end(), 2));
            board[current_idx1] = 0;
            board[current_idx2] = 0;
            board[position1] = 1;
            board[position2] = 2;
            render(board);
        }
        std::cout << "The board has been rolled back once again!" << std::endl;
    }
    else
    {
        std::cout << "Out of bounds! (" << times << ">" << history.size() << ")\n";
    }
}

int main(int argc, char *argv[])
{
    // 0 = empty
    // 1 = robot 1
    // 2 = robot 2
    std::array<int, 10> board = {1, 2, 0, 0, 0, 0, 0, 0, 0, 0};
    // index 0 will be the index of robot 1
    // index 1 will be the index of robot 2
    std::vector<std::array<int, 2>> history;
    std::array<int, 2> initial_history = {0, 1};
    history.push_back(initial_history);

    
    for (;;)
    {
        std::cout << "Controller Menu:" << std::endl;
        std::cout << "1.Move robot 1 Right" << std::endl;
        std::cout << "2.Move robot 1 Left" << std::endl;
        std::cout << "3.Move robot 2 Right" << std::endl;
        std::cout << "4.Move robot 2 Left" << std::endl;
        std::cout << "5.Display" << std::endl;
        std::cout << "6.Reboot" << std::endl;
        std::cout << "7.Show Array" << std::endl;
        std::cout << "8.Rollback/Redo" << std::endl;
        std::cout << "9.Exit" << std::endl;
        std::cout << "Please choose an option (1-9): ";
        std::string choice;
        std::cin >> choice;
        if (choice == "1")
        {
            int spaces;
            std::cout << "Enter amount of spaces to move right by: ";
            if (std::cin >> spaces) {
                right(board, history, 1, spaces);
            } else {
                std::cout << "Please enter a valid number!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
            }
        }
        else if (choice == "2")
        {
            int spaces;
            std::cout << "Enter amount of spaces to move left by: ";
            if (std::cin >> spaces) {
                left(board, history, 1, spaces);
            } else {
                std::cout << "Please enter a valid number!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
            }
        }
        else if (choice == "3")
        {
            int spaces;
            std::cout << "Enter amount of spaces to move right by: ";
            if (std::cin >> spaces) {
                right(board, history, 2, spaces);
            } else {
                std::cout << "Please enter a valid number!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
            }
        }
        else if (choice == "4")
        {
            int spaces;
            std::cout << "Enter amount of spaces to move left by: ";
            if (std::cin >> spaces) {
                left(board, history, 2, spaces);
            } else {
                std::cout << "Please enter a valid number!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
            }
        }
        else if (choice == "5")
        {
            auto robot1 = std::find(board.begin(), board.end(), 1);
            auto robot2 = std::find(board.begin(), board.end(), 2);
            std::cout << "Robot 1 is at poisition " << *robot1 << " and Robot 2 is at position " << *robot2 << std::endl;
        }
        else if (choice == "6")
        {
            board = {1, 2, 0, 0, 0, 0, 0, 0, 0, 0};
            std::cout << "The board has been reset, robot 1 is at index 0 and robot 2 is at index 1." << std::endl;
        }
        else if (choice == "7")
        {
            render(board);
        }
        else if (choice == "8")
        {
            int moves;
            std::cout << "Enter amount of moves you would like to roll back: ";
            if (std::cin >> moves) {
                undo(board, history, moves);
            } else {
                std::cout << "Please enter a valid number!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
            }
        }
        else if (choice == "9")
        {
            break;
        }
    }
    return 0;
}