/*============================================================================*/
/* Project      = LG Demo Project                                             */
/* Module       = View.cpp                                                    */
/* SW-VERSION   = 1.0.0                                                       */
/* Date         = 20/11/2020                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/*                                                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provide API for console screen of this application                         */
/*                                                                            */
/*============================================================================*/
/* Limitation of Liability                                                    */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:                                                      */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * 1.0.0:  20/11/2020    : Initial Version
 */
/******************************************************************************/
/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

#include "View.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/*******************************************************************************
** Function Name         : gotoXY
**
** Description           : Move to position of row : x, collum: y
**
** Author                : 
*******************************************************************************/
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY(int x, int y) 
{ 
    CursorPosition.X = x; // Locates column
    CursorPosition.Y = y; // Locates Row
    SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

/*******************************************************************************
** Function Name         : loadMainScreen
**
** Description           : To load the main screen when start up application
**
** Author                : Dinh Pham
*******************************************************************************/
void loadMainScreen() {
    int idx1 = 1;
    while(idx1 != 6)
    {

    cout << endl << "Started application" << endl;
    cout << endl << "Please choose what you want:" << endl << endl;
    cout << "1. Import Management" << endl;
    cout << "2. Export Management" << endl;
    cout << "3. Stock Management" << endl;
    cout << "4. Category Management" << endl;
    cout << "5. Backup and Restore" << endl;
    cout << "6. Exit" << endl;

    do {
        cout << endl << "You choose: ";
        cin >> idx1;
    } while (idx1 < 1 || idx1 > 6);
    

    switch(idx1) {
        case 1: loadImport();
                break;
        case 2: loadExport();
                break;
        case 3: loadStock();
                break;
        case 4: loadCategory();
                break;
        case 5: loadBackupRestore();
                break;    
    };
    }
}

/*******************************************************************************
** Function Name         : loadMainScreen
**
** Description           : To load the main screen when start up application
**
** Author                : Dinh Pham
*******************************************************************************/
void loadImport() {
    OrdersData ordersData("../DataBase/Orders.json");
    OrderDetailData orderDetailData("../DataBase/OrderDetails.json");
    CustomersData customerData("../DataBase/Customers.json");
    EmployeesData employeeData("../DataBase/Employees.json");
    ShippersData shipperData("../DataBase/Shippers.json");
    ProductData productData("../DataBase/Products.json");

    int customerId, employeeId, shipperId, productId, quantity;
    string orderDate;
    
    int idx11;
    char idx112;

    cout << "1. Import Product by Import Order" << endl;
    cout << "2: Find Product" << endl;
    cout << "You choose: ";
    cin >> idx11;

    if (idx11 == 1) {
        /* Enter Import Product by Import Order */
        cout << "Please type Customer ID(1 to 91): ";
        cin >> customerId;
        /* Show customer name for staff can verify information */
        vector<Customers>::iterator customer = customerData.GetCustomerById(customerId);
        cout << "Customer name: " + customer->CustomerName << endl;

        cout << "Please type Employee ID(1 to 10): ";
        cin >> employeeId;
        /* Show employee name for staff can verify information */
        Employees* employee = employeeData.GetPointer(employeeId);
        cout << "Employee name: " + employee->FirstName << endl;

        cout << "Please type Order Date(yyyy-mm-dd): ";
        cin >> orderDate;
        cout << "Please type Shipper ID(1 to 3): ";
        cin >> shipperId;
        /* Show shipper name for staff can verify information */
        Shippers* shipper = shipperData.GetPointer(shipperId);
        cout << "Shipper name: " + shipper->ShipperName << endl;

        /* Push new order into database */
        Orders order(ordersData.GetSize() + 10248, customerId, employeeId, orderDate, shipperId);
        ordersData.PushBack(order);
        ordersData.ExportToFile("../DataBase/Orders.json");

        cout << endl << "Type Order Detail ID for Order ID " +  to_string(ordersData.GetSize() + 10248 - 1) << endl;

        do {
            cout << "Please type Product ID(1 to 77): ";
            cin >> productId;
            /* Show product name for staff can verify information */
            vector<Products>::iterator product = productData.getProductById(productId);
            cout << "Product name: " + product->m_ProductName << endl;

            cout << "Please type Quantity: ";
            cin >> quantity;
            
            /* Push new order detail into database */
            OrderDetails orderDetail(orderDetailData.getSize() + 1, 
            ordersData.GetSize() + 10248 - 1,
            productId, quantity);

            orderDetailData.addOrderDetail(orderDetail);
            cout << "Continue typing ? Y(yes)/N(no): ";
            cin >> idx112;
            
        } while (idx112 == 'Y' || idx112 == 'y');
        orderDetailData.exportToFile("../DataBase/OrderDetails.json");

    } else if (idx11 == 2) {
        cout << "1. Find Product by Order Detail ID" << endl;
        cout << "2. Find Product by Product ID" << endl;
        cout << "3. Find Product by Supplier ID" << endl;
        cout << "4. Find Product by Price" << endl;
        cout << "You choose: ";

        int idx12;
        cin >> idx12;
        if (idx12 == 1) {
            cout << "Please type Order Detail ID" << endl;
            cout << "Typing: ";
            int orderDetailId;
            cin >> orderDetailId;
            orderDetailData.printOrderDetail(orderDetailId);
        } 
    }
    
}

/*******************************************************************************
** Function Name         : loadExport
**
** Description           : Manager the export information
**4
** Author                : Bao Tran
*******************************************************************************/
void loadExport()
{
    system("cls");
    cout << "**************************************************************\n";
    cout << "*                         LOAD EXPORT                        *\n";
    cout << "**************************************************************\n\n";

    /*Insert new order*/
    int orderdetail_id, order_id, product_id, quantity;
    int customer_id, employee_id, shipper_id;
    string order_date;
    string customer_name, contact_name, address, city, postal_code, country;

    ProductData product_data("../DataBase/Products.json");
    CustomersData customer_data("../DataBase/Customers.json");
    ShippersData shipper_data("../DataBase/Shippers.json");
    EmployeesData employee_data("../DataBase/Employees.json");
    OrderDetailData order_detail_data("../DataBase/OrderDetails.json");
    OrdersData order_data("../DataBase/Orders.json");

    cout << "*****************You choice New Product Order*****************\n";
    cout << "--------------------------------------------------------------\n";

    char newcustomer = {0};
    cout << "This is New Customer (Press y: new customer, n: old customer)\n";
    cin >> newcustomer; cin.sync();
    if (newcustomer == 'n'){
        /*This is old customer*/

        //Type Customer Id
        cout << "Enter CustomerID (CustomerId is in range 1 - " << customer_data.GetSize() << "): ";
        cin >> customer_id;
        cin.sync();
        //Display Customer Id convert to customer name
        Customers cus = customer_data.Get(customer_id - 1);
        cout << "Customer Name: " << cus.CustomerName << endl;
    }else if (newcustomer == 'y'){
        /*This is New Customer and Save information about new customer*/

        customer_id = customer_data.GetSize() + 1;
        cout << "Enter Customer Name: ";getline(cin, customer_name); cin.sync();
        cout << "Enter Contact Name: ";getline(cin, contact_name); cin.sync();
        cout << "Enter Address: ";getline(cin, address); cin.sync();
        cout << "Enter City: ";getline(cin, city); cin.sync();
        cout << "Enter PostalCode: ";getline(cin, postal_code); cin.sync();
        cout << "Enter Country: ";getline(cin, country); cin.sync();

        Customers cus(customer_id, customer_name, contact_name, address, city, postal_code, country);
        customer_data.PushBack(cus);
        if (customer_data.ExportToFile("../DataBase/Customers.json")){
            cout << "Save information success\n";
        }else{
            cout << "Falt!!!\n";
        }
    }

    //Date Order
    cout << "Enter Date (format yyyy-mm-dd): ";
    cin >> order_date;
    cin.sync();

    //Shipper Id
    cout << "Enter ShipperId (CustomerId is in range 1 - " << shipper_data.GetSize() << "): ";
    cin >> shipper_id;
    cin.sync();
    //Display Shipper id convert to Shipper name
    Shippers sh = shipper_data.Get(shipper_id - 1);
    cout << "Shipper Name: " << sh.ShipperName << endl;

    //Employee Id
    cout << "Enter EmployeeId (EmployeeId is in range 1 - " << employee_data.GetSize() << "): ";
    cin >> employee_id;
    cin.sync();
    //Display employeeid convert to employee name
    Employees em = employee_data.Get(employee_id - 1);
    cout << "Employee Name: " << em.FirstName << endl;

    //Add new value in to object order
    order_id = 10248 + order_data.GetSize();
    Orders order(order_id, customer_id, employee_id, order_date, shipper_id);
    order_data.PushBack(order);

    //Number of product customer want to buy
    cout << "How many type of product ?\n";
    int number_product = 0;
    cin >> number_product;
    for (int i = 0; i < number_product; i++)
    {
        cout << "Enter ProductID (ProductId is in range 1 - " << product_data.getSize() << "): ";
        cin >> product_id;
        cin.sync();
        vector<Products>::iterator p = product_data.getProductById(product_id);
        cout << "Product Name: " << p[0].m_ProductName << endl;

        cout << "Quantity of this product ? ";
        cin >> quantity;
        cin.sync();

        orderdetail_id = order_detail_data.getSize() + 1;
        if (quantity > 0) quantity = -quantity;
        OrderDetails order_detail(orderdetail_id, order_id, product_id, quantity);
        order_detail_data.addOrderDetail(order_detail);
    }
    //Confirm to save data
    char savedata = {0};
    cout << "Are you want to save this choice!!\n";
    cout << "(Please choice y: yes or n: no)\n";
    cin >> savedata;
    if (savedata == 'y')
    {
        //Save data to file
        order_detail_data.exportToFile("../DataBase/OrderDetails.json");
        order_data.ExportToFile("../DataBase/Orders.json");
    }
}

/*******************************************************************************
** Function Name         : loadMainScreen
**
** Description           : To load the main screen when start up application
**
** Author                : Dinh Pham
*******************************************************************************/
void loadStock() {
    StockManagement stockManagement;
    stockManagement.Display();
}


/*******************************************************************************
** Function Name         : loadMainScreen
**
** Description           : To load the main screen when start up application
**
** Author                : Dinh Pham
*******************************************************************************/
/*******************************************************************************
** Function Name         : loadCategory
**
** Description           : Manager the Category information
**
** Author                : Bao Tran
*******************************************************************************/
void loadCategory()
{
    system("cls");
    cout << "**********************************************************\n\n";
    cout << "*              Category Management                       *\n";
    cout << "**********************************************************\n\n";
    cout << "**********************************************************\n";
    cout << "*         1. Update List of Suppliers                    *\n";
    cout << "*         2. Add New Suppliers                           *\n";
    cout << "*         3. Delete Suppliers by Id                      *\n";
    cout << "*         4. Update List of Category                     *\n";
    cout << "*         5. Add New Category                            *\n";
    cout << "*         6. Delete Category at Id                       *\n";
    cout << "*         7. Display List of Suppliers                   *\n";
    cout << "*         8. Display List of Category                    *\n";
    cout << "**********************************************************\n";

    int choice = 0;
    do
    {
        cout << "Please Enter choice: ";
        cin >> choice;
    } while (choice > 13 || choice < 1);

    switch (choice)
    {
    case 1:
    {
        /*Update list of Suppliers*/
        int supplierid;
        string suppliername, contactname, address, city, postalcode, country, phone;
        SuppliersData supplydata("../DataBase/Suppliers.json");
        cout << "You choice Update List of Suppliers \n";

        //Check the Id can found
        do
        {
            cout << "Type Suppliers ID (Suppliers ID is in range 1 - " << supplydata.GetSize() << ")";
            cin >> supplierid;
        } while (supplierid > supplydata.GetSize());
        //delete buffer memory
        cin.sync(); 
        cout << "Type Supplier Name: ";getline(cin, suppliername);cin.sync();
        cout << "Type Contact Name: ";getline(cin, contactname);cin.sync();
        cout << "Type Address: ";getline(cin, address);cin.sync();
        cout << "Type City: ";getline(cin, city);cin.sync();
        cout << "Type PostalCode: ";getline(cin, postalcode);cin.sync();
        cout << "Type Country: ";getline(cin, country);cin.sync();
        cout << "Type Phone: ";getline(cin, phone); cin.sync();

        Suppliers su(supplierid, suppliername, contactname, address, city, postalcode, country, phone);
        supplydata.Update(supplierid - 1, su);
        if (supplydata.ExportToFile("../DataBase/Suppliers.json") == 1)
        {
            cout << "Update Suseccfull\n";
        }else{
            cout << "Fail\n";
        }
        break;
    }
    case 2:
    {
        /*Add New Suppliers*/
        int supplierid;
        string suppliername, contactname, address, city, postalcode, country, phone;
        SuppliersData supplydata("../DataBase/Suppliers.json");
        cout << "You choice Add New Suppliers \n";
        supplierid = supplydata.GetSize() + 1;
        cin.sync();
        cout << "Type Supplier Name: ";getline(cin, suppliername);cin.sync();
        cout << "Type Contact Name: ";getline(cin, contactname);cin.sync();
        cout << "Type Address: ";getline(cin, address);cin.sync();
        cout << "Type City: ";getline(cin, city);cin.sync();
        cout << "Type PostalCode: ";getline(cin, postalcode);cin.sync();
        cout << "Type Country: ";getline(cin, country);cin.sync();
        cout << "Type Phone: ";getline(cin, phone);cin.sync();

        Suppliers su(supplierid, suppliername, contactname, address, city, postalcode, country, phone);
        supplydata.PushBack(su);
        if (supplydata.ExportToFile("../DataBase/Suppliers.json") == 1){
            cout << "Add Suppliers successfull\n";
        }
        else{
            cout << "Fail\n";
        }
        break;
    }
    case 3:
    {
        /*Delete Suppllier by ID*/
        int supplierid;
        SuppliersData supplydata("../DataBase/Suppliers.json");
        cout << "You choice Delete Suppliers by Id \n";
        do
        {
            cout << "Type Suppliers ID which you want to delete (Suppliers ID is in range 1 - " << supplydata.GetSize() << ")";
            cin >> supplierid;
            cin.sync();
            if (supplierid > supplydata.GetSize())
                cout << "Not fount Id. Please retype!!!\n";
        } while (supplierid > supplydata.GetSize());

        supplydata.DeleteSupplierById(supplierid);
        if (supplydata.ExportToFile("../DataBase/Suppliers.json") == 1){
            cout << "Delete Suppliers Successfull!!\n";
        }
        else{
            cout << "Fail\n";
        }
        break;
    }
    case 4:
    {
        /*Update list of categories*/
        cout << "You choice Update List of Suppliers \n";
        int category_id;
        string category_name, description;
        CategoryData category_data("../DataBase/Categories.json");

        //Check the Id can found
        do
        {
            cout << "Type Suppliers ID (Suppliers ID is in range 1 - " << category_data.getSize() << ")";
            cin >> category_id;
        } while (category_id > category_data.getSize());
        cin.sync();
        cout << "Type Category Name: ";getline(cin, category_name);cin.sync();
        cout << "Type Description: ";getline(cin, description);cin.sync();
  
        Categories ca(category_id, category_name, description);
        category_data.updateCategory(category_id, ca);

        if (category_data.exportToFile("../DataBase/Categories.json") == 1)
        {
            cout << "Update Success\n";
        }else{
            cout << "Fail\n";
        }
    }
    break;
    case 5:
    {
        /*Add New Category */
        cout << "You choice Add New Category \n";
        int category_id;
        string category_name, description;
        CategoryData category_data("../DataBase/Categories.json");

        category_id = category_data.getSize() + 1;
        cin.sync();
        cout << "Type Category Name: ";getline(cin, category_name);cin.sync();
        cout << "Type Description: ";getline(cin, description);cin.sync();

        Categories ca(category_id, category_name, description);
        category_data.addCategory(ca);
        if (category_data.exportToFile("../DataBase/Categories.json") == 1){
            cout << "Add Category successfull\n";
        }
        else{
            cout << "Fail\n";
        }
    }
    break;
    case 6:
    {
        /*Delete Category by id*/
        cout << "You choice Add Delete Category \n";
        int category_id;
        string category_name, description;
        CategoryData category_data("../DataBase/Categories.json");
        do
        {
            cout << "Type Category ID which you want to delete (Category ID is in range 1 - " << category_data.getSize() << ")";
            cin >> category_id;
            cin.sync();
            if (category_id > category_data.getSize())
                cout << "Not fount Id. Please retype!!!\n";
        } while (category_id > category_data.getSize());

        category_data.deleteCategoryById(category_id);
        if (category_data.exportToFile("../DataBase/Categories.json")){
            cout << "Delete Category Successfull!!\n";
        }
        else{
            cout << "Fail\n";
        }
    }
    break;
    case 7:
    {
        system("cls");
        cout << "You choice Display of Suppliers \n";
        cout << "**************************************************************************************************************\n";
        cout << "*                                            DISPLAY LIST OF SUPPLIERS                                       *\n";
        cout << "**************************************************************************************************************\n\n";

        gotoXY(0, 7);
        cout << "**************************************************************************************************************\n";
        gotoXY(0, 8);cout << "Supplier Id";
        gotoXY(12, 8);cout << "Supplier Name";
        gotoXY(42, 8);cout << "Contact Name";
        gotoXY(77, 8);cout << "Address";
        gotoXY(97, 8);cout << "City";
        gotoXY(107, 8);cout << "Country";
        gotoXY(117, 8);cout << "Phone\n";
        SuppliersData supplydata("../DataBase/Suppliers.json");
        for (int i = 0; i < supplydata.GetSize(); i++)
        {
            Suppliers su = supplydata.Get(i);
            gotoXY(0, i + 10);cout << su.SupplierId << "\t";
            gotoXY(12, i + 10);cout << su.SupplierName << "\t";
            gotoXY(42, i + 10);cout << su.ContactName << "\t";
            gotoXY(77, i + 10);cout << su.Address << "\t";
            gotoXY(97, i + 10);cout << su.City << "\t";
            gotoXY(107, i + 10);cout << su.Country << "\t";
            gotoXY(117, i + 10);cout << su.Phone << "\t\n";
        }
        
    }
    break;
    case 8:
    {
        system("cls");
        cout << "You choice Display of Category \n";
        cout << "**************************************************************************************************************\n";
        cout << "*                                            DISPLAY LIST OF CATEGORIES                                       *\n";
        cout << "**************************************************************************************************************\n\n";
        gotoXY(0, 7);
        cout << "**************************************************************************************************************\n";
        gotoXY(0, 8);cout << "Category Id";
        gotoXY(20, 8);cout << "Category Name";
        gotoXY(42, 8);cout << "Description\n";
        cout << "**************************************************************************************************************\n";
        CategoryData category_data("../DataBase/Categories.json");
        for (int i = 1; i < category_data.getSize(); i++)
        {
            vector<Categories>::iterator cate = category_data.getCategoryById(i);
            gotoXY(0, i + 10);cout << cate[0].m_CategoryId;
            gotoXY(20, i + 10);cout << cate[0].m_CategoryName;
            gotoXY(42, i + 10);cout << cate[0].m_Description << endl;
        }
    }
    break;
    default:
        cout << "Never have this case";
    }
}


void loadBackupRestore(){
     int id = 1;
    while(id != 3){

        cout << endl << "BACKUP AND RESTORE" << endl;
        cout << endl << "Please choose what you want:" << endl << endl;
        cout << "1. Backup" << endl;
        cout << "2. Restore" << endl;
        cout << "3. Exit" << endl;

        do {
            cout << endl << "You choose: ";
            cin >> id;
        } while (id < 1 || id > 3);

        switch(id) {
            case 1:
                    Backup();
                    system("pause");
                    system("cls");
                    break;
            case 2: 
                    Restore();
                    system("pause");
                    system("cls");
                    break;
                 }
    }
}
/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/