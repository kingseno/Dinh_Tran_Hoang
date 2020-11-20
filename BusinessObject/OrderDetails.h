/*============================================================================*/
/* Project      = LG Demo Project                                             */
/* Module       = OrderDetails.h                                              */
/* SW-VERSION   = 1.0.0                                                       */
/* Date         = 20/11/2020                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/*                                                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provide function prototypes for file OrderDetails.cpp and definition of    */
/* Class OrderDetails                                                         */
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

#ifndef ORDER_DETAILS_H
#define ORDER_DETAILS_H

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

class OrderDetails {
public:
    int m_OrderDetailId, m_OrderId, m_ProductId, m_Quantity;
public:
    OrderDetails() = default;
    OrderDetails(int orderDetailId, int orderId, int productId, int quantity);
    string toString();
    json toJson();
};

#endif

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/