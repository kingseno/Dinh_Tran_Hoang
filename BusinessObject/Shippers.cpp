#include "Shippers.h"

Shippers::Shippers(){
}

/** @brief Function initial object with atrribute.
 *  
 *  Function converts this object to string object.
 *  @return a Shippers object;
 *  
 */
Shippers::Shippers(int ShipperID, string ShipperName, string Phone){
    this->ShipperID = ShipperID;
    this->ShipperName = ShipperName;
    this->Phone = Phone;
}

/** @brief Function converts this object to string object.
 *  
 *  Function converts this object to string object.
 *  @return a string object;
 *  Example: 
 */
string Shippers::ToString(){
    string s;
    s += "{";
    s += to_string(ShipperID) + ", ";
    s += ShipperName + ", ";
    s += Phone;
    s += "}";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 * 
 */
json Shippers::ToJson(){
    json j;
    j["ShipperID"] = ShipperID;
    j["ShipperName"] = ShipperName;
    j["Phone"] = Phone;
    return j;
}