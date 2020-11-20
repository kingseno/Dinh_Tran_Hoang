/*============================================================================*/
/* Project      = LG Demo Project                                             */
/* Module       = Categories.h                                                */
/* SW-VERSION   = 1.0.0                                                       */
/* Date         = 20/11/2020                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/*                                                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provide function prototypes for file Categories.cpp and definition of      */
/* Class Categories                                                           */
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

#ifndef CATEGORIES_H
#define CATEGORIES_H

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

class Categories {
public:
    int m_CategoryId;
    string m_CategoryName, m_Description;
public:
    Categories() = default;
    Categories(int categoryId, string categoryName, string description);
    string toString();
    json toJson();
};

#endif

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/