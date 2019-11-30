#include <string>
class House {
    int age_, rooms_;
    std::string type_;
public:
    House();
    House(int age, std::string type, int rooms);
    int GetAge();
    int GetRooms();
    std::string GetType();
    void SetAge(int age);
    double EstimatePrice();
};