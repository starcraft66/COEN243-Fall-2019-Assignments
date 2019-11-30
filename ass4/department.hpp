#include <string>
#include <vector>
#include "employee.hpp"
class Department
{
    std::string id_number_, name_, history_;
    std::vector<Employee> employees_;
public:
    Department(std::string id_number, std::string name, std::string history);
    std::string GetIdNumber();
    std::string GetName();
    void SetName(std::string name);
    std::string GetHistory();
    void SetHistory(std::string history);
    // Return the departure date
    // What?!?!
    void AddEmployee(Employee employee);
    void RemoveEmployee(Employee employee);
    bool DoesEmployeeWorkInDepartment(int employee_id);
    void PrintEmployeeList();
    void PrintNumberOfEmployees();
};