/** @file SuppliersData.h
 *  @brief SuppliersData stores all Suppliers objects
 *  
 *  @author Van-Minh Le (lvminh2k)
 *  @bug No known bugs.
 */

#include "SuppliersData.h"

using json = nlohmann::json;

SuppliersData::SuppliersData(){
    maxId = 0;
    _data.resize(0);
}

SuppliersData::SuppliersData(string filename){
    maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Suppliers p(
            j["SupplierId"],
            j["SupplierName"],
            j["ContactName"],
            j["Address"],
            j["City"],
            j["PostalCode"],
            j["Country"],
            j["Phone"]
        );
        _data.push_back(p);
    }
    inFile.close();
}
/** @brief Function add a Suppliers object to the end of the list inside SuppliersData.
 *  
 *  Function add a Suppliers object to the end of the list inside SuppliersData.
 *  @return maxId of Suppliers object inside SuppliersData;
 */
int SuppliersData::PushBack(Suppliers p){
    //at first, there nothing, maxId = 0
    
    //assume p.SupplierId = 5, then maxId = 5
    if (maxId < p.SupplierId) maxId = p.SupplierId;

    //add a Suppliers object to SuppliersData
    _data.push_back(p);
    return maxId;
}

/** @brief Function updates a Suppliers object at a position inside the list inside SuppliersData.
 *  
 *  Function updates a Suppliers object at a position inside the list inside SuppliersData.
 *  @return maxId of Suppliers object inside SuppliersData;
 *  if fail, return -1;
 */
int SuppliersData::Update(int i, Suppliers p){
    if (i < 0) return -1;
    if (i >= _data.size()) return -1;
    _data[i] = p;
    //assume p.SupplierId = 5 and maxId = 4, then maxId = 5
    if (maxId < p.SupplierId) maxId = p.SupplierId;
    return maxId;
}

/** @brief Function return a Suppliers object at a position inside the list inside SuppliersData.
 *  
 *  Function return a Suppliers object at a position inside the list inside SuppliersData.
 *  @return Suppliers object;
 *  if fail, return NULL;
 */
Suppliers SuppliersData::Get(int i){
    return _data[i];
}

Suppliers* SuppliersData::GetPointer(int i){
    Suppliers* p = nullptr;
    if (i < 0) return p;
    if (i >= _data.size()) return p;
    p = &_data[i];
    return p;
}

vector<Suppliers>::iterator SuppliersData::GetSupplierById(int SupplierId){
	vector<Suppliers>::iterator it = find_if(_data.begin(),_data.end(), [&](const Suppliers& sl) {
		return sl.SupplierId == SupplierId;
	});
        return it;
}
void SuppliersData::DeleteSupplierById(int SupplierId){
    _data.erase(GetSupplierById(SupplierId));
}

/** @brief Function return size of SuppliersData.
 *  
 *  Function return size of SuppliersData. This is the quantity of Suppliers objects inside SuppliersData.
 *  @return number of Suppliers objects;
 */
int SuppliersData::GetSize(){
    return _data.size();
}

/** @brief Function write all data in SuppliersData to file.
 *  
 *  Function write all data in SuppliersData to file.
 *  @return 1 if success, 0 if fail;
 */
int SuppliersData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Suppliers p:_data){
        outFile << p.ToJson() << endl;
    }
    outFile.close();
    return 1;
}