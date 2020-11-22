#ifndef _Orders_h
#define _Orders_h

#include <string>
#include "../Util/json.hpp"

using namespace std;
using json = nlohmann::json;

class Orders{
public:
    int OrderId, CustomerId, EmployeeId, ShipperId;
    string OrderDate;
public:
    Orders();
    Orders(int OrderId, int CustomerId, int EmployeeId, string OrderDate, int ShipperId);
    string ToString();
    json ToJson();
};
#endif