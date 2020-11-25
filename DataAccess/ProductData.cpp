/*============================================================================*/
/* Project      = LG Demo Project                                             */
/* Module       = ProductData.cpp                                             */
/* SW-VERSION   = 1.0.0                                                       */
/* Date         = 20/11/2020                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/*                                                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* To add, update, find, delete products in the product list                  */
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

#include "ProductData.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : ProductData
**
** Description           : To load product list from json file
**
** Author                : Dinh Pham
*******************************************************************************/
ProductData::ProductData(string fileName) {
    productList.resize(0);
    const int maxSize = 10000;
    /* Buffer to storage json string of each product */
    char buff[maxSize]; 
    /* Variable to read json file */
    ifstream inFile(fileName);

    /* Loop all line in json file and create object of the corresponding 
    Product */
    while (inFile.getline(buff, maxSize)) {
        json j = json::parse(buff);
        Products p(
            j["productId"],
            j["productName"],
            j["supplierId"],
            j["categoryId"],
            j["unit"],
            j["price"]
        );
        productList.push_back(p);
    }
    inFile.close();
}

/*******************************************************************************
** Function Name         : addProduct
**
** Description           : Add new product to the product list
**
** Author                : Dinh Pham
*******************************************************************************/
void ProductData::addProduct(const Products& newProduct) {
    productList.push_back(newProduct);
    clog << "Added a Product" << endl;
}

/*******************************************************************************
** Function Name         : getProductByOrder
**
** Description           : Get product with its order in the product list
**
** Author                : Dinh Pham
*******************************************************************************/
Products ProductData::getProductByOrder(int order) {
    return productList[order];
}

/*******************************************************************************
** Function Name         : getProductByOrder
**
** Description           : Get product with its ID in the product list
**
** Author                : Dinh Pham
*******************************************************************************/
vector<Products>::iterator ProductData::getProductById(int productId) {
    vector<Products>::iterator product;

    /* Find the product by ID in the product list */
    product = find_if(productList.begin(), productList.end(), 
    [=] (Products& productIdInList) {
        return productId == productIdInList.m_ProductId;
    });

    // if (product != productList.end()) {
    //     clog << "Found a Product" << endl;
    // } else {
    //     clog << "This Product doesn't exist" << endl;
    // }

    return product;
}

/*******************************************************************************
** Function Name         : deleteProductById
**
** Description           : Delete product with its ID in the product list
**
** Author                : Dinh Pham
*******************************************************************************/
void ProductData::deleteProductById(int productId) {
    productList.erase(getProductById(productId));
    clog << "Delete a Product" << endl;
}

void ProductData::updateProduct(int productId, const Products& updateProduct) {
    vector<Products>::iterator product;

    /* Find the product by ID in the product list */
    product = find_if(productList.begin(), productList.end(), 
    [=] (Products& productIdInList) {
        return productId == productIdInList.m_ProductId;
    });

    product->m_ProductId = updateProduct.m_ProductId;
    product->m_ProductName = updateProduct.m_ProductName;
    product->m_SupplierId = updateProduct.m_SupplierId;
    product->m_CategoryId = updateProduct.m_CategoryId;
    product->m_Unit = updateProduct.m_Unit;
    product->m_Price = updateProduct.m_Price;
}
/*******************************************************************************
** Function Name         : getSize
**
** Description           : Get size of the product list
**
** Author                : Dinh Pham
*******************************************************************************/
int ProductData::getSize() {
    return productList.size();
}

/*******************************************************************************
** Function Name         : exportToFile
**
** Description           : Export the product list to json file
**
** Author                : Dinh Pham
*******************************************************************************/
int ProductData::exportToFile(string filename) {
    /* Variable to write to json file */
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;

    /* Loop all product and write to json file at the new line */
    for (Products p : productList) {
        outFile << p.toJson() << endl;
    }
    outFile.close();
    return 1;
}   

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/