#include <iostream>
#include <array>
#include "employee.hpp"

int main(int argc, char *argv[])
{
    std::array<Employee, 2> employees;
    for(int i = 0; i < 2; i++)
    {
        int id, year_hired, tel_area_code;
        std::string first_name, last_name, dob, address, tel_number;
        double salary;
        std::cout << "Entering information for employee #" << i + 1 << std::endl;
        std::cout << "Enter the first name: ";
        std::getline(std::cin, first_name);
        std::cout << "Enter the last name: ";
        std::getline(std::cin, last_name);
        std::cout << "Enter the address: ";
        std::getline(std::cin, address);
        std::cout << "Enter the id (int): ";
        std::cin >> id;
        std::cout << "Enter the year hired: ";
        std::cin >> year_hired;
        std::cout << "Enter the phone number area code (int): ";
        std::cin >> tel_area_code;
        std::cout << "Enter the phone number: ";
        std::getline(std::cin, tel_number);
        std::cout << "Enter the salary: ";
        std::cin >> salary;
        std::cout << "Enter the date of birth: ";
        std::getline(std::cin, dob);
        employees[i] = Employee(id, first_name, last_name, dob, address, year_hired, salary, tel_area_code, tel_number);
    }
    int i = 0;
    for(auto employee : employees)
    {
        i++;
        int year_hired, tel_area_code;
        std::string first_name, last_name, dob, address, tel_number;
        double salary;
        std::cout << "Device information for employee #" << i << ":" << std::endl;
        std::cout << "ID number: " << employee.GetId() << std::endl;
        std::cout << "First Name: " << employee.GetFirstName() << std::endl;
        std::cout << "Last Name: " << employee.GetLastName() << std::endl;
        std::cout << "Hired Year: " << employee.GetYearHired() << std::endl;
        std::cout << "Full Name: " << employee.GetFullName() << std::endl;
        std::cout << "Date Of Birth: " << employee.GetDateOfBirth() << std::endl;
        std::cout << "Salary: " << employee.GetSalary() << std::endl;
        std::cout << "Address: " << employee.GetAddress() << std::endl;
        std::cout << "Telephone Number: " << employee.GetTelephoneNumber() << std::endl;
        std::cout << "Enter a new first name: " << std::endl;
        std::cin >> first_name;
        employee.SetFirstName(first_name);
        std::cout << "Enter a new last name: " << std::endl;
        std::cin >> last_name;
        employee.SetLastName(last_name);
        std::cout << "Enter a new date of birth: " << std::endl;
        std::getline(std::cin, dob);
        employee.SetDateOfBirth(dob);
        std::cout << "Enter a new salary: " << std::endl;
        std::cin >> salary;
        employee.SetSalary(salary);
        std::cout << "Enter a new address: " << std::endl;
        std::getline(std::cin, address);
        employee.SetAddress(address);
        std::cout << "Enter a new telephone number area code (int): " << std::endl;
        std::cin >> tel_area_code;
        std::cout << "Enter a new telephone number: " << std::endl;
        std::cin >> tel_number;
        employee.SetTelephoneNumber(tel_area_code, tel_number);
    }
    if(Employee::HaveSameLastName(employees[0], employees[1]))
    {
        std::cout << "Both employees have the same last name." << std::endl;
    }
    else
    {
        std::cout << "Both employees don't have the same last name." << std::endl;
    }
    if(Employee::HaveSameSalaryOrHiredInSameYear(employees[0], employees[1]))
    {
        std::cout << "Both employees have the same salary or were hired in the same year." << std::endl;
    }
    else
    {
        std::cout << "Both employees don't have the same salary and weren't hired in the same year." << std::endl;
    }
}