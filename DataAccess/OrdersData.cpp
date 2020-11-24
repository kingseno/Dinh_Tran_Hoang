/** @file OrdersData.h
 *  @brief OrdersData stores all Orders objects
 *  
 *  @author Nguyen Manh Hoang
 *  @bug No known bugs.
 */

#include "OrdersData.h"
using json = nlohmann::json;

// Constructor
OrdersData::OrdersData(){
    maxId = 0;
    _data.resize(0);
}

// Constructor to load Orders list from json file
OrdersData::OrdersData(string filename){
    maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Orders p(
            j["OrderId"],
            j["CustomerId"],
            j["EmployeeId"],
            j["OrderDate"],
            j["ShipperId"]
        );
        _data.push_back(p);
    }
    inFile.close();
}
/** @brief Function add a Orders object to the end of the list inside OrdersData.
 *  
 *  Function add a Orders object to the end of the list inside OrdersData.
 *  @return maxId of Orders object inside OrdersData;
 */
int OrdersData::PushBack(Orders p){
    //at first, there nothing, maxId = 0
    
    //assume p.OrderId = 5, then maxId = 5
    if (maxId < p.OrderId) maxId = p.OrderId;

    //add a Orders object to OrdersData
    _data.push_back(p);
    return maxId;
}

/** @brief Function updates a Orders object at a position inside the list inside OrdersData.
 *  
 *  Function updates a Orders object at a position inside the list inside OrdersData.
 *  @return maxId of Orders object inside OrdersData;
 *  if fail, return -1;
 */
int OrdersData::Update(int i, Orders p){
    if (i < 0) return -1;
    if (i >= _data.size()) return -1;
    _data[i] = p;
    //assume p.OrderId = 5 and maxId = 4, then maxId = 5
    if (maxId < p.OrderId) maxId = p.OrderId;
    return maxId;
}

/** @brief Function return a Orders object at a position inside the list inside OrdersData.
 *  
 *  Function return a Orders object at a position inside the list inside OrdersData.
 *  @return Orders object;
 */
Orders OrdersData::Get(int i){
    return _data[i];
}

/** @brief Function return a Orders object at a position inside the list inside OrdersData.
 *  
 *  Function return a Orders object at a position inside the list inside OrdersData.
 *  @return Orders object;
 *  if fail, return NULL;
 */

Orders* OrdersData::GetPointer(int i){
    Orders* p = nullptr;
    if (i < 0) return p;
    if (i >= _data.size()) return p;
    p = &_data[i];
    return p;
}
// Function "GetOrderById" get Order with its ID in the Order list.
vector<Orders>::iterator OrdersData::GetOrderById(int OrderId){
	vector<Orders>::iterator it = find_if(_data.begin(),_data.end(), [&](const Orders& od) {
		return od.OrderId == OrderId;
	});
        return it;
}

// Function "DeleteOrderById" Delete Order with its ID in the Order list.
void OrdersData::DeleteOrderById(int OrderId){
    _data.erase(GetOrderById(OrderId));
}
/** @brief Function return size of OrdersData.
 *  
 *  Function return size of OrdersData. This is the quantity of Orders objects inside OrdersData.
 *  @return number of Orders objects;
 */
int OrdersData::GetSize(){
    return _data.size();
}

/** @brief Function write all data in OrdersData to file.
 *  
 *  Function write all data in OrdersData to file.
 *  @return 1 if success, 0 if fail;
 */
int OrdersData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Orders p:_data){
        outFile << p.ToJson() << endl;
    }
    outFile.close();
    return 1;
}