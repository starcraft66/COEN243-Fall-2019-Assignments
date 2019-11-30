#include "edevice.hpp"

EDevice::EDevice()
{

}

EDevice::EDevice(std::string category, int model_number, std::string color, bool status, int year_built, double price)
{
    this->category_ = category;
    this->model_number_ = model_number;
    this->color_ = color;
    this->status_ = status;
    this->year_built_ = year_built;
    this->price_ = price;
}

int EDevice::GetModelNumber()
{
    return this->model_number_;
}

std::string EDevice::GetCategory()
{
    return this->category_;
}

void EDevice::SetStatus(bool status)
{
    this->status_ = status;
}

void EDevice::SetColor(std::string color)
{
    this->color_ = color;
}

void EDevice::SetPrice(double price)
{
    this->price_ = price;
}

int EDevice::GetYearBuilt()
{
    return this->year_built_;
}

bool EDevice::GetStatus()
{
    return this->status_;
}