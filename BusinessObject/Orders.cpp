/** @file Orders.cpp
 *  @brief Class to create objects which storage data of Orders.
 *
 *  @author Nguyen Manh Hoang
 *  @bug No known bugs.
 */

#include "Orders.h"

// This is the constructor for creating a new object with no parameters
Orders::Orders(){
}
// This is a constructor that creates a new object with parameters
Orders::Orders(int OrderId, int CustomerId, int EmployeeId, string OrderDate, int ShipperId){
    this->OrderId = OrderId;
    this->CustomerId = CustomerId;
    this->EmployeeId = EmployeeId;
    this->OrderDate = OrderDate;
    this->ShipperId = ShipperId;
}

/** @brief Function convert this object into a string.
 *  
 *  @return a string object;
 */
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