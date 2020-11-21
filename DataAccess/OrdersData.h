#ifndef _Orders_Data_h
#define _Orders_Data_h
#include <vector>
#include "../businessobjects/Orders.h"

class OrdersData{
public:
    int maxId;
private:
    vector<Orders> _data;
public:
    OrdersData();
    OrdersData(string);
    int PushBack(Orders);
    int Update(int, Orders);
    Orders Get(int);
    Orders* GetPointer(int);
    vector<Orders>::iterator GetOrderById(int OrderId);
    void DeleteOrderById(int OrderId);
    int GetSize();
    int ExportToFile(string);
};
#endif