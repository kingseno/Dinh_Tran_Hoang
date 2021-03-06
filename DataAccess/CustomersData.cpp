/** @file CustomersData.h
 *  @brief CustomersData stores all Customers objects
 *  
 *  @author Nguyen Manh Hoang
 *  @bug No known bugs.
 */

#include "CustomersData.h"

using json = nlohmann::json;

// Constructor
CustomersData::CustomersData(){
    maxId = 0;
    _data.resize(0);
}

// Constructor to load Customers list from json file
 
CustomersData::CustomersData(string filename){
    maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Customers p(
            j["CustomerId"],
            j["CustomerName"],
            j["ContactName"],
            j["Address"],
            j["City"],
            j["PostalCode"],
            j["Country"]
        );
        _data.push_back(p);
    }
    inFile.close();
}
/** @brief Function add a Customers object to the end of the list inside CustomersData.
 *  
 *  Function add a Customers object to the end of the list inside CustomersData.
 *  @return maxId of Customers object inside CustomersData;
 */
int CustomersData::PushBack(Customers p){
    //at first, there nothing, maxId = 0
    
    //assume p.CustomerId = 5, then maxId = 5
    if (maxId < p.CustomerId) maxId = p.CustomerId;

    //add a Customers object to CustomersData
    _data.push_back(p);
    return maxId;
}

/** @brief Function updates a Customers object at a position inside the list inside CustomersData.
 *  
 *  Function updates a Customers object at a position inside the list inside CustomersData.
 *  @return maxId of Customers object inside CustomersData;
 *  if fail, return -1;
 */
int CustomersData::Update(int i, Customers p){
    if (i < 0) return -1;
    if (i >= _data.size()) return -1;
    _data[i] = p;
    //assume p.CustomerId = 5 and maxId = 4, then maxId = 5
    if (maxId < p.CustomerId) maxId = p.CustomerId;
    return maxId;
}

/** @brief Function return a Customers object at a position inside the list inside CustomersData.
 *  
 *  Function return a Customers object at a position inside the list inside CustomersData.
 *  @return Customers object;
 */
Customers CustomersData::Get(int i){
    return _data[i];
}
/** @brief Function return a Customers object at a position inside the list inside CustomersData.
 *  
 *  Function return a Customers object at a position inside the list inside CustomersData.
 *  @return Customers object;
 *  if fail, return NULL;
 */

Customers* CustomersData::GetPointer(int i){
    Customers* p = nullptr;
    if (i < 0) return p;
    if (i >= _data.size()) return p;
    p = &_data[i];
    return p;
}

// Function "GetCustomerById" get Customer with its ID in the Customer list.

vector<Customers>::iterator CustomersData::GetCustomerById(int CustomerId){
	vector<Customers>::iterator it = find_if(_data.begin(),_data.end(), [&](const Customers& ct) {
		return ct.CustomerId == CustomerId;
	});
        return it;
}

// Function "DeleteCustomerById" Delete Customer with its ID in the Customer list.
void CustomersData::DeleteCustomerById(int CustomerId){
    _data.erase(GetCustomerById(CustomerId));
}

/** @brief Function return size of CustomersData.
 *  
 *  Function return size of CustomersData. This is the quantity of Customers objects inside CustomersData.
 *  @return number of Customers objects;
 */
int CustomersData::GetSize(){
    return _data.size();
}

/** @brief Function write all data in CustomersData to file.
 *  
 *  Function write all data in CustomersData to file.
 *  @return 1 if success, 0 if fail;
 */
int CustomersData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Customers p:_data){
        outFile << p.ToJson() << endl;
    }
    outFile.close();
    return 1;
}