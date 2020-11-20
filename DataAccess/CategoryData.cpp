/*============================================================================*/
/* Project      = LG Demo Project                                             */
/* Module       = CategoryData.cpp                                            */
/* SW-VERSION   = 1.0.0                                                       */
/* Date         = 20/11/2020                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/*                                                                            */
/*============================================================================*/
/* Purpose:                                                                   */
/* To add, update, find, delete categories in the category list               */
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

#include "CategoryData.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : CategoryData
**
** Description           : To load category list from json file
**
** Author                : Dinh Pham
*******************************************************************************/
CategoryData::CategoryData(string fileName) {
    categoryList.resize(0);
    const int maxSize = 10000;
    /* Buffer to storage json string of each category */
    char buff[maxSize]; 
    /* Variable to read json file */
    ifstream inFile(fileName);

    /* Loop all line in json file and create object of the corresponding 
    Category */
    while (inFile.getline(buff, maxSize)) {
        json j = json::parse(buff);
        Categories p(
            j["categoryId"],
            j["categoryName"],
            j["description"]
        );
        categoryList.push_back(p);
    }
    inFile.close();
}

/*******************************************************************************
** Function Name         : addCategory
**
** Description           : Add new category to the category list
**
** Author                : Dinh Pham
*******************************************************************************/
void CategoryData::addCategory(const Categories& newCategory) {
    categoryList.push_back(newCategory);
    clog << "Added a Category" << endl;
}

/*******************************************************************************
** Function Name         : getCategoryByOrder
**
** Description           : Get category with its order in the category list
**
** Author                : Dinh Pham
*******************************************************************************/
Categories CategoryData::getCategoryByOrder(int order) {
    return categoryList[order];
}

/*******************************************************************************
** Function Name         : getCategoryByOrder
**
** Description           : Get category with its ID in the category list
**
** Author                : Dinh Pham
*******************************************************************************/
vector<Categories>::iterator CategoryData::getCategoryById(int categoryId) {
    vector<Categories>::iterator category;

    /* Find the category by ID in the category list */
    category = find_if(categoryList.begin(), categoryList.end(), 
    [=] (Categories& categoryIdInList) {
        return categoryId == categoryIdInList.m_CategoryId;
    });

    if (category != categoryList.end()) {
        clog << "Found a Category" << endl;
    } else {
        clog << "This Category doesn't exist" << endl;
    }

    return category;
}

/*******************************************************************************
** Function Name         : deleteCategoryById
**
** Description           : Delete category with its ID in the category list
**
** Author                : Dinh Pham
*******************************************************************************/
void CategoryData::deleteCategoryById(int categoryId) {
    categoryList.erase(getCategoryById(categoryId));
    clog << "Delete a Category" << endl;
}

void CategoryData::updateCategory(int categoryId, const Categories& updateCategory) {
    vector<Categories>::iterator category;

    /* Find the category by ID in the category list */
    category = find_if(categoryList.begin(), categoryList.end(), 
    [=] (Categories& categoryIdInList) {
        return categoryId == categoryIdInList.m_CategoryId;
    });

    category->m_CategoryId = updateCategory.m_CategoryId;
    category->m_CategoryName = updateCategory.m_CategoryName;
    category->m_Description = updateCategory.m_Description;
}
/*******************************************************************************
** Function Name         : getSize
**
** Description           : Get size of the category list
**
** Author                : Dinh Pham
*******************************************************************************/
int CategoryData::getSize() {
    return categoryList.size();
}

/*******************************************************************************
** Function Name         : exportToFile
**
** Description           : Export the category list to json file
**
** Author                : Dinh Pham
*******************************************************************************/
int CategoryData::exportToFile(string filename) {
    /* Variable to write to json file */
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;

    /* Loop all category and write to json file at the new line */
    for (Categories p : categoryList) {
        outFile << p.toJson() << endl;
    }
    outFile.close();
    return 1;
}   

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/