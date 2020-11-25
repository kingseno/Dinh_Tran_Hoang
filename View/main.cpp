#include <iostream>
#include "../DataAccess/ProductData.h"
#include "../DataAccess/OrderDetailData.h"
#include "../View/View.h"
#include "StockManagement.h"


using namespace std;

void read_products_from_file(){
	ProductData productsData("../DataBase/Products.json");
	for (int i = 0; i < productsData.getSize(); i++) {
		Products p = productsData.getProductByOrder(i);
		cout << p.toString() << endl;
	}
}

int main() {
    // Products product(1, "abc", 1, 1, "abc", 1);
    // Products product2(2, "xyz", 1, 1, "xyz", 1);
    // ProductData productData;
    
    
    // productData.addProduct(product);
    // productData.addProduct(product);
    // productData.addProduct(product2);
    // productData.getProductById(1);
    
    // productData.deleteProductById(1);
    // productData.exportToFile("pretty.json");
    // read_products_from_file();

    loadMainScreen();
    
    return 0;
}
