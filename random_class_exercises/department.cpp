#include <iostream>
#include <algorithm>
#include "department.hpp"

Department::Department(std::string id_number, std::string name, std::string history)
{
    this->id_number_ = id_number;
    this->name_ = name;
    this->history_ = history;
}

std::string Department::GetIdNumber()
{
    return this->id_number_;
}

std::string Department::GetName()
{
    return this->name_;
}

void Department::SetName(std::string name)
{
    this->name_ = name;
}

std::string Department::GetHistory()
{
    return this->history_;
}

void Department::SetHistory(std::string history)
{
    this->history_ = history;
}

void Department::AddEmployee(Employee employee)
{
    this->employees_.push_back(employee);
}

void Department::RemoveEmployee(Employee employee)
{
    this->employees_.erase(std::remove(this->employees_.begin(), this->employees_.end(), employee), this->employees_.end());
}

bool Department::DoesEmployeeWorkInDepartment(int employee_id)
{
    for (auto &employee : this->employees_)
    {
        if (employee.GetId() == employee_id)
        {
            return true;
        }
    }
    return false;
}

void Department::PrintEmployeeList()
{
    for (auto &employee : this->employees_)
    {
        std::cout << employee.GetFullName() << std::endl;
    }
}

void Department::PrintNumberOfEmployees()
{
    std::cout << this->employees_.size() << std::endl;
}
