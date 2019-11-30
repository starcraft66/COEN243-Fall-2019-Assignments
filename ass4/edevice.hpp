#include <string>
class EDevice
{
    int model_number_, year_built_;
    std::string category_, color_;
    double price_;
    bool status_;
public:
    EDevice();
    EDevice(std::string category_, int model_number_, std::string color_, bool status_, int year_built_, double price_);
    int GetModelNumber();
    std::string GetCategory();
    // Return the departure date
    // What?!?!
    void SetStatus(bool status);
    void SetColor(std::string color);
    void SetPrice(double price);
    int GetYearBuilt();
    bool GetStatus();
};