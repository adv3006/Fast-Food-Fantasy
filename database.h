#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QVector>
#include <QString>
#include <QDebug>
#include "restaurant.h"

class database
{
public:
    /**
     * @brief database
     * - constructor
     */
    database();

    /**
     * @brief AddRestaurant
     * - adds new restaurant to database
     * @param add - new restaurant
     * @return if adding was successful
     */
    bool AddRestaurant(Restaurant add);

    /**
     * @brief TestDatabase
     * -used to test what is in database
     */
    void TestDatabase();

    /**
     * @brief GetRestaurantsName
     * @return - name of restaurant
     */
    QVector<QString> GetRestaurantsName();

    /**
     * @brief SearchForName
     * -searches for restaurant with name passed in
     * @param key - name of restaurant
     * @return - true if restaurant is found, false if not
     */
    bool SearchForName(QString key);

    /**
     * @brief SearchForNumber
     * -searches for restaurant with number passed in
     * @param key - number of restaurant to search for
     * @return - true if restaurant is found, false if not
     */
    bool SearchForNumber(int key);

    /**
     * @brief GetAllRestaurants
     * - stores restaurants names and distances to paramets passed in by reference
     * @param names - names of restaurants
     * @param distances - distances of restaurants
     */
    void GetAllRestaurants(QVector<QString>& names, QVector<float> &distances);

    /**
     * @brief AllRestaurantInfo
     * @return -returns vector of all restaurants in database
     */
    QVector<Restaurant> AllRestaurantInfo();

    /**
     * @brief GetRestaurant
     * @param name - name of restauant to return
     * @return - restaurant info
     */
    Restaurant GetRestaurant(QString name);

    /**
     * @brief AddMenuItem
     * @param item
     * @param price
     * @param name
     * @return
     */
    bool AddMenuItem(QString item, float price, QString name);

    /**
     * @brief DelteMenuItem
     * - deletes menu item from restaurant
     * @param item
     * @param name
     * @return
     */
    bool DelteMenuItem(QString item, QString name);

    /**
     * @brief CheckMenuItem
     * - checks if menu item passed in is already in restaurant menu
     * @param name
     * @return
     */
    bool CheckMenuItem(QString name);

    /**
     * @brief ChangePrice
     * - Changes menu item price with price passed in
     * @param itemName
     * @param newPrice
     * @return
     */
    bool ChangePrice(QString itemName, float newPrice);

private:
    QSqlDatabase db; ///< accsesses database

};

#endif // DATABASE_H
