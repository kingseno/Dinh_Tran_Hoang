#include "Employees.h"

Employees::Employees(){
}
Employees::Employees(int EmployeeID, string LastName, string FirstName, string BirthDate, string Photo, string Notes){
    this->EmployeeID = EmployeeID;
    this->LastName = LastName;
    this->FirstName = FirstName;
    this->BirthDate = BirthDate;
    this->Photo = Photo;
    this->Notes = Notes;
}

/** @brief Function initial object with atrribute.
 *  
 *  Function converts this object to string object.
 *  @return a Employees object;
 *  
 */
string Employees::ToString(){
    string s;
    s += "{";
    s += to_string(EmployeeID) + ", ";
    s += LastName + ", ";
    s += FirstName + ", ";
    s += BirthDate + ", ";
    s += Photo + ", ";
    s += Notes;
    s += "}";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: Employees e1(1, "Davolio", "Nancy", "1968-12-08", "EmpID1.pic", "Education includes a BA in psychology from Colorado State University. She also completed (The Art of the Cold Call). Nancy is a member of 'Toastmasters International'.");
 *  -> {"BirthDate":"1968-12-08","EmployeeID":1,"FirstName":"Nancy","LastName":"Davolio","Notes":"Education includes a BA in psychology from Colorado State University. She also completed (The Art of the Cold Call). Nancy is a member of 'Toastmasters International'.","Photo":"EmpID1.pic"}
 */
json Employees::ToJson(){
    json j;
    j["EmployeeID"] = EmployeeID;
    j["LastName"] = LastName;
    j["FirstName"] = FirstName;
    j["BirthDate"] = BirthDate;
    j["Photo"] = Photo;
    j["Notes"] = Notes;
    return j;
}