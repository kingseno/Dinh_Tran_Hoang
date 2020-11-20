/*============================================================================*/
/* Project      = LG Demo Project                                             */
/* Module       = CategoryData.h                                              */
/* SW-VERSION   = 1.0.0                                                       */
/* Date         = 20/11/2020                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/*                                                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provide function prototypes for file CategoryData.cpp and definition of    */
/* class CategoryData                                                         */
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

#ifndef CATEGORY_DATA_H
#define CATEGORY_DATA_H

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
/* To use class Categories in this file */
#include "../BusinessObject/Categories.h"
/* To use json library of the third party nlohmann/json */
#include "../Util/json.hpp"

/* Use alias for nlohmann::json, just is convenience */
using json = nlohmann::json;
using namespace std;

class CategoryData {
private:
    vector<Categories> categoryList;
public:
    CategoryData() = default;
    CategoryData(string fileName);

    void addCategory(const Categories& newCategory);
    Categories getCategoryByOrder(int order);
    vector<Categories>::iterator getCategoryById(int categoryId);
    void deleteCategoryById(int categoryId);
    void updateCategory(int categoryId, const Categories& updateCategory);
    int getSize();
    int exportToFile(string fileName);
};

#endif

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/