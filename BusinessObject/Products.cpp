/*============================================================================*/
/* Project      = LG Demo Project                                             */
/* Module       = Products.cpp                                                */
/* SW-VERSION   = 1.0.0                                                       */
/* Date         = 20/11/2020                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/*                                                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* Class to create objects which storage data of Products                     */
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

#include "Products.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : Products
**
** Description           : This is constructor function to create a new object
**
** Author                : Dinh Pham
*******************************************************************************/
Products::Products(int productId, string productName, int supplierId,
 int categoryId, string unit, double price) {
    m_ProductId = productId;
    m_ProductName = productName;
    m_SupplierId = supplierId;
    m_CategoryId = categoryId;
    m_Unit = unit;
    m_Price = price;
}

/*******************************************************************************
** Function Name         : toString
**
** Description           : Convert a product object into a string
**
** Author                : Dinh Pham
*******************************************************************************/
string Products::toString(){
    string s;
    s += "{";
    s += to_string(m_ProductId) + ", ";
    s += m_ProductName + ", ";
    s += to_string(m_SupplierId) + ", ";
    s += to_string(m_CategoryId) + ", ";
    s += m_Unit + ", ";
    s += to_string(m_Price);
    s += "}";
    return s;
}

/*******************************************************************************
** Function Name         : toJson
**
** Description           : Convert a product object into a json object
**
** Author                : Dinh Pham
*******************************************************************************/
json Products::toJson(){
    json j;
    j["productId"] = m_ProductId;
    j["supplierId"] = m_SupplierId;
    j["categoryId"] = m_CategoryId;
    j["price"] = m_Price;
    j["productName"] = m_ProductName;
    j["unit"] = m_Unit;
    return j;
}

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/