#include "employee.hpp"

Employee::Employee()
{

}

Employee::Employee(int id, std::string first_name, std::string last_name, Date dob, std::string address, int year_hired, double salary, int tel_area_code, std::string tel_number)
{
    this->id_ = id;
    this->first_name_ = first_name;
    this->last_name_ = last_name;
    this->dob_ = dob;
    this->address_ = address;
    this->year_hired_ = year_hired;
    this->salary_ = salary;
    this->tel_area_code_ = tel_area_code;
    this->tel_number_ = tel_number;
}

int Employee::GetId()
{
    return this->id_;
}

void Employee::SetId(int id)
{
    this->id_ = id;
}

std::string Employee::GetFirstName()
{
    return this->first_name_;
}

void Employee::SetFirstName(std::string first_name)
{
    this->first_name_ = first_name;
}

std::string Employee::GetLastName()
{
    return this->last_name_;
}

void Employee::SetLastName(std::string last_name)
{
    this->last_name_ = last_name;
}

int Employee::GetYearHired()
{
    return this->year_hired_;
}

std::string Employee::GetFullName()
{
    return this->first_name_ + " " + this->last_name_;
}

Date Employee::GetDateOfBirth()
{
    return this->dob_;
}

void Employee::SetDateOfBirth(Date dob)
{
    this->dob_ = dob;
}

double Employee::GetSalary()
{
    return this->salary_;
}

void Employee::SetSalary(double salary)
{
    this->salary_ = salary;
}

std::string Employee::GetAddress()
{
    return this->address_;
}

void Employee::SetAddress(std::string address)
{
    this->address_ = address;
}

std::string Employee::GetTelephoneNumber()
{
    return std::to_string(this->tel_area_code_) + "-" + this->tel_number_;
}

void Employee::SetTelephoneNumber(int tel_area_code, std::string tel_number)
{
    this->tel_area_code_ = tel_area_code;
    this->tel_number_ = tel_number;
}

bool Employee::HaveSameLastName(Employee e1, Employee e2)
{
    return e1.GetLastName() == e2.GetLastName();
}

bool Employee::HaveSameSalaryOrHiredInSameYear(Employee e1, Employee e2)
{
    return (e1.GetSalary() == e2.GetSalary()) || (e1.GetYearHired() == e2.GetYearHired());
}

bool Employee::operator==(const Employee& e) const{
    return this->id_ == e.id_;
}
