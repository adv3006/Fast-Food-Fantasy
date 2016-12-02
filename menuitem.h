#ifndef MENUITEM_H
#define MENUITEM_H

#include <QString> // string
#include <vector> // vector
#include <iostream> // cout
#include <algorithm> // find in vector
#include <fstream> // files
#include <limits> // numeric limits

using namespace std;

/*************************************************************************
 * Class MenuItem
 * This class represents a menu item in a restaurant with a name, price,
 * and number of times its been sold.
 *************************************************************************/
class MenuItem {
public:
    /*************************************************************************
     * Constructors & Destructors
     *************************************************************************/
    /**
     * @brief MenuItem
     * This is the default no-arg constructor for menu item. It initializes to
     * default values.
     */
    MenuItem();

    /**
     * @brief MenuItem
     * This is the non-default constructor with arguments that set the name and
     * price of the item
     * @param newName the name of the item
     * @param newPrice the price of the item
     */
    MenuItem(QString newName, double newPrice);

    /**
     * @brief MenuItem
     * This is the copy constructor for the menu item that allows for a deep copy
     * of the menu item
     * @param otherMenuItem the menu item to copy from
     */
    MenuItem(const MenuItem& otherMenuItem);

    /**
     * @brief ~MenuItem
     * This is the destructor for the menu item
     */
    ~MenuItem();

    /*************************************************************************
     * Mutators
     *************************************************************************/
    /**
     * @brief addSalesCount
     * This method adds sales to the item
     * @param newSales the new sales to add the item
     */
    void addSalesCount(int newSales);

    /**
     * @brief setPrice
     * This method sets the price of the menu item from the parameter
     * @param newPrice The price to set of the menu item
     */
    void setPrice(double newPrice);

    /**
     * @brief This method sets the name of the menu item from the parameter
     * @param newName The name to set of the menu item
     */
    void setName(QString newName);

    /*************************************************************************
     * Accessors
     *************************************************************************/
    /**
     * @brief sales
     * @return returns the number of sales for the item
     */
    int sales() const;

    /**
     * @brief name
     * @return Returns the name of the menu item
     */
    QString name() const;

    /**
     * @brief price
     * @return Returns the price of the menu item
     */
    double price() const;

private:
    double  itemPrice;      ///< price of item
    QString itemName;       ///< name of item
    int     itemSalesCount; ///< number of times item was sold
};

#endif // MENUITEM_H
