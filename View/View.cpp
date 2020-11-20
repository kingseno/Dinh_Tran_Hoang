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
    cout << "3. Remaining Stock Management" << endl;
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
    int productId, supplierId, categoryId;
    double price;
    string productName, unit;
    cout << "Please type Product ID: ";
    cin >> productId;
    cout << "Please type Product Name: ";
    cin >> productName;
    cout << "Please type Supplier ID: ";
    cin >> supplierId;
    cout << "Please type Category ID: ";
    cin >> categoryId;
    cout << "Please type Unit: ";
    cin >> unit;
    cout << "Please type Price: ";
    cin >> price;

    Products product(productId, productName, supplierId,
                categoryId, unit, price);
    productData.addProduct(product);

    productData.exportToFile("productData.json");
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