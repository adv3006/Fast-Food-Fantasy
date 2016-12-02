#ifndef RESTAURANTLIST_H
#define RESTAURANTLIST_H

#include "restaurant.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <limits>
#include <map>
#include <queue>
#include "errorcheck.h"
#include <QDebug>
using namespace std;

/*************************************************************************
 * Class RestaurantList
 * This class represents a list of restaurants.
 *************************************************************************/
class RestaurantList {
public:
    /*************************************************************************
    * Constructors & Destructors
    *************************************************************************/
    /**
     * @brief RestaurantList
     * This is the default constructor for the restaurant list. It does not
     * initialize anything.
     */
    RestaurantList();

    /**
     * @brief ~RestaurantList
     * This is the destructor for the restaurant list.
     */
    ~RestaurantList();

    /*************************************************************************
    * Mutators
    *************************************************************************/
    /**
     * @brief addRestaurant
     * this method adds a new restaurant to the restaurant list
     * @param newRestaurant the new restaurant to add
     */
    void addRestaurant(Restaurant newRestaurant);

    /**
     * @brief purchase
     * This method purchases the item specified at a quantity specified, for the
     * restaurant at the specified index
     * @param restaurantIndex the index of the restaurant to purchase the item for
     * @param menuItemIndex the index of the menu item to be purchased for the
     * restaurant
     * @param quantity the quantity of the item to be purchased for the restaurant
     */
    void purchase(int restaurantIndex, int menuItemIndex, int quantity);

    /**
     * @brief addPurchase
     * Adds revenue and quantity information to the restaurant list as a total of
     * all restaurants
     * @param revenue the revenue to add to the restaurant list
     * @param quantity the quantity of purchases to add to the restaurant list
     */
    void addPurchase(double revenue, int quantity);

    /**
     * @brief initialize
     * This method calls either calls loadRestaurantListFromFile to load from the
     * save file or calls addDefaultRestaurants to load from the default file. It
     * also calls a method to load the revenue data if it exists.
     */
    void initialize(QVector<Restaurant> list);

    /**
     * @brief addNewRestaurantsFromList
     * This method calls loadRestaurantListFromFile to load the new restaurants
     * from the extra input file.
     */
    void addNewRestaurantsFromList();

    /**
     * @brief SetRestaurantList
     * -sets vector of restaurants with vector passed in
     * @param res - new list of restaurants
     */
    void SetRestaurantList(QVector<Restaurant> res);


    /*************************************************************************
    * Accessors
    *************************************************************************/
    /**
     * @brief restaurant
     * This method returns a pointer to the restaurant at the specified index
     * @param index the index to get the restaurant from
     * @return returns the restaurant at the specified index
     */
    Restaurant GetRestaurant(int index);

    /**
     * @brief restaurant
     * returns a pointer to the restaurant with given restaurant name
     * @param restaurantName the name fo the restaurant as a std::string
     * @return restaurant pointer if found, null if not found
     */
    Restaurant restaurant(QString restaurantName);

    /**
     * @brief restaurantByID
     * This method returns a pointer to the restaurant with the specified number
     * @param number the number of the restaurant to return
     * @return the pointer to the restaurant with the specified number
     */
    Restaurant restaurantByID(int number);

    /**
     * @brief hasLoadedFromNewList
     * @return whether the new list has been loaded.
     */
    bool hasLoadedFromNewList() const;

    /**
     * @brief size
     * @return Returns the size of the vector that is the list of the restaurants.
     */
    unsigned int size();

    /**
     * @brief getTotalRevenue
     * updates and returns total revenue
     * @return total revenue of all restaurants
     */
    double getTotalRevenue();

    /**
     * @brief getTotalItemsPurchased
     * updates and returns total sales count
     * @return returns total sales count of all restaurants
     */
    int getTotalItemsPurchased();

    /*************************************************************************
    * Utility
    *************************************************************************/
    /**
     * @brief saveWhetherLoadedNewFile
     * Saves whether the new file was loaded to a file.
     */
    void saveThatLoadedNewFile();

    /**
     * @brief saveRevenue
     * This method saves to a file the revenue of all of the restaurants.
     */
    void saveRevenue();

    /**
     * @brief saveRestaurantList
     * This method saves to a file the restaurant list data, such as the names
     * and menu items of the restaurants.
     */
    void saveRestaurantList();

    /**
     * @brief distanceAlgorithm
     * This method sorts a list of restaurant indices by distance so that a trip
     * goes in the most efficient order. With the parameters the caller can
     * specify a starting restaurant, otherwise by default it will start with
     * whichever of the restaurants passed to it is closest to saddleback. It
     * returns a queue of the restaurants sorted in the most efficient order.
     * @param indices a vector of indices to sort by distance
     * @param presetStartingRestaurantEnabled Whether a starting restaurant is
     * going to be set and passed to this method
     * @param startingRestaurantIndex If a starting restaurant is going to be set,
     * this is the index of the starting restaurant
     * @return
     */
    queue <int> distanceAlgorithm(QVector<int> indices,
                                  bool presetStartingRestaurantEnabled = false,
                                  int startingRestaurantIndex = 0);

    /**
     * @brief SetResList
     * - sets restaurant list with list passed in
     * @param list
     */
    void SetResList(RestaurantList list);

protected:
    /*************************************************************************
    * Mutators
    *************************************************************************/
    /**
     * @brief calcTotals
     * This method iterates through each restaurant in the list
     * and accumulates their sales count and total revenues and
     * assigns those values back to the attributes of this class
     */
    void calcTotals();

    /**
     * @brief GetResList
     * returns vector of restaurants
     * @return
     */
    QVector<Restaurant> GetResList();

    /**
     * @brief loadRevenue
     * This method loads revenue data from the specified file.
     * @param filename the file to load from.
     */
    void loadRevenue(string filename);

private:
    QVector<Restaurant> restaurantList;     ///< list of restaurants
    double              totalRevenue;       ///< total revenue
    int                 totalItemsPurchased;///< number of items purchased
};

#endif // RESTAURANTLIST_H
