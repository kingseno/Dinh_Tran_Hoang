/*============================================================================*/
/* Project      = LG Demo Project                                             */
/* Module       = View.h                                                      */
/* SW-VERSION   = 1.0.0                                                       */
/* Date         = 20/11/2020                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/*                                                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provide function prototypes for file View.cpp and definition of            */
/* class View                                                                 */
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

#ifndef VIEW_H
#define VIEW_H

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
/*To use random*/
#include <stdlib.h>
#include <time.h>
/*To use gotoXY*/
#include <windows.h>
/* To use class Products in this file */
#include "../DataAccess/ProductData.h"
#include "../BusinessObject/Products.h"
#include "../BusinessObject/Orders.h"
#include "../DataAccess/OrdersData.h"
#include "../BusinessObject/OrderDetails.h"
#include "../DataAccess/OrderDetailData.h"
#include "../BusinessObject/Customers.h"
#include "../DataAccess/CustomersData.h"
#include "../BusinessObject/Suppliers.h"
#include "../DataAccess/SuppliersData.h"
#include "StockManagement.h"

using namespace std;

void loadMainScreen();
void loadImport();
void loadExport();
void loadStock();
void loadCategory();
void gotoXY(int, int);

#endif

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/