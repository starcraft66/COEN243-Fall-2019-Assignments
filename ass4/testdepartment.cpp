#include <iostream>
#include <array>
#include "department.hpp"

int main(int argc, char *argv[])
{
    Employee lastemp;
    std::string id_number, name, history;
    std::cout << "Enter the name of the department: ";
    std::getline(std::cin, name);
    std::cout << "Enter the department's identification number: ";
    std::getline(std::cin, id_number);
    std::cout << "Enter the department's history: ";
    std::getline(std::cin, history);
    Department department = Department(id_number, name, history);
    for(int i = 0; i < 5; i++)
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
        Employee emp = Employee(id, first_name, last_name, dob, address, year_hired, salary, tel_area_code, tel_number);
        department.AddEmployee(emp);
        lastemp = emp;
    }
    std::cout << "Department information" << std::endl;
    std::cout << "Identification Number: " << department.GetIdNumber() << std::endl;
    std::cout << "Name: " << department.GetName() << std::endl;
    std::cout << "History: " << department.GetHistory() << std::endl;
    std::cout << "Enter the new name of the department: ";
    std::getline(std::cin, name);
    department.SetName(name);
    std::cout << "Enter the department's new history: ";
    std::getline(std::cin, history);
    department.SetHistory(history);
    department.RemoveEmployee(lastemp);
    std::cout << "Removed the last employee" << std::endl;
    if(department.DoesEmployeeWorkInDepartment(2))
    {
        std::cout << "Employee 2 works in the department." << std::endl;
    }
    else
    {
        std::cout << "Employee 2 doesn't work in the department." << std::endl;
    }
    std::cout << "List of employees working in the department:" << std::endl;
    department.PrintEmployeeList();
    std::cout << "Number of employees working in the department: ";
    department.PrintNumberOfEmployees();
}