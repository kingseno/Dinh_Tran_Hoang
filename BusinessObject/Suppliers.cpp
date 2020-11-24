/** @file Suppliers.cpp
 *  @brief Class to create objects which storage data of Suppliers.
 *
 *  @author Nguyen Manh Hoang
 *  @bug No known bugs.
 */
#include "Suppliers.h"
// This is the constructor for creating a new object with no parameters
Suppliers::Suppliers(){
}

// This is a constructor that creates a new object with parameters
Suppliers::Suppliers(int SupplierId, string SupplierName, string ContactName, string Address, string City, string PostalCode, string Country, string Phone) {
    this->SupplierId = SupplierId;
    this->SupplierName = SupplierName;
    this->ContactName = ContactName;
    this->Address = Address;
    this->City = City;
    this->PostalCode = PostalCode;
    this->Country = Country;
    this->Phone = Phone;
}

/** @brief Function convert this object into a string.
 *  
 *  @return a string object;
 */
string Suppliers::ToString(){
    string s;
    s += "{";
    s += to_string(SupplierId) + ", ";
    s += SupplierName + ", ";
    s += ContactName + ", ";
    s += Address + ", ";
    s += City + ", ";
    s += PostalCode + ", ";
    s += Country + ", ";
    s += Phone;
    s += "}";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 */
json Suppliers::ToJson(){
    json j;
    j["SupplierId"] = SupplierId;
    j["SupplierName"] = SupplierName;
    j["ContactName"] = ContactName;
    j["Address"] = Address;
    j["City"] = City;
    j["PostalCode"] = PostalCode;
    j["Country"] = Country;
    j["Phone"] = Phone;
    return j;
}