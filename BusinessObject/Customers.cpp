/** @file Customers.cpp
 *  @brief Class to create objects which storage data of Customers.
 *
 *  @author Nguyen Manh Hoang
 *  @bug No known bugs.
 */

#include "Customers.h"
// This is the constructor for creating a new object with no parameters

Customers::Customers(){
}

// This is a constructor that creates a new object with parameters

Customers::Customers(int CustomerId, string CustomerName, string ContactName, string Address, string City, string PostalCode, string Country){
    this->CustomerId = CustomerId;
    this->CustomerName = CustomerName;
    this->ContactName = ContactName;
    this->Address = Address;
    this->City = City;
    this->PostalCode = PostalCode;
    this->Country = Country;
}
/** @brief Function convert this object into a string.
 *  
 *  @return a string object;
 */

string Customers::ToString(){
    string s;
    s += "{";
    s += to_string(CustomerId) + ", ";
    s += CustomerName + ", ";
    s += ContactName + ", ";
    s += Address + ", ";
    s += City + ", ";
    s += PostalCode + ", ";
    s += Country;
    s += "}";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 */
json Customers::ToJson(){
    json j;
    j["CustomerId"] = CustomerId;
    j["CustomerName"] = CustomerName;
    j["ContactName"] = ContactName;
    j["Address"] = Address;
    j["City"] = City;
    j["PostalCode"] = PostalCode;
    j["Country"] = Country;
    return j;
}