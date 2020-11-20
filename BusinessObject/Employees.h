#ifndef _Employees_h
#define _Employees_h

#include <string>
#include "../Util/json.hpp"

using namespace std;
using json = nlohmann::json;

class Employees{
public:
    int EmployeeID;
    string LastName, FirstName, BirthDate, Photo, Notes;
public:
    Employees();
    Employees(int EmployeeID, string LastName, string FirstName, string BirthDate, string Photo, string Notes);
    string ToString();
    json ToJson();
};
#endif