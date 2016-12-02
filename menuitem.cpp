#include "menuitem.h"

/*************************************************************************
 * Class MenuItem
 * This class represents a menu item in a restaurant with a name, price,
 * and number of times its been sold.
 *************************************************************************/
/*************************************************************************
* Constructors & Destructors
*************************************************************************/
/**
 * @brief MenuItem
 * This is the default no-arg constructor for menu item. It initializes to
 * default values.
 */
MenuItem::MenuItem(){
    itemName = "";
    itemSalesCount = 0;
    itemPrice = 0.0;
}

/**
 * @brief MenuItem
 * This is the non-default constructor with arguments that set the name and
 * price of the item
 * @param newName the name of the item
 * @param newPrice the price of the item
 */
MenuItem::MenuItem(QString newName, double newPrice) {
    itemPrice = newPrice;
    itemName = newName;
    itemSalesCount = 0;
}

/**
 * @brief MenuItem
 * This is the copy constructor for the menu item that allows for a deep copy
 * of the menu item
 * @param otherMenuItem the menu item to copy from
 */
MenuItem::MenuItem(const MenuItem &otherMenuItem){
    this->itemPrice = otherMenuItem.itemPrice;
    this->itemName  = otherMenuItem.itemName;
    this->itemSalesCount = otherMenuItem.itemSalesCount;
}

/**
 * @brief ~MenuItem
 * This is the destructor for the menu item
 */
MenuItem::~MenuItem() {
}

/*************************************************************************
* Mutators
*************************************************************************/
/**
 * @brief addSalesCount
 * This method adds sales to the item
 * @param newSales the new sales to add the item
 */
void MenuItem::addSalesCount(int newSales) {
    itemSalesCount += newSales;
}

/**
 * @brief setPrice
 * This method sets the price of the menu item from the parameter
 * @param newPrice The price to set of the menu item
 */
void MenuItem::setPrice(double newPrice) {
    itemPrice = newPrice;
}

/**
 * @brief This method sets the name of the menu item from the parameter
 * @param newName The name to set of the menu item
 */
void MenuItem::setName(QString newName) {
    itemName = newName;
}

/*************************************************************************
* Accessors
*************************************************************************/
/**
 * @brief sales
 * @return returns the number of sales for the item
 */
int MenuItem::sales() const {
    return itemSalesCount;
}

/**
 * @brief name
 * @return Returns the name of the menu item
 */
QString MenuItem::name() const {
    return itemName;
}

/**
 * @brief price
 * @return Returns the price of the menu item
 */
double MenuItem::price() const {
    return itemPrice;
}
