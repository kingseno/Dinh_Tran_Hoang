#ifndef _Employees_Data_h
#define _Employees_Data_h
#include <vector>
#include "../BusinessObject/Employees.h"

class EmployeesData{
public:
    int maxId;
private:
    vector<Employees> _data;
public:
    EmployeesData();
    EmployeesData(string);
    int PushBack(Employees);
    int Update(int, Employees);
    Employees Get(int);
    Employees* GetPointer(int);
    int Delete(int);
    int GetSize();
    int ExportToFile(string);
};
#endif