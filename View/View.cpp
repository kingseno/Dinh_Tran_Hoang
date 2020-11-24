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
** Function Name         : loadMainScreen
**
** Description           : To load the main screen when start up application
**
** Author                : Dinh Pham
*******************************************************************************/
void loadMainScreen() {
    int idx1 = 0;

    cout << endl << "Started application" << endl;
    cout << endl << "Please choose what you want:" << endl << endl;
    cout << "1. Import Management" << endl;
    cout << "2. Export Management" << endl;
    cout << "3. Stock Management" << endl;
    cout << "4. Category Management" << endl;

    do {
        cout << endl << "You choose: ";
        cin >> idx1;
    } while (idx1 < 1 || idx1 > 4);
    

    switch(idx1) {
        case 1: loadImport();
                break;
        case 2: loadExport();
                break;
        case 3: loadStock();
                break;
        case 4: loadCategory();
                break;
        default: cout << "Never have this case";
    };
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
        orderDetailData.exportToFile("./DataBase/OrderDetails.json");
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
** Function Name         : loadMainScreen
**
** Description           : To load the main screen when start up application
**4
** Author                : Dinh Pham
*******************************************************************************/
void loadExport() {
    
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
void loadCategory() {

}

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/