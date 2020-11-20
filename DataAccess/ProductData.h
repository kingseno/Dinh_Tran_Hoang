/*============================================================================*/
/* Project      = LG Demo Project                                             */
/* Module       = ProductData.h                                               */
/* SW-VERSION   = 1.0.0                                                       */
/* Date         = 20/11/2020                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/*                                                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provide function prototypes for file ProductData.cpp and definition of     */
/* class ProductData                                                          */
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

#ifndef PRODUCT_DATA_H
#define PRODUCT_DATA_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/* To use cin cout */
#include <iostream>
/* To use data type string */
#include <string>
/* To use container vector */
#include <vector>
/* To use utility function */
#include <algorithm>
/* To use ifstream, ofstream */
#include <fstream>
/* To use class Products in this file */
#include "../BusinessObject/Products.h"
/* To use json library of the third party nlohmann/json */
#include "../Util/json.hpp"

/* Use alias for nlohmann::json, just is convenience */
using json = nlohmann::json;
using namespace std;

class ProductData {
private:
    vector<Products> productList;
public:
    ProductData() = default;
    ProductData(string fileName);

    void addProduct(const Products& newProduct);
    Products getProductByOrder(int order);
    vector<Products>::iterator getProductById(int productId);
    void deleteProductById(int productId);
    void updateProduct(int productId, const Products& updateProduct);
    int getSize();
    int exportToFile(string fileName);
};

#endif

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/