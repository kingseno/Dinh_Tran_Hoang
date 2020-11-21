#ifndef _Suppliers_h
#define _Suppliers_h

#include <string>
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class Suppliers{
public:
    int SupplierId;
    string SupplierName, ContactName, Address, City, PostalCode, Country, Phone;
public:
    Suppliers();
    Suppliers(int SupplierId, string SupplierName, string ContactName, string Address, string City, string PostalCode, string Country, string Phone);
    string ToString();
    json ToJson();
};
#endif