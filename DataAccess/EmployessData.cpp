/** @file ProductsData.h
 *  @brief ProductsData stores all Products objects
 *  
 *  @author Ngo Nguyen Bao Tran
 *  @bug No known bugs.
 */

#include "EmployeesData.h"
#include <fstream>
#include "../Util/json.hpp"

using json = nlohmann::json;

EmployeesData::EmployeesData(){
    maxId = 0;
    _data.resize(0);
}

/** @brief Function initial a EmployeesData object and load the filename to object e.
 *  
 *  Function initial a EmployeesData object and load the filename to object e.
 *  @return EmployeesData object ;
 */
EmployeesData::EmployeesData(string filename){
    maxId = 0;
    _data.resize(0);

    ifstream inFile(filename);
    const int maxSize = 2000;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Employees e(
            j["EmployeeID"],
            j["LastName"],
            j["FirstName"],
            j["BirthDate"],
            j["Photo"],
            j["Notes"]
        );
        _data.push_back(e);    
    }
    inFile.close();
}

/** @brief Function add a Employees object to the end of the list inside EmployeesData.
 *  
 *  Function add a Products object to the end of the list inside EmployeesData.
 *  @return maxId of Employees object inside EmployeesData;
 */
int EmployeesData::PushBack(Employees e){
    //at first, there nothing, maxId = 0
    
    //assume e.EmployeeId = 5, then maxId = 5
    if (maxId < e.EmployeeID) maxId = e.EmployeeID;

    //add a Employees object to ProductsData
    _data.push_back(e);
    return maxId;
}

/** @brief Function updates a Employees object at a position inside the list inside EmployeesData.
 *  
 *  Function updates a Employees object at a position inside the list inside EmployeesData.
 *  @return maxEmployeeId of Employees object inside EmployeesData;
 *  if fail, return -1;
 */
int EmployeesData::Update(int i, Employees e){
    if (i < 0) return -1;
    if (i >= _data.size()) return -1;
    _data[i] = e;
    //assume p.ProductId = 5 and maxId = 4, then maxId = 5
    if (maxId < e.EmployeeID) maxId = e.EmployeeID;
    return maxId;
}

/** @brief Function return a Products object at a position inside the list inside ProductsData.
 *  
 *  Function return a Products object at a position inside the list inside ProductsData.
 *  @return Products object;
 *  if fail, return NULL;
 */
Employees EmployeesData::Get(int i){
    return _data[i];
}

/** @brief Function return a Employees object at a position inside the list inside EmployeesData.
 *  
 *  Function return a Employees object at a position inside the list inside EmployeesData.
 *  @return Employees object;
 *  if fail, return NULL;
 */
Employees* EmployeesData::GetPointer(int i){
    Employees* e = nullptr;
    if (i < 0) return e;
    if (i >= _data.size()) return e;
    e = &_data[i];
    return e;
}

/** @brief Function return size of ProductsData.
 *  
 *  Function return size of ProductsData. This is the quantity of Products objects inside ProductsData.
 *  @return number of Products objects;
 */
int EmployeesData::GetSize(){
    return _data.size();
}

/** @brief Function delete EmployeesData at position pos. 
 *  
 *  Function return size of EmployeesData. This is the quantity of Employees objects inside EmployeesData.
 *  @return number of Employees objects;
 */
int EmployeesData::Delete(int pos){
    _data.erase(_data.begin() + pos);
    return maxId;
}

/** @brief Function write all data in EmployeesData to file.
 *  
 *  Function write all data in EmployeesData to file.
 *  @return 1 if success, 0 if fail;
 */
int EmployeesData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Employees e:_data){
        outFile << e.ToJson() << endl;
    }
    outFile.close();
    return 1;
}