#ifndef _Suppliers_Data_h
#define _Suppliers_Data_h
#include <vector>
#include "../businessobjects/Suppliers.h"

class SuppliersData{
public:
    int maxId;
private:
    vector<Suppliers> _data;
public:
    SuppliersData();
    SuppliersData(string);
    int PushBack(Suppliers);
    int Update(int, Suppliers);
    Suppliers Get(int);
    Suppliers* GetPointer(int);
    vector<Suppliers>::iterator GetSupplierById(int SupplierId);
    void DeleteSupplierById(int SupplierId);
    int GetSize();
    int ExportToFile(string);
};
#endif