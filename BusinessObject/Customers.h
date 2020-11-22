/** @file Customers.h
 *  @brief Function prototypes for the console driver.
 *
 *  This contains the prototypes for the console
 *  driver and eventually any macros, constants,
 *  or global variables you will need.
 *
 *  @author Harry Q. Bovik (hqbovik)
 *  @author Fred Hacker (fhacker)
 *  @bug No known bugs.
 */

#ifndef _Customers_h
#define _Customers_h

#include <string>
#include "../Util/json.hpp"

using namespace std;
using json = nlohmann::json;

class Customers{
public:
    int CustomerId;
    string CustomerName, ContactName, Address, City, PostalCode, Country;
public:
    Customers();
    Customers(int CustomerId, string CustomerName, string ContactName, string Address, string City, string PostalCode, string Country);
    string ToString();
    json ToJson();
};
#endif