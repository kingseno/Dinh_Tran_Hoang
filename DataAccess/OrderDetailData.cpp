/*============================================================================*/
/* Project      = LG Demo Project                                             */
/* Module       = OrderDetailData.cpp                                         */
/* SW-VERSION   = 1.0.0                                                       */
/* Date         = 20/11/2020                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/*                                                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* To add, update, find, delete orderDetailData in the orderDetailData list   */
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

#include "OrderDetailData.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : OrderDetailData
**
** Description           : To load orderDetailData list from json file
**
** Author                : Dinh Pham
*******************************************************************************/
OrderDetailData::OrderDetailData(string fileName) {
    orderDetailList.resize(0);
    const int maxSize = 10000;
    /* Buffer to storage json string of each orderDetailData */
    char buff[maxSize]; 
    /* Variable to read json file */
    ifstream inFile(fileName);

    /* Loop all line in json file and create object of the corresponding 
    OrderDetail */
    while (inFile.getline(buff, maxSize)) {
        json j = json::parse(buff);
        OrderDetails p(
            j["orderDetailId"],
            j["orderId"],
            j["productId"],
            j["quantity"]
        );
        orderDetailList.push_back(p);
    }
    inFile.close();
}

/*******************************************************************************
** Function Name         : addOrderDetail
**
** Description           : Add new orderDetailData to the orderDetailData list
**
** Author                : Dinh Pham
*******************************************************************************/
void OrderDetailData::addOrderDetail(const OrderDetails& newOrderDetail) {
    orderDetailList.push_back(newOrderDetail);
    clog << "Added a OrderDetail" << endl;
}

/*******************************************************************************
** Function Name         : getOrderDetailByOrder
**
** Description           : Get orderDetailData with its order in the orderDetailData list
**
** Author                : Dinh Pham
*******************************************************************************/
OrderDetails OrderDetailData::getOrderDetailByOrder(int order) {
    return orderDetailList[order];
}

/*******************************************************************************
** Function Name         : getOrderDetailByOrder
**
** Description           : Get orderDetailData with its ID in the orderDetailData list
**
** Author                : Dinh Pham
*******************************************************************************/
vector<OrderDetails>::iterator OrderDetailData::getOrderDetailById(int orderDetailDataId) {
    vector<OrderDetails>::iterator orderDetailData;

    /* Find the orderDetailData by ID in the orderDetailData list */
    orderDetailData = find_if(orderDetailList.begin(), orderDetailList.end(), 
    [=] (OrderDetails& orderDetailDataIdInList) {
        return orderDetailDataId == orderDetailDataIdInList.m_OrderDetailId;
    });

    if (orderDetailData != orderDetailList.end()) {
        clog << "Found a OrderDetail" << endl;
    } else {
        clog << "This OrderDetail doesn't exist" << endl;
    }

    return orderDetailData;
}

/*******************************************************************************
** Function Name         : deleteOrderDetailById
**
** Description           : Delete orderDetailData with its ID in the orderDetailData list
**
** Author                : Dinh Pham
*******************************************************************************/
void OrderDetailData::deleteOrderDetailById(int orderDetailDataId) {
    orderDetailList.erase(getOrderDetailById(orderDetailDataId));
    clog << "Delete a OrderDetail" << endl;
}

void OrderDetailData::updateOrderDetail(int orderDetailDataId, const OrderDetails& updateOrderDetail) {
    vector<OrderDetails>::iterator orderDetailData;

    /* Find the orderDetailData by ID in the orderDetailData list */
    orderDetailData = find_if(orderDetailList.begin(), orderDetailList.end(), 
    [=] (OrderDetails& orderDetailDataIdInList) {
        return orderDetailDataId == orderDetailDataIdInList.m_OrderDetailId;
    });

    orderDetailData->m_OrderDetailId = updateOrderDetail.m_OrderDetailId;
    orderDetailData->m_OrderId = updateOrderDetail.m_OrderId;
    orderDetailData->m_ProductId = updateOrderDetail.m_ProductId;
    orderDetailData->m_Quantity = updateOrderDetail.m_Quantity;
}
/*******************************************************************************
** Function Name         : getSize
**
** Description           : Get size of the orderDetailData list
**
** Author                : Dinh Pham
*******************************************************************************/
int OrderDetailData::getSize() {
    return orderDetailList.size();
}

/*******************************************************************************
** Function Name         : exportToFile
**
** Description           : Export the orderDetailData list to json file
**
** Author                : Dinh Pham
*******************************************************************************/
int OrderDetailData::exportToFile(string filename) {
    /* Variable to write to json file */
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;

    /* Loop all orderDetailData and write to json file at the new line */
    for (OrderDetails p : orderDetailList) {
        outFile << p.toJson() << endl;
    }
    outFile.close();
    return 1;
}   

/*******************************************************************************
** Function Name         : exportToFile
**
** Description           : Import Product with OrderDetailId
**
** Author                : Dinh Pham
*******************************************************************************/
void OrderDetailData::importProductByOrderId(int orderDetailId) {
    vector<OrderDetails>::iterator orderDetailData;

    /* Find the orderDetailData by ID in the orderDetailData list */
    orderDetailData = find_if(orderDetailList.begin(), orderDetailList.end(), 
    [=] (OrderDetails& orderDetailDataIdInList) {
        return orderDetailId == orderDetailDataIdInList.m_OrderDetailId;
    });

    orderDetailData->m_Quantity += orderDetailData->m_Quantity;

    clog << "Imported Product with the Order:" << endl;
    clog << "Order Detail ID: " << orderDetailData->m_OrderDetailId << endl;
    clog << "Order ID: " << orderDetailData->m_OrderId << endl;
    clog << "Product ID: " << orderDetailData->m_ProductId << endl;
    clog << "Quantity: " << orderDetailData->m_Quantity << endl;
}

/*******************************************************************************
** Function Name         : exportToFile
**
** Description           : print information of product when finding with 
**                         orderDetailId
**
** Author                : Dinh Pham
*******************************************************************************/
void OrderDetailData::printOrderDetail(int orderDetailId) {
    vector<OrderDetails>::iterator orderDetailData =
    getOrderDetailById(orderDetailId);

    clog << "Order Detail ID: " << orderDetailData->m_OrderDetailId << endl;
    clog << "Order ID: " << orderDetailData->m_OrderId << endl;
    clog << "Product ID: " << orderDetailData->m_ProductId << endl;
    clog << "Quantity: " << orderDetailData->m_Quantity << endl;
}
/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/