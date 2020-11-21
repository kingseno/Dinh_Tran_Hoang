#include "Suppliers.h"

Suppliers::Suppliers(){
}
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
 *  Example: Suppliers p(2, "Chang", 1, 1, "bottle", 19.0) -> {"CategoryId":1,"Price":19.0,"ProductId":2,"ProductName":"Chang","SupplierId":1,"Unit":"bottle"}
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