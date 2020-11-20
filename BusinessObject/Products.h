/*============================================================================*/
/* Project      = LG Demo Project                                             */
/* Module       = Products.h                                                  */
/* SW-VERSION   = 1.0.0                                                       */
/* Date         = 20/11/2020                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/*                                                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provide function prototypes for file Products.cpp and definition of Class  */
/* Products                                                                   */
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

#ifndef PRODUCTS_H
#define PRODUCTS_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* To use data type string */
#include <string>
/* To use json library of the third party nlohmann/json */
#include "../Util/json.hpp"

/* Use alias for nlohmann::json, just is convenience */
using namespace std;
using json = nlohmann::json;

class Products {
public:
    int m_ProductId, m_SupplierId, m_CategoryId;
    double m_Price;
    string m_ProductName, m_Unit;
public:
    Products() = default;
    Products(int productId, string productName, int supplierId,
                int categoryId, string unit, double price);
    string toString();
    json toJson();
};

#endif

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/