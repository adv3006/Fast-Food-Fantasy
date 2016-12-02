#include "restaurant.h"
#include <QDebug>

/**
 * @brief Restaurant::Restaurant
 */
Restaurant::Restaurant()
{

}

/**
 * @brief Restaurant::Restaurant
 * @param newName - restaurant name
 * @param newNum - restaurant number
 * @param newDistanceSB - distance from saddleback
 * @param newDistances - vector of distances
 * @param newItem - vector of menu items
 * @param newPrice - vector of menu prices
 */
Restaurant::Restaurant(QString newName, int newNum, float newDistanceSB,
                       QVector<float> newDistances, QVector<QString> newItem,
                       QVector<float> newPrice)
{
    name       = newName;
    num        = newNum;
    distanceSB = newDistanceSB;
    distances  = newDistances;
    for(int i = 0; i < newItem.size(); i++)
    {
        MenuItem item(newItem[i], newPrice[i]);
        restaurantMenuList.push_back(item);
    }
    item  = newItem;
    price = newPrice;
}

/**
 * @brief Restaurant::GetName
 * @return restaurants name
 */
QString Restaurant::GetName()
{
    return name;
}

/**
 * @brief Restaurant::GetNum
 * @return restaurants number
 */
int Restaurant::GetNum()
{
    return num;
}

/**
 * @brief Restaurant::GetDistanceSB
 * @return distance from saddleback
 */
float Restaurant::GetDistanceSB()
{
    return distanceSB;
}

/**
 * @brief Restaurant::GetDistances
 * @return - distances from other restaurants
 */
QVector<float> Restaurant::GetDistances()
{
    return distances;
}

/**
 * @brief Restaurant::GetItems
 * @return vector of items
 */
QVector<QString> Restaurant::GetItems()
{
    return item;
}

/**
 * @brief Restaurant::GetPrices
 * @return vector of prices
 */
QVector<float> Restaurant::GetPrices()
{
    return price;
}

/**
 * @brief Restaurant::SetNum
 * -sets new restaurant number
 * @param newNum
 */
void Restaurant::SetNum(int newNum)
{
    num = newNum;
    restaurantNumber = newNum;
}

/**
 * @brief Restaurant::SetMenu
 * - sets restaurant menu
 * @param name
 * @param price
 */
void Restaurant::SetMenu(QString name, float price)
{
    item.push_back(name);
    this->price.push_back(price);

    MenuItem item(name, price);
    restaurantMenuList.push_back(item);
}

/**
 * @brief Restaurant::SetDistances
 * - set restaurant distances
 * @param newDistance
 */
void Restaurant::SetDistances(float newDistance)
{
    distances.push_back(newDistance);
}

/**
 * @brief Restaurant::SetName
 * set restaurant name
 * @param n
 */
void Restaurant::SetName(QString n)
{
    name = n;
}

/**
 * @brief Restaurant::SetDistanceSB
 * set restaurant distance from saddleback
 * @param d
 */
void Restaurant::SetDistanceSB(float d)
{
    distanceSB = d;
    restaurantDistanceFromSaddleback = d;
}

/**
 * @brief Restaurant::purchase
 * -purchases an item from the restaurant
 * @param index
 * @param quantity
 */
void Restaurant::purchase(int index, int quantity) {
    // pointer to menu item
    MenuItem menuItemPtr = menuItem(index);

    // add revenue, which is price of item times quantity
    addRevenue(menuItemPtr.price() * quantity);

    // add sales count, which is quantity
    addSalesCount(quantity); // to restaurant
    menuItemPtr.addSalesCount(quantity); // to item
}

/**
 * @brief Restaurant::menuItem
 * - returns a pointer to the menu item at the specified index.
 * @param index
 * @return
 */
MenuItem Restaurant::menuItem(int index)
{
    // returns a pointer to the menu item at the specified index.
    // Use this to directly edit the item
    return restaurantMenuList[index];
}

/**
 * @brief Restaurant::setLogoPath
 * -sets logo path
 * @param nameLogo - restaurant name
 */
void Restaurant::setLogoPath(string nameLogo){
    string imgPath = ":/logos/";


    if(nameLogo == "MacDonald's")           { imgPath += "mcdonalds_logo.png";}
    else if(nameLogo == "Chipotle")         { imgPath += "chipotle_logo.png";}
    else if(nameLogo == "Domino's Pizza")   { imgPath += "dominos_logo.png";}
    else if(nameLogo == "KFC")              { imgPath += "kfc_logo.png";}
    else if(nameLogo == "Subway")           { imgPath += "subway_logo.png";}
    else if(nameLogo == "In-N-Out Burger")  { imgPath += "innout_logo.png";}
    else if(nameLogo == "Wendy's")          { imgPath += "wendys_logo.png";}
    else if(nameLogo == "Jack in the Box")  { imgPath += "jackinthebox_logo.png";}
    else if(nameLogo == "El Pollo Loco")    { imgPath += "elpolloloco_logo.png";}
    else if(nameLogo == "Papa John's Pizza"){ imgPath += "papajohns_logo.png";}
    else if(nameLogo == "Pizza Hut")        { imgPath += "pizzahut_logo.png";}
    else if(nameLogo == "Sonic")            { imgPath += "sonic_logo.png";}
    else                                { imgPath += "default.png";}

    logoPath = imgPath;
}

/**
 * @brief Restaurant::SetRestaurant
 * sets restaurant with one passed in
 * @param r - new restaurant
 */
void Restaurant::SetRestaurant(Restaurant r)
{
    name = r.GetName();
    num = r.GetNum();
    distanceSB = r.GetDistanceSB();
    distances = r.GetDistances();
    item = r.GetItems();
    price = r.GetPrices();
}

/**
 * @brief Restaurant::ClearMenu
 * - clears the menu of the restaurant
 */
void Restaurant::ClearMenu()
{
    item.clear();
    price.clear();
    restaurantMenuList.clear();
}

/**
 * @brief Restaurant::ClearDistances
 * -clears the distances of the restaurant
 */
void Restaurant::ClearDistances()
{
    restaurantDistances.clear();
}

/**
 * @brief Restaurant::addMenuItem
 * -adds a newmenu item to the restaurant
 * @param newMenuItem
 */
void Restaurant::addMenuItem(MenuItem newMenuItem)
{
    // menu may only hold 8 items
    if (restaurantMenuList.size() <= 7) {
        restaurantMenuList.push_back(newMenuItem);
    }
}

/**
 * @brief Restaurant::addRevenue
 * @param newRevenue
 */
void Restaurant::addRevenue(double newRevenue)
{
    restaurantRevenue += newRevenue;
}

/**
 * @brief addSalesCount
 * adds new sales to the restaurant
 * @param newSale the amount of new sales to add
 */
void Restaurant::addSalesCount(int newSale) {
    restaurantSalesCount += newSale;
}

/**
 * @brief setDistanceFrom
 * sets the distance away from the specifid restaurant
 * @param otherRestaurantNumber the other restaurant to set the distance away from
 * @param distance the amount of distance to set away from the other restaurant
 */
void Restaurant::setDistanceFrom(int otherRestaurantNumber, double distance) {
    restaurantDistances[otherRestaurantNumber] = distance;
}

/**
 * @brief Restaurant::getLogoPath
 * @return - returns logo path
 */
string Restaurant::getLogoPath(){
    return logoPath;
}

/**
 * @brief menuList
 * @return returns the vector of the menu list for the restaurant
 */
QVector<MenuItem> Restaurant::menuList() const {
    return restaurantMenuList;
}

/**
 * @brief Restaurant::menuListPtr
 * @return
 */
QVector<MenuItem> Restaurant::menuListPtr() {
    //we meeded direct manipulation of the menu list so we made a new method
    //to return a pointer to the restaurant objects menu list vector
    //the reason for doing so was that we did not want to change the API
    //because other code could be using it. Therefore we just made a new method
    return restaurantMenuList;
}

/**
 * @brief number
 * @return returns the number of the restaurant
 */
int Restaurant::number() const {
    return restaurantNumber;
}

/**
 * @brief revenue
 * @return returns the revenue of the restaurant
 */
double Restaurant::revenue() const {
    return restaurantRevenue;
}

/**
 * @brief salesCount
 * @return returns amount of sales restaurant has
 */
int Restaurant::salesCount() const {
    return restaurantSalesCount;
}

/**
 * @brief Restaurant::distanceFrom
 * @param otherRestaurantNumber
 * @return
 */
double Restaurant::distanceFrom(int otherRestaurantNumber) {
    return restaurantDistances[otherRestaurantNumber];
}

void Restaurant::RemoveMenuItem(int i)
{
    item.remove(i);
}
