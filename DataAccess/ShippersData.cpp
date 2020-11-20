/** @file ProductsData.h
 *  @brief ProductsData stores all Products objects
 *  
 *  @author Ngo Nguyen Bao Tran
 *  @bug No known bugs.
 */

#include "ShippersData.h"
#include <fstream>
#include "../Util/json.hpp"

using json = nlohmann::json;

ShippersData::ShippersData(){
    maxId = 0;
    _data.resize(0);
}

/** @brief Function initial a ShippersData object and load the filename to object s.
 *  
 *  Function initial a ShippersData object and load the filename to object s.
 *  @return ShippersData object ;
 */
ShippersData::ShippersData(string filename){
    maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Shippers s(
            j["ShipperID"],
            j["ShipperName"],
            j["Phone"]
        );
        _data.push_back(s);
    }
    inFile.close();
}

/** @brief Function add a Shippers object to the end of the list inside ProductsData.
 *  
 *  Function add a Products object to the end of the list inside ProductsData.
 *  @return maxId of Products object inside ProductsData;
 */
int ShippersData::PushBack(Shippers s){
    //at first, there nothing, maxId = 0
    
    //assume s.ShipperID = 5, then maxId = 5
    if (maxId < s.ShipperID) maxId = s.ShipperID;

    //add a Products object to ProductsData
    _data.push_back(s);
    return maxId;
}

/** @brief Function updates a Shippers object at a position inside the list inside ShippersData.
 *  
 *  Function updates a Shippers object at a position inside the list inside ShippersData.
 *  @return maxShipperId of Shippers object inside ShippersData;
 *  if fail, return -1;
 */
int ShippersData::Update(int i, Shippers s){
    if (i < 0) return -1;
    if (i >= _data.size()) return -1;
    _data[i] = s;
    //assume p.ProductId = 5 and maxId = 4, then maxId = 5
    if (maxId < s.ShipperID) maxId = s.ShipperID;
    return maxId;
}

Shippers ShippersData::Get(int i){
    return _data[i];
}

/** @brief Function return a Shippers object at a position inside the list inside ShippersData.
 *  
 *  Function return a Shippers object at a position inside the list inside ShippersData.
 *  @return Shippers object;
 *  if fail, return NULL;
 */
Shippers* ShippersData::GetPointer(int i){
    Shippers* s = nullptr;
    if (i < 0) return s;
    if (i >= _data.size()) return s;
    s = &_data[i];
    return s;
}

/** @brief Function return size of ShippersData.
 *  
 *  Function return size of ShippersData. This is the quantity of Shippers objects inside ShippersData.
 *  @return number of Shippers objects;
 */
int ShippersData::GetSize(){
    return _data.size();
}

/** @brief Function delete ShippersData at position pos. 
 *  
 *  Function return size of ShippersData. This is the quantity of Shippers objects inside ShippersData.
 *  @return number of Shippers objects;
 */
int ShippersData::Delete(int pos){
    _data.erase(_data.begin() + pos);
    return maxId;
}

/** @brief Function write all data in ShippersData to file.
 *  
 *  Function write all data in ShippersData to file.
 *  @return 1 if success, 0 if fail;
 */
int ShippersData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Shippers s:_data){
        outFile << s.ToJson() << endl;
    }
    outFile.close();
    return 1;
}