#include "BackupRestore.h"
void Backup()
{
    CategoryData p1("../DataBase/Categories.json");
    CustomersData p2("../DataBase/Customers.json");
    EmployeesData p3("../DataBase/Employees.json");
    OrderDetailData p4("../DataBase/OrderDetails.json");
    OrdersData p5("../DataBase/Orders.json");
    ProductData p6("../DataBase/Products.json");
    ShippersData p7("../DataBase/Shippers.json");
    SuppliersData p8("../DataBase/Suppliers.json");
    
    char nameFolder[100];
    char tp[] = "../DataBase/";
    string folder;
    int stat;
    cout << "BACKUP: Input Forder Name: ";
    cin.ignore();
    cin.getline(nameFolder,100);
    
    strcat(tp, nameFolder);
    stat = mkdir(tp);
    if (!stat){
        folder = string(tp);
        p1.exportToFile(folder + "/Categories.json");
        p2.ExportToFile(folder + "/Customers.json");
        p3.ExportToFile(folder + "/Employees.json");
        p4.exportToFile(folder + "/OrderDetails.json");
        p5.ExportToFile(folder + "/Orders.json");
        p6.exportToFile(folder + "/Products.json");
        p7.ExportToFile(folder + "/Shippers.json");
        p8.ExportToFile(folder + "/Suppliers.json");
        cout << "Done!" << endl;
    }
    else
    {
        cout << "Folder already exists. Please re-input." << endl;
        Backup();
    }

    
    
}
void Restore(){
    string nameFolder;
    cout << "RESTORE: Input Forder Name: ";
    cin.ignore();
    getline(cin, nameFolder);
    CategoryData r1("../DataBase/" + nameFolder + "/Categories.json");
    CustomersData r2("../DataBase/" + nameFolder + "/Customers.json");
    EmployeesData r3("../DataBase/" + nameFolder + "/Employees.json");
    OrderDetailData r4("../DataBase/" + nameFolder + "/OrderDetails.json");
    OrdersData r5("../DataBase/" + nameFolder + "/Orders.json");
    ProductData r6("../DataBase/" + nameFolder + "/Products.json");
    ShippersData r7("../DataBase/" + nameFolder + "/Shippers.json");
    SuppliersData r8("../DataBase/" + nameFolder + "/Suppliers.json");
    
    r1.exportToFile("../DataBase/Categories.json");
    r2.ExportToFile("../DataBase/Customers.json");
    r3.ExportToFile("../DataBase/Employees.json");
    r4.exportToFile("../DataBase/OrderDetails.json");
    r5.ExportToFile("../DataBase/Orders.json");
    r6.exportToFile("../DataBase/Products.json");
    r7.ExportToFile("../DataBase/Shippers.json");
    r8.ExportToFile("../DataBase/Suppliers.json");
    cout << "Done!" << endl;
    
}
