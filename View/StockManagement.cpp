/** @file StockManagement.cpp
 *  @brief The class creates objects that store data to stock management
 *
 *  @author Nguyen Manh Hoang
 *  @bug No known bugs.
 */

#include "StockManagement.h"
// This is the constructor to load data list from data json file
StockManagement::StockManagement(){
    OrdersData Orders("..\\DataBase\\Orders.json");
    OrderDetailData OrderDetails("..\\DataBase\\OrderDetails.json");
    ProductData Products("..\\DataBase\\Products.json");

    for(int i = 0; i<Orders.GetSize(); i++){
        OrderDate.push_back(Orders.Get(i).OrderDate);
        OrderIdOrders.push_back(Orders.Get(i).OrderId);
    }
    for(int i = 0; i<OrderDetails.getSize(); i++){
        OrderIdOrderDetails.push_back(OrderDetails.getOrderDetailByOrder(i).m_OrderId);
        ProductIdOrderDetails.push_back(OrderDetails.getOrderDetailByOrder(i).m_ProductId);
        Quantity.push_back(OrderDetails.getOrderDetailByOrder(i).m_Quantity);
    }
    for(int i = 0; i<Products.getSize(); i++){
        ProductIdProducts.push_back(Products.getProductByOrder(i).m_ProductId);
        ProductName.push_back(Products.getProductByOrder(i).m_ProductName);
        Price.push_back(Products.getProductByOrder(i).m_Price);
    }
}

/** @brief Function converts string to time.
 *  
 *  Function converts string to time.
 *  @return time_t of string;
 */

time_t StockManagement::String2Time(string t)
{
    string startTime = t;

    time_t tStart;
    int yy, month, dd;
    struct tm whenStart;
    const char *zStart = startTime.c_str();

    sscanf(zStart, "%d-%d-%d", &yy, &month, &dd);
    whenStart.tm_year = yy - 1900;
    whenStart.tm_mon = month - 1;
    whenStart.tm_mday = dd;
    whenStart.tm_hour = 0;
    whenStart.tm_min = 0;
    whenStart.tm_sec = 0;
    whenStart.tm_isdst = -1;

    tStart = mktime(&whenStart);

    return tStart;
}
/** @brief Function compare time.
 *  
 *  Function compare time.
 *  @return 1 if time first >= time later else return 0;
 */
int StockManagement::CompareTime(string st1, string st2){
	time_t time1 = String2Time(st1);
	time_t time2 = String2Time(st2);
    return difftime(time1,time2) >= 0.0 ? 1 : 0; 
}

/** @brief Function "ExportImport" to synthesize the import and export arising in the period.
 *  
 *  Function "ExportImport" to synthesize the import and export arising in the period.
 *  @return void.
 */

void StockManagement::ExportImport(){
    string daybegin, dayend;
    cout << "Enter the goods inspection time: " << endl;
    cout << "From day (yyy-mm-dd): ";
    cin.ignore();
    getline(cin, daybegin);
    cout << "to day (yyyy-mm-dd): ";
    getline(cin, dayend);
    cout << endl << left << setw(12) << "DATE" << setw(9) << "OrderID"<< setw(11) << "ProductID" << setw(35) << "PRODUCT NAME" << setw(9) << "IMPORT" << setw(9) << "EXPORT" << "PRICE" << endl << endl ;
    for(int i = 0; i<OrderDate.size(); i++){
        if(CompareTime(OrderDate.at(i),daybegin)==1 && CompareTime(dayend, OrderDate.at(i))==1 )
        {
            for(int j = 0; j < OrderIdOrderDetails.size(); j++)
            {
                vector<int>::iterator it = find(ProductIdProducts.begin(), ProductIdProducts.end(), ProductIdOrderDetails.at(j));
                int index = distance(ProductIdProducts.begin(), it);

                if(OrderIdOrderDetails.at(j) == OrderIdOrders.at(i) )
                {
                    cout << left << setw(12) << OrderDate.at(i) << setw(9) << OrderIdOrders.at(i)<< setw(11) << ProductIdProducts.at(index) << setw(35) << ProductName.at(index) << setw(9);
                    if (Quantity.at(j) > 0) cout << Quantity.at(j) << setw(9) << "-" << setw(9) << Price.at(index)*Quantity.at(j) << endl;
                    else cout << "-" << setw(9) << -Quantity.at(j) << setw(9) << -Price.at(index)*Quantity.at(j) << endl;
                }
            }
        }

    }
}

/** @brief Function "Inventory()" to synthesize inventory in the period.
 *  
 *  Function "Inventory()" to synthesize inventory in the period.
 *  @return void.
 */

void StockManagement::Inventory(){
    vector<int> ProductExport(ProductIdProducts.size());
    vector<int> ProductImport(ProductIdProducts.size());
    string daybegin, dayend;
    cout << "Enter the goods inspection time: " << endl;
    cout << "From day (yyyy-mm-dd): ";
    cin.ignore();
    getline(cin, daybegin);
    cout << "to day (yyyy-mm-dd): ";
    getline(cin, dayend);
    cout << endl << left << setw(11) << "ProductID" << setw(35) << "ProductName" << setw(9) << "IMPORT" << setw(9) << "EXPORT" << setw(11) << "INVENTORY"<< setw(9)<< "PRICE" << endl << endl ;
    for(int i = 0; i<OrderDate.size(); i++){
        if(CompareTime(OrderDate.at(i),daybegin)==1 && CompareTime(dayend, OrderDate.at(i))==1 )
        {
            for(int j = 0; j < OrderIdOrderDetails.size(); j++)
            {
                vector<int>::iterator it = find(ProductIdProducts.begin(), ProductIdProducts.end(), ProductIdOrderDetails.at(j));
                int index = distance(ProductIdProducts.begin(), it);

                if(OrderIdOrderDetails.at(j) == OrderIdOrders.at(i) )
                {
                    if(Quantity.at(j) > 0)
                        ProductImport.at(index) = ProductImport.at(index) + Quantity.at(j);
                    else
                    {
                        ProductExport.at(index) = ProductExport.at(index) + Quantity.at(j);
                    }
                }
                
            }
        }

    }    
    float SumExport = 0, SumImport = 0;
    for (int i = 0; i < ProductExport.size(); i++)
    {
        SumExport = SumExport + ProductExport.at(i)*Price.at(i);
        SumImport = SumImport + ProductImport.at(i)*Price.at(i);
        if(ProductExport.at(i) != 0 || ProductImport.at(i) != 0)
            cout << left << setw(11) << ProductIdProducts.at(i) << setw(35) << ProductName.at(i)<< setw(9) << ProductImport.at(i) << setw(9) << -ProductExport.at(i) 
                        << setw(11) << ProductExport.at(i) + ProductImport.at(i) << setw(9) <<(ProductExport.at(i) + ProductImport.at(i))*Price.at(i) << endl;
    }

    cout << "Total amount EXPOR: " << -SumExport << endl;
    cout << "Total amount IMPORT: " << SumImport << endl;
    cout << "Total amount INVENTORY: " << SumImport + SumExport << endl;


}

/** @brief Function "Display()" to select and display information import, export and inventory by the time.
 *  
 *  Function "Display()" to select and display information import, export and inventory by the time.
 *  @return void.
 */

void StockManagement::Display(){
    int id = 1;
    while(id != 3){

        cout << endl << "STOCK MANAGEMENT" << endl;
        cout << endl << "Please choose what you want:" << endl << endl;
        cout << "1. Synthesize the import and export" << endl;
        cout << "2. Report inventory and inventory value" << endl;
        cout << "3. Exit" << endl;

        do {
            cout << endl << "You choose: ";
            cin >> id;
        } while (id < 1 || id > 3);

        switch(id) {
            case 1:
                    ExportImport();
                    system("pause");
                    system("cls");
                    break;
            case 2: 
                    Inventory();
                    system("pause");
                    system("cls");
                    break;
                 }
    }
}
