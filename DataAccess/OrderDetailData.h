/*============================================================================*/
/* Project      = LG Demo Project                                             */
/* Module       = OrderDetailData.h                                           */
/* SW-VERSION   = 1.0.0                                                       */
/* Date         = 20/11/2020                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/*                                                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provide function prototypes for file OrderDetailData.cpp and definition of */
/* class OrderDetailData                                                      */
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

#ifndef ORDER_DETAIL_DATA_H
#define ORDER_DETAIL_DATA_H

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
/* To use class OrderDetails in this file */
#include "../BusinessObject/OrderDetails.h"
/* To use json library of the third party nlohmann/json */
#include "../Util/json.hpp"

/* Use alias for nlohmann::json, just is convenience */
using json = nlohmann::json;
using namespace std;

class OrderDetailData {
private:
    vector<OrderDetails> orderDetailList;
public:
    OrderDetailData() = default;
    OrderDetailData(string fileName);

    void addOrderDetail(const OrderDetails& newOrderDetail);
    OrderDetails getOrderDetailByOrder(int order);
    vector<OrderDetails>::iterator getOrderDetailById(int orderDetailId);
    void deleteOrderDetailById(int orderDetailId);
    void updateOrderDetail(int orderDetailId, const OrderDetails& updateOrderDetail);
    int getSize();
    int exportToFile(string fileName);
};

#endif

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/