#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "menuitem.h"
#include <map>
#include <QString>
#include <QVector>

class Restaurant
{
public:
    /**
     * @brief Restaurant
     * default constructor
     */
    Restaurant();

    /**
     * @brief Restaurant
     * - constructor that sets variables with paramaters passed in
     * @param newName - restaurant name
     * @param newNum - restaurant num
     * @param newDistanceSB - restaurant distance from saddleback
     * @param newDistances - distances to other restaurants
     * @param newItem - vector of items
     * @param newPrice - vector of prices
     */
    Restaurant( QString newName, int newNum, float newDistanceSB,  QVector <float> newDistances,
                QVector <QString> newItem,  QVector <float> newPrice);
    /**
     * @brief GetName
     * @return - name of festaurant
     */
    QString GetName();

    /**
     * @brief GetNum
     * @return - number of restaurant
     */
    int GetNum();

    /**
     * @brief GetDistanceSB
     * @return  - distance from saddleback
     */
    float GetDistanceSB();

    /**
     * @brief GetDistances
     * @return - vector of distances to other restaurants
     */
    QVector <float> GetDistances();

    /**
     * @brief GetItems
     * @return - vector of menu items
     */
    QVector <QString> GetItems();

    /**
     * @brief GetPrices
     * @return - vector of menu prices
     */
    QVector <float> GetPrices();

    /**
     * @brief SetNum
     * - sets restaurant number with number passed in
     * @param newNum - new restaurant number
     */
    void SetNum(int newNum);

    /**
     * @brief SetMenu
     * -sets menu item with name and price passed in
     * @param name - restaurant name
     * @param price - restaurant price
     */
    void SetMenu(QString name, float price);

    /**
     * @brief SetDistances
     * sets distance with distance passed in
     * @param newDistance - new distance
     */
    void SetDistances(float newDistance);

    /**
     * @brief SetName
     * -sets name of restaurant with name passed in
     * @param n - new name
     */
    void SetName(QString n);

    /**
     * @brief SetDistanceSB
     * - sets distance from saddleback
     * @param d - new distance passed in
     */
    void SetDistanceSB(float d);

    /**
     * @brief purchase
     * -purchases menu item from restaurant
     * @param index -
     * @param quantity - number bought
     */
    void purchase(int index, int quantity);

    /**
     * @brief purchase
     * - purchase item from restauarnt
     * @param restaurantIndex - number restaurant
     * @param menuItemIndex - menu item index
     * @param quantity - quantity bought
     */
    void purchase(int restaurantIndex, int menuItemIndex, int quantity);

    /**
     * @brief menuItem
     * - returns menu item with index passed in
     * @param index
     * @return - menu item
     */
    MenuItem menuItem(int index);

    /**
     * @brief setLogoPath
     * @param nameLogo - returns logo of name of restaurant passed in
     */
    void setLogoPath(string nameLogo);

    /**
     * @brief SetRestaurant
     * @param r
     */
    void SetRestaurant(Restaurant r);

    /**
     * @brief ClearMenu
     * - clears menu items
     */
    void ClearMenu();

    /**
     * @brief ClearDistances
     * -clears distances
     */
    void ClearDistances();

    /**
     * @brief addMenuItem
     * adds a menu item to the restaurant
     * @param newMenuItem the menu item to be added
     */
    void addMenuItem(MenuItem newMenuItem);

    /**
     * @brief addRevenue
     * adds revenue to the restaurant
     * @param newRevenue the revenue to add
     */
    void addRevenue(double newRevenue);

    /**
     * @brief addSalesCount
     * adds new sales to the restaurant
     * @param newSale the amount of new sales to add
     */
    void addSalesCount(int newSale);
    /**
     * @brief setDistanceFrom
     * sets the distance away from the specifid restaurant
     * @param otherRestaurantNumber the other restaurant to set the distance away from
     * @param distance the amount of distance to set away from the other restaurant
     */
    void setDistanceFrom(int otherRestaurantNumber, double distance);

    /*************************************************************************
    * Acccessors
    *************************************************************************/
    /**
     * @brief getLogoPath
     * @return returns the logo path of the restaurant
     */
    string getLogoPath();
    /**
     * @brief menuList
     * @return returns the vector of the menu list for the restaurant
     */
    QVector<MenuItem> menuList() const;

    /**
     * @brief menuListPtr
     * @return returns a pointer to the list of the menu items for the restaurant
     */
    QVector<MenuItem> menuListPtr();

    /**
     * @brief number
     * @return returns the number of the restaurant
     */
    int number() const;

    /**
     * @brief revenue
     * @return returns the revenue of the restaurant
     */
    double revenue() const;

    /**
     * @brief salesCount
     * @return returns amount of sales restaurant has
     */
    int salesCount() const;

    /**
     * @brief distanceFrom
     * @param otherRestaurantNumber the restaurant number that the method will
     * return the distance away from
     * @return the distance away from the specified restaurant number
     */
    double distanceFrom(int otherRestaurantNumber);

    void RemoveMenuItem(int i);

private:
    QString               name;                             ///< name of restaurant
    int                   num;                              ///< number of restaurant
    float                 distanceSB;                       ///< distance from saddleback
    QVector <float>       distances;                        ///< distances to other restaurants
    QVector <QString>     item;                             ///< menu items
    QVector <float>       price;                            ///< menu prices
    QVector<MenuItem>     restaurantMenuList;               ///< all menu items and prices
    std::map<int, double> restaurantDistances;              ///< map of distances
    double                restaurantRevenue;                ///< total revenue
    int                   restaurantSalesCount;             ///< total sales made
    double                restaurantDistanceFromSaddleback; ///< distance from saddleback
    int                   restaurantNumber;                 ///< number
    string                logoPath;                         ///< path for logo
};

#endif // RESTAURANT_H
