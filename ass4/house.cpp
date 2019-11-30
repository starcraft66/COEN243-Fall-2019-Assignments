#include "house.hpp"

House::House()
{

}

House::House(int age, std::string type, int rooms)
{
    this->age_ = age;
    this->type_ = type;
    this->rooms_ = rooms;
}

int House::GetAge()
{
    return this->age_;
}

int House::GetRooms()
{
    return this->rooms_;
}

std::string House::GetType()
{
    return this->type_;
}

void House::SetAge(int age)
{
    this->age_ = age;
}

double House::EstimatePrice()
{
    double base;
    if (this->type_ == "Detached")
    {
        base = 200000L;
        for(int i = 0; i < this->age_; i++)
        {
            base *= 1.02L;
        }
        return base;
    }
    else if (this->type_ == "Semi‐Attached")
    {
        base = 150000L;
        if(this->age_ > 5)
        {
            for(int i = 0; i < 5; i++)
            {
                base *= 1.02L;
            }
            for(int i = 0; i < this->age_ - 5; i++)
            {
                base *= 1.03L;
            }
        }
        else
        {
            for(int i = 0; i < this->age_; i++)
            {
                base *= 1.02;
            }
        }
        return base;
    }
    else if (this->type_ == "Attached")
    {
        base = 100000L;
        if(this->age_ > 5)
        {
            for(int i = 0; i < 5; i++)
            {
                base *= 1.01L;
            }
            for(int i = 0; i < this->age_ - 5; i++)
            {
                base *= 1.02L;
            }
        }
        else
        {
            for(int i = 0; i < this->age_; i++)
            {
                base *= 1.01L;
            }
        }
        return base;
    }
    else
    {
        //🖕🏻
        return 0;
    }
}