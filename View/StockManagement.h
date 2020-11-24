#ifndef _Stock_Management_h
#define _Stock_Management_h
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>  
#include <time.h> 
#include <iomanip>
#include <stdlib.h>
#include "../DataAccess/OrdersData.h"
#include "../DataAccess/OrderDetailData.h"
#include "../DataAccess/ProductData.h"
using namespace std;
class StockManagement{
private:
    vector<string> OrderDate, ProductName;
    vector<int> OrderIdOrders,OrderIdOrderDetails, ProductIdOrderDetails,ProductIdProducts, Quantity;
    vector<float> Price;
    time_t String2Time(string t);
    int CompareTime(string st1, string st2);
    void ExportImport();
    void Inventory();
public:
    StockManagement();
    void Display(); 
};

#endif