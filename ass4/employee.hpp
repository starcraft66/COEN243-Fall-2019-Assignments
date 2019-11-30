#include <string>
class Employee
{
    int id_, year_hired_, tel_area_code_;
    std::string first_name_, last_name_, dob_, address_, tel_number_;
    double salary_;
public:
    Employee();
    Employee(int id_, std::string first_name_, std::string last_name_, std::string dob_, std::string address_, int year_hired_, double salary_, int tel_area_code_, std::string tel_number_);
    int GetId();
    void SetId(int id);
    std::string GetFirstName();
    void SetFirstName(std::string first_name);
    std::string GetLastName();
    void SetLastName(std::string last_name);
    int GetYearHired();
    std::string GetFullName();
    std::string GetDateOfBirth();
    void SetDateOfBirth(std::string dob);
    double GetSalary();
    void SetSalary(double salary);
    std::string GetAddress();
    void SetAddress(std::string address);
    std::string GetTelephoneNumber();
    void SetTelephoneNumber(int tel_area_code, std::string tel_number);
    static bool HaveSameLastName(Employee e1, Employee e2);
    static bool HaveSameSalaryOrHiredInSameYear(Employee e1, Employee e2);
    bool operator==(const Employee& c) const;
};