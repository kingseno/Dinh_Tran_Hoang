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
extern ProductData productData;
extern OrderDetailData orderDetailData;
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
    while(idx1 != 5)
    {

    cout << endl << "Started application" << endl;
    cout << endl << "Please choose what you want:" << endl << endl;
    cout << "1. Import Management" << endl;
    cout << "2. Export Management" << endl;
    cout << "3. Stock Management" << endl;
    cout << "4. Category Management" << endl;
    cout << "5. Exit" << endl;

    do {
        cout << endl << "You choose: ";
        cin >> idx1;
    } while (idx1 < 1 || idx1 > 5);
    

    switch(idx1) {
        case 1: loadImport();
                break;
        case 2: loadExport();
                break;
        case 3: loadStock();
                break;
        case 4: loadCategory();
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
    int orderDetailId;

    int idx11;

    cout << "1. Import Product by Order Detail ID" << endl;
    cout << "2: Find Product" << endl;
    cout << "You choose: ";
    cin >> idx11;

    if (idx11 == 1) {
        cout << "Please type Order Detail ID" << endl;
        cout << "Typing: ";
        cin >> orderDetailId;
        orderDetailData.importProductByOrderId(orderDetailId);
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
    cout << "**************************************************************\n";
    cout << "*                 1. Take New Product Order                  *\n";
    cout << "*                 2. Display List of Order                   *\n";
    cout << "*                 3. Go to Main Screen                       *\n";
    cout << "**************************************************************\n";

    //Type the choice
    int choice = 0;
    do
    {
        cout << "Please Enter choice: ";
        cin >> choice;
    } while (choice > 3 || choice < 1);
    switch (choice)
    {
    case 1:
    {
        /*Insert new order*/
        cout << "You choice New Product Order\n"
             << endl;
        cout << "--------------------------------------------------------------\n";
        int orderdetail_id, order_id, product_id, quantity;
        int customer_id, employee_id, shipper_id;
        string order_date;
        cout << "Enter ProductID (ProductId is in range 1 - 77): ";
        cin >> product_id;
        cin.sync();
        cout << "Enter CustomerID (CustomerId is in range 1 - 91):  ";
        cin >> customer_id;
        cin.sync();
        cout << "Enter Date (format yyyy-mm-dd): ";
        cin >> order_date;
        cin.sync();
        cout << "How many Product would you like to order: ";
        cin >> quantity;
        cin.sync();

        //Confirm to save data
        char savedata = {0};
        cout << "Are you want to save this choice!!\n";
        cout << "(Please choice y: yes or n: no)\n";
        cin >> savedata;
        if (savedata == 'y')
        {
            //Save to Orders.json file
            OrdersData order_data("../DataBase/Orders.json");
            order_id = 10248 + order_data.GetSize();

            //random employee_id and shipper_id
            srand(time(0));
            employee_id = 1 + rand() % 10;
            srand(time(0));
            shipper_id = 1 + rand() % 3;
            Orders order(order_id, customer_id, employee_id, order_date, shipper_id);
            order_data.PushBack(order);
            order_data.ExportToFile("../DataBase/Orders.json");

            //Save to OrderDetail.json file
            OrderDetailData order_detail_data("../DataBase/OrderDetails.json");
            orderdetail_id = order_detail_data.getSize() + 1;
            if (quantity > 0)
                quantity = -quantity;
            OrderDetails order_detail(orderdetail_id, order_id, product_id, quantity);
            order_detail_data.addOrderDetail(order_detail);
            order_detail_data.exportToFile("../DataBase/OrderDetails.json");

            //Display the receipt

            //Product id convert to product name
            ProductData product_data("../DataBase/Products.json");
            vector<Products>::iterator p = product_data.getProductById(product_id);
            //Customer id convert to customer name
            CustomersData customer_data("../DataBase/Customers.json");
            Customers cus = customer_data.Get(customer_id);

            cout << "**************************************************************\n";
            cout << "*                 DISPLAY THE RECEIPT EXPORT                 *\n";
            cout << "*                                                            *\n";
            cout << "**************************************************************\n";
            cout << "Customer Name: " << cus.ContactName << endl;
            cout << "Product Name: " << p[0].m_ProductName << endl;
            cout << "Quantity: " << -quantity << endl;
            cout << "Order Date: " << order_date << endl;
            cout << "**************************************************************\n";
        }
        break;
    }

    case 2:
    {
        break;
    }
    case 3:
    {
        break;
    }
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
    cout << "*         4. Display List of Suppliers                   *\n";
    cout << "*         5. Update List of Category                     *\n";
    cout << "*         6. Add New Category                            *\n";
    cout << "*         7. Delete Category at Id                       *\n";
    cout << "*         8. Display List of Category                    *\n";
    cout << "*         9. Go to Main Screen                           *\n";
    cout << "**********************************************************\n";

    int choice = 0;
    do
    {
        cout << "Please Enter choice: ";
        cin >> choice;
    } while (choice > 8 || choice < 1);

    switch (choice)
    {
    case 1:
    {
        int supplierid;
        string suppliername, contactname, address, city, postalcode, country, phone;
        SuppliersData supplydata("../DataBase/Suppliers.json");
        cout << "You choice Update List of Suppliers \n";

        //Check the Id can found
        do
        {
            cout << "Type Suppliers ID (Suppliers ID is in range 1 - " << supplydata.GetSize() << " )";
            cin >> supplierid;
        } while (supplierid > supplydata.GetSize());
        cin.sync(); //delete buffer memory
        cout << "Type Supplier Name: ";getline(cin, suppliername);cin.sync();
        cout << "Type Contact Name: ";getline(cin, contactname);cin.sync();
        cout << "Type Address: ";getline(cin, address);cin.sync();
        cout << "Type City: ";getline(cin, city);cin.sync();
        cout << "Type PostalCode: ";getline(cin, postalcode);cin.sync();
        cout << "Type Country: ";getline(cin, country); cin.sync();
        cout << "Type Phone: ";getline(cin, phone);cin.sync();

        Suppliers su(supplierid, suppliername, contactname, address, city, postalcode, country, phone);
        supplydata.Update(supplierid - 1, su);
        if (supplydata.ExportToFile("../DataBase/Suppliers.json") == 1)
        {
            cout << "Update Suseccfull\n";
        }
        else
        {
            cout << "Fail\n";
        }
        break;
    }
    case 2:
    {
        int supplierid;
        string suppliername, contactname, address, city, postalcode, country, phone;
        SuppliersData supplydata("../DataBase/Suppliers.json");
        cout << "You choice Add New Suppliers \n";
        supplierid = supplydata.GetSize() + 1;
        cin.sync();
        cout << "Type Supplier Name: ";
        getline(cin, suppliername);
        cin.sync();
        cout << "Type Contact Name: ";
        getline(cin, contactname);
        cin.sync();
        cout << "Type Address: ";
        getline(cin, address);
        cin.sync();
        cout << "Type City: ";
        getline(cin, city);
        cin.sync();
        cout << "Type PostalCode: ";
        getline(cin, postalcode);
        cin.sync();
        cout << "Type Country: ";
        getline(cin, country);
        cin.sync();
        cout << "Type Phone: ";
        getline(cin, phone);
        cin.sync();

        Suppliers su(supplierid, suppliername, contactname, address, city, postalcode, country, phone);
        supplydata.PushBack(su);
        if (supplydata.ExportToFile("../DataBase/Suppliers.json") == 1)
        {
            cout << "Add Suppliers successfull\n";
        }
        else
        {
            cout << "Fail\n";
        }
        break;
    }
    case 3:
    {
        int supplierid;
        SuppliersData supplydata("../DataBase/Suppliers.json");
        cout << "You choice Delete Suppliers by Id \n";
        do
        {
            cout << "Type Suppliers ID which you want to delete: ";
            cin >> supplierid;
            cin.sync();
            if (supplierid > supplydata.GetSize())
                cout << "Not fount Id. Please retype!!!\n";
        } while (supplierid > supplydata.GetSize());

        supplydata.DeleteSupplierById(supplierid);
        if (supplydata.ExportToFile("../DataBase/Suppliers.json") == 1)
        {
            cout << "Delete Suppliers Successfull!!\n";
        }
        else
        {
            cout << "Fail\n";
        }
        break;
    }
    case 4:
    {
        system("cls");
        cout << "You choice Display of Suppliers \n";
        cout << "**************************************************************************************************************\n";
        cout << "*                                            DISPLAY LIST OF SUPPLIERS                                       *\n";
        cout << "**************************************************************************************************************\n\n";
        
        gotoXY(0, 9);cout << "Supplier Id";
        gotoXY(12, 9); cout << "Supplier Name";
        gotoXY(42, 9); cout << "Contact Name";
        gotoXY(77, 9); cout << "Address";
        gotoXY(97, 9); cout << "City";
        gotoXY(107, 9); cout << "Country";
        gotoXY(117, 9); cout << "Phone\n";
        SuppliersData supplydata("../DataBase/Suppliers.json");
        for (int i = 0; i < supplydata.GetSize(); i++)
        {
            Suppliers su = supplydata.Get(i);
            gotoXY(0, i + 10); cout << su.SupplierId << "\t";
            gotoXY(12, i + 10);cout << su.SupplierName << "\t";
            gotoXY(42, i + 10);cout << su.ContactName << "\t";
            gotoXY(77, i + 10);cout << su.Address << "\t";
            gotoXY(97, i + 10);cout << su.City << "\t";
            gotoXY(107, i + 10);cout << su.Country << "\t";
            gotoXY(117, i + 10);cout << su.Phone << "\t\n";
        }
        break;
    }
    case 5:
    {
        break;
    }
    case 6:
    {
        break;
    }
    case 7:
    {
        break;
    }
    case 8:
    {
        cout << "You choice Exit => Go to main screen" << endl;
        //Cho nhin thay
        break;
    }
    }
}
/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/