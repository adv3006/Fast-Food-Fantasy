#include "restaurantlist.h"
/*************************************************************************
 * Class RestaurantList
 * This class represents a list of restaurants.
 *************************************************************************/
/*************************************************************************
* Constructors & Destructors
*************************************************************************/
/**
 * @brief RestaurantList
 * This is the default constructor for the restaurant list. It does not
 * initialize anything.
 */
RestaurantList::RestaurantList() {
    totalRevenue        = 0.0;
    totalItemsPurchased = 0.0;
}

/**
 * @brief ~RestaurantList
 * This is the destructor for the restaurant list.
 */
RestaurantList::~RestaurantList()
{

}

/*************************************************************************
* Mutators
*************************************************************************/
/**
 * @brief addRestaurant
 * this method adds a new restaurant to the restaurant list
 * @param newRestaurant the new restaurant to add
 */
void RestaurantList::addRestaurant(Restaurant newRestaurant) {
    restaurantList.push_back(newRestaurant);
}

/**
 * @brief purchase
 * This method purchases the item specified at a quantity specified, for the
 * restaurant at the specified index
 * @param restaurantIndex the index of the restaurant to purchase the item for
 * @param menuItemIndex the index of the menu item to be purchased for the
 * restaurant
 * @param quantity the quantity of the item to be purchased for the restaurant
 */
void RestaurantList::purchase(int restaurantIndex, int menuItemIndex, int quantity) {
    // pointer to restaurant
    Restaurant restaurantPtr = GetRestaurant(restaurantIndex);
    restaurantPtr.purchase(menuItemIndex, quantity);

    totalItemsPurchased += quantity;
    // add revenue
    totalRevenue += restaurantPtr.menuItem(menuItemIndex).price()
            * quantity;
}

/**
 * @brief addPurchase
 * Adds revenue and quantity information to the restaurant list as a total of
 * all restaurants
 * @param revenue the revenue to add to the restaurant list
 * @param quantity the quantity of purchases to add to the restaurant list
 */
void RestaurantList::addPurchase(double revenue, int quantity){
    totalItemsPurchased += quantity;
    totalRevenue        += revenue;
}

///**
// * @brief loadRestaurantListFromFile
// * This method loads data from an input file and puts that information into the
// * restaurant list
// * @param filename the filename to load from
// */
//void RestaurantList::loadRestaurantListFromFile(string filename) {
//    // the input file stream to traverse
//    ifstream inFile;

//    // a string to traverse the file and read data
//    string lineReader;
//    // whether to check for blank lines
//    bool checkForBlackLines = true;
//    // the amount of menu items to check for
//    int menuItemNum = 0;
//    // the name of the restaurant
//    string restaurantName;
//    // the distance from saddleback
//    double restaurantSaddlebackDistance = 0.0;
//    // the name of the menu item to be added to the current restaurant
//    string itemName;
//    // the price of the menu item to be added to the current restaurant
//    double itemPrice;
//    // the number of the restaurant
//    int restaurantNumber;
//    // the number of distances to record from other restaurants
//    double distanceFromOtherRestaurants;
//    // the distance from current other restaurant
//    double distance;
//    // the map of the distances away from other restaurants, with number of the
//    // restaurant as the key and the distance as the value
//    std::map<int, double> restaurantDistances;

//    // pointer of the new restaurant to add
//    Restaurant* restPtr;
//    // pointer of the new menu item to add to the new restaurant
//    MenuItem* itemPtr;

//    // open the input file
//    inFile.open(filename.c_str());

//    while (!inFile.eof()) {

//        // get restaurant name
//        getline(inFile, restaurantName);
//        // replace non-latin characters and convert from qstring to string
//        restaurantName = QString::fromStdString(restaurantName).toLatin1().replace("?","'").toStdString();

//        // restaurant number
//        // ignore first 28 characters
//        inFile.ignore(28);
//        inFile >> restaurantNumber;
//        // ignore rest
//        getline(inFile, lineReader);

//        // restaurant distance from other restaurants
//        inFile.ignore(50);
//        inFile >> distanceFromOtherRestaurants;
//        // ignore rest
//        getline(inFile, lineReader);

//        // array of distances
//        for (unsigned int i = 0; i < distanceFromOtherRestaurants; i++) {
//            // ignore first one
//            inFile >> distance;
//            inFile >> distance;
//            getline(inFile, lineReader);
//            restaurantDistances[i + 1] = distance;
//            if (distanceFromOtherRestaurants >= size() && 1 <= size()) {
//                // set distances of preexisting restaurants on restaurant list
//                // size change
//                if (size() >= i + 1) {
//                    restaurant(i)->setDistanceFrom(size() + 1, distance);
//                }
//            }
//        }

//        // distance from saddleback
//        inFile >> restaurantSaddlebackDistance;
//        // ignore rest of line
//        getline(inFile, lineReader);

//        restPtr = new Restaurant(restaurantName.substr(30),
//                                 restaurantSaddlebackDistance,
//                                 restaurantNumber, restaurantDistances);

//        // number of menu items
//        inFile >> menuItemNum;

//        // clear buffer
//        inFile.ignore(numeric_limits<streamsize>::max(), '\n');

//        // menu items
//        for (int i = 0; i < menuItemNum; i++) {
//            getline(inFile, itemName);
//            inFile >> itemPrice;

//            // clear buffer
//            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//            itemPtr = new MenuItem(itemName, itemPrice);

//            // add item to restaurant
//            restPtr->addMenuItem(*itemPtr);
//        }

//        // add restaurant to list
//        addRestaurant(*restPtr);

//        // blank lines
//        getline(inFile, lineReader);
//        do {
//            lineReader = inFile.peek();
//            if (lineReader == "\n") {
//                getline(inFile, lineReader);
//            } else {
//                checkForBlackLines = false;
//            }
//        } while (checkForBlackLines);
//        checkForBlackLines = true;
//    }

//    // close the input file
//    inFile.close();
//}

/**
 * @brief initialize
 * This method calls either calls loadRestaurantListFromFile to load from the
 * save file or calls addDefaultRestaurants to load from the default file. It
 * also calls a method to load the revenue data if it exists.
 */
void RestaurantList::initialize(QVector<Restaurant> list)
{
    restaurantList = list;
}


void RestaurantList::SetRestaurantList(QVector<Restaurant> res)
{
    restaurantList = res;

}

/**
 * @brief loadRevenue
 * This method loads revenue data from the specified file.
 * @param filename the file to load from.
 */
void RestaurantList::loadRevenue(string filename) {
    // DECLARE/INITIALIZE
    // input file stream
    ifstream inFile;
    // revenue of restaurant
    double revenue = 0;
    // sales count of restaurant
    unsigned int salesCount = 0;
    // a string to traverse the file and read data
    string lineReader;
    // the index of the restaurant
    unsigned int restaurantIndex = 0;

    // open file
    inFile.open(filename.c_str());

    // while in the file
    while (!inFile.eof()) {
        // get revenue
        inFile >> revenue;
        // get next line
        getline(inFile, lineReader);

        //get salesCount and nextLine
        inFile >> salesCount;
        getline(inFile,lineReader);

        // set revenue
        if (restaurantIndex < size()) {
            GetRestaurant(restaurantIndex).addRevenue(revenue);
            GetRestaurant(restaurantIndex).addSalesCount(salesCount);
        }

        // increment counter
        restaurantIndex++;
    }

    // close the file
    inFile.close();
}

/**
 * @brief calcTotals
 * This method iterates through each restaurant in the list
 * and accumulates their sales count and total revenues and
 * assigns those values back to the attributes of this class
 */
void RestaurantList::calcTotals(){
    double totalRev = 0;
    int totalCount  = 0;

    // for the restaurant list total up the revenue and sales count
    for(unsigned int i = 0; i < restaurantList.size(); i++){
        Restaurant rest = GetRestaurant(i);

        totalRev   += rest.revenue();
        totalCount += rest.salesCount();
    }
    totalRevenue = totalRev;
    totalItemsPurchased = totalCount;
}

/**
 * @brief RestaurantList::GetResList
 * @return restaurant list
 */
QVector<Restaurant> RestaurantList::GetResList()
{
    return restaurantList;
}

/*************************************************************************
* Accessors
*************************************************************************/
/**
 * @brief restaurant
 * This method returns a pointer to the restaurant at the specified index
 * @param index the index to get the restaurant from
 * @return returns the restaurant at the specified index
 */
Restaurant RestaurantList::GetRestaurant(int index)
{
    return restaurantList[index];
}

/**
 * @brief restaurant
 * returns a pointer to the restaurant with given restaurant name
 * @param restaurantName the name fo the restaurant as a std::string
 * @return restaurant pointer if found, null if not found
 */
Restaurant RestaurantList::restaurant(QString restaurantName)
{
    for(unsigned int i = 0; i < restaurantList.size(); i++)
    {
        if(restaurantList[i].GetName() == restaurantName)
        {
            return restaurantList[i];
        }
    }
}

/**
 * @brief restaurantByID
 * This method returns a pointer to the restaurant with the specified number
 * @param number the number of the restaurant to return
 * @return the pointer to the restaurant with the specified number
 */
Restaurant RestaurantList::restaurantByID(int number)
{
    //PROCESSING - searches for restaurant with id passed in
    for (unsigned int index = 0; index < size(); index++)
    {
        //PROCESSING - if found, retuarsn the restaurant
        if (restaurantList[index].GetNum() == number)
        {
            return restaurantList[index];
        }
    }
}

/**
 * @brief hasLoadedFromNewList
 * @return whether the new list has been loaded.
 */
bool RestaurantList::hasLoadedFromNewList() const {
    // declare/initialize
    // the input file stream to load from
    ifstream inFile;
    // string to hold data
    string test = "";
    // the boolean value to return
    bool returnValue = false;

    // open input file
    inFile.open("SaveDataMisc.txt");

    // get data at the line
    getline(inFile, test);
    // if line says true return value si true
    if (test == "true") {
        returnValue = true;
    }

    // close the file
    inFile.close();

    // return the boolean
    return returnValue;
}

/**
 * @brief size
 * @return Returns the size of the vector that is the list of the restaurants.
 */
unsigned int RestaurantList::size()
{
    return restaurantList.size();
}

/**
 * @brief getTotalRevenue
 * updates and returns total revenue
 * @return total revenue of all restaurants
 */
double RestaurantList::getTotalRevenue()
{
    calcTotals();
    return totalRevenue;
}

/**
 * @brief getTotalItemsPurchased
 * updates and returns total sales count
 * @return returns total sales count of all restaurants
 */
int RestaurantList::getTotalItemsPurchased()
{
    calcTotals();
    return totalItemsPurchased;
}

/*************************************************************************
* Utility
*************************************************************************/
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
queue<int> RestaurantList::distanceAlgorithm(QVector<int> indices, bool presetStartingRestaurantEnabled,
                                             int startingRestaurantIndex) {

    // queue of sorted indices to return
    queue <int> restaurantQueue;
    // holds the current restaurant id
    int restaurantID = 0;
    // holds the index of the restaurant at the current lowest distance
    int lowestDistanceIndex = 0;
    // holds the current lowest index
    double lowestDistance = 0;

    // if the vector of indices passed to this method is at least 2
    if (indices.size() > 1)
    {
        if (!presetStartingRestaurantEnabled) {
            // start with distance of first element
            lowestDistance = GetRestaurant(indices[0]).GetDistanceSB();
            lowestDistanceIndex = 0;
            for (unsigned int i = 1; i < indices.size(); i++) {
                if (GetRestaurant(indices[i]).GetDistanceSB() < lowestDistance) {
                    lowestDistanceIndex = i;
                    lowestDistance = GetRestaurant(indices[i]).GetDistanceSB();
                }
            }
            // push the index of the restaurant closest to saddleback to queue
            restaurantID = indices[lowestDistanceIndex];
            restaurantQueue.push(indices[lowestDistanceIndex]);

            // pop the index of that restaurant from the initial list
            // so it is not revisited
            indices.erase(indices.begin() + lowestDistanceIndex);
        }
        else {
            restaurantID = startingRestaurantIndex;
            restaurantQueue.push(startingRestaurantIndex);
        }

        // loop for the remaining restaraunts
        while (indices.size() > 1)
        {
            // re-initialize
            int startPoint = restaurantID;
            lowestDistanceIndex = 0;
            lowestDistance = GetRestaurant(startPoint).distanceFrom(GetRestaurant(indices[0]).number());

            for (unsigned int i = 1; i < indices.size(); i++) {
                if (GetRestaurant(startPoint).distanceFrom(GetRestaurant(indices[i]).number()) < lowestDistance) {
                    lowestDistanceIndex = i;
                    lowestDistance = GetRestaurant(startPoint).distanceFrom(GetRestaurant(indices[i]).number());
                }
            }

            // push the index of the restaurant closest to the previous one onto the queue
            restaurantID = indices.at(lowestDistanceIndex);
            restaurantQueue.push(indices.at(lowestDistanceIndex));

            // pop the index of that restaurant from the initial list
            // so it is not revisited
            indices.erase(indices.begin() + lowestDistanceIndex);

        }

        // push the last remaining restaurant onto the queue
        restaurantQueue.push(indices.at(0));

    }
    else if (indices.size() == 1)
    {
        restaurantQueue.push(indices.at(0));
    }
    return restaurantQueue;
}

/**
 * @brief RestaurantList::SetResList
 * @param list
 */
void RestaurantList::SetResList(RestaurantList list)
{
    restaurantList      = list.GetResList();
    totalRevenue        = list.getTotalRevenue();
    totalItemsPurchased = list.getTotalItemsPurchased();
}

/**
 * @brief saveRestaurantList
 * This method saves to a file the restaurant list data, such as the names
 * and menu items of the restaurants.
 */
void RestaurantList::saveRestaurantList() {
    // output file stream to write to
    ofstream outFile;

    // open the save file
    outFile.open("SavedRestaurantList.txt");

    // for the number of restaurants
    for (unsigned int i = 0; i < size(); i++) {
        // output blank line if not first restaurant
        if (i != 0) {
            outFile << endl;
        }

        // write restauranta data to file
        outFile << "Name of Fast Food restaurant: "
                << restaurantList[i].GetName().toStdString() << endl;
        outFile << "Fast Food restaurant number "
                << restaurantList[i].GetNum() << endl;
        outFile << "Distance (miles) to other Fast Food restaurants - "
                << restaurantList.size() << endl;
        for (unsigned int j = 0; j < size(); j++) {
            outFile << j + 1 << " " << restaurantList[i].distanceFrom(j + 1)
                    << endl;
        }
        outFile << restaurantList[i].GetDistanceSB()
                << " miles to Saddleback College" << endl;
        outFile << restaurantList[i].menuList().size()
                << " menu items" << endl;
        for (unsigned int j = 0; j < restaurantList[i].menuList().size(); j++) {
            outFile << GetRestaurant(i).menuItem(j).name().toStdString() << endl;
            outFile << GetRestaurant(i).menuItem(j).price() << endl;
        }
    }
}

/**
 * @brief saveRevenue
 * This method saves to a file the revenue of all of the restaurants.
 */
void RestaurantList::saveRevenue()
{
    // the output file stream to write to
    ofstream outFile;

    // open the file
    outFile.open("SavedRevenue.txt");

    // write to the file the revenue and sales count of the restaurants
    for (unsigned int i = 0; i < size(); i++) {
        outFile << restaurantList.at(i).revenue() << endl;
        outFile << restaurantList.at(i).salesCount() << endl;
    }
}

/**
 * @brief saveWhetherLoadedNewFile
 * Save to a file that the new restaurants were added
 */
void RestaurantList::saveThatLoadedNewFile()
{
    // file to save to
    ofstream outFile;

    // write to file true
    outFile.open("SaveDataMisc.txt");
    outFile << "true";

    // cloes the file
    outFile.close();
}
