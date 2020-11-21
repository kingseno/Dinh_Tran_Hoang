#include "Customers.h"

Customers::Customers(){
}
Customers::Customers(int CustomerId, string CustomerName, string ContactName, string Address, string City, string PostalCode, string Country){
    this->CustomerId = CustomerId;
    this->CustomerName = CustomerName;
    this->ContactName = ContactName;
    this->Address = Address;
    this->City = City;
    this->PostalCode = PostalCode;
    this->Country = Country;
}

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
 *  Example: Customers p(2, "Chang", 1, 1, "bottle", 19.0) -> {"CategoryId":1,"Price":19.0,"CustomerId":2,"CustomerName":"Chang","SupplierId":1,"Unit":"bottle"}
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