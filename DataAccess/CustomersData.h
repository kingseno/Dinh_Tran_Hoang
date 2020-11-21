#ifndef _Customers_Data_h
#define _Customers_Data_h
#include <vector>
#include "../businessobjects/Customers.h"

class CustomersData{
public:
    int maxId;
private:
    vector<Customers> _data;
public:
    CustomersData();
    CustomersData(string);
    int PushBack(Customers);
    int Update(int, Customers);
    Customers Get(int);
    Customers* GetPointer(int);
    vector<Customers>::iterator GetCustomerById(int CustomerId);
    void DeleteCustomerById(int CustomerId);
    int GetSize();
    int ExportToFile(string);
};
#endif