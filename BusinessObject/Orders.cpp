#include "Orders.h"

Orders::Orders(){
}
Orders::Orders(int OrderId, int CustomerId, int EmployeeId, string OrderDate, int ShipperId){
    this->OrderId = OrderId;
    this->CustomerId = CustomerId;
    this->EmployeeId = EmployeeId;
    this->OrderDate = OrderDate;
    this->ShipperId = ShipperId;
}

string Orders::ToString(){
    string s;
    s += "{";
    s += to_string(OrderId) + ", ";
    s += to_string(CustomerId) + ", ";
    s += to_string(EmployeeId) + ", ";
    s += OrderDate + ", ";
    s += to_string(ShipperId);
    s += "}";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: Orders p(2, "Chang", 1, 1, "bottle", 19.0) -> {"CategoryId":1,"Price":19.0,"ProductId":2,"ProductName":"Chang","SupplierId":1,"Unit":"bottle"}
 */
json Orders::ToJson(){
    json j;
    j["OrderId"] = OrderId;
    j["CustomerId"] = CustomerId;
    j["EmployeeId"] = EmployeeId;
    j["OrderDate"] = OrderDate;
    j["ShipperId"] = ShipperId;
    return j;
}