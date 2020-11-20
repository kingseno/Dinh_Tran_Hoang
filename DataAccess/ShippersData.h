#ifndef _Shippers_Data_h
#define _Shippers_Data_h
#include <vector>
#include "../BusinessObject/Shippers.h"

class ShippersData{
public:
    int maxId;
private:
    vector<Shippers> _data;
public:
    ShippersData();
    ShippersData(string);
    int PushBack(Shippers);
    int Update(int, Shippers);
    Shippers Get(int);
    Shippers* GetPointer(int);
    int Delete(int);
    int GetSize();
    int ExportToFile(string);
};
#endif