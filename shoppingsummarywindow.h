#ifndef SHOPPINGSUMMARYWINDOW_H
#define SHOPPINGSUMMARYWINDOW_H

#include <QDialog>
#include <QTreeWidget>
#include <vector>
#include "restaurantlist.h"

/**
 * @brief The purchase struct
 */
struct purchase{
    QString itemName;   ///< the item name of the purchase
    double price;       ///< the price fo the purchase
    int quantity;       ///< the quantity of items bought
};

/**
 * @brief The total struct
 */
struct total{
    QString restaurantName; ///< The name of the restaurant
    double  revenue;        ///< The revene generated at that restaurant
    int     purchaseCount;  ///< the count of items bought at this restaurant
};

/**
 * @brief The restaurantChoices struct
 */
struct restaurantChoices{
    QString restaurantName;             ///< the name of the restaurant
    std::vector<purchase*> purchases;   ///< a vector of purchases at that restaurant
};

namespace Ui {
class shoppingSummaryWindow;
}

class shoppingSummaryWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief shoppingSummaryWindow
     * @param choices a vector of restaurntChoices
     * @param masterList the master restaurant list
     * @param distance the total distance traveled
     * @param visitHistory a vector of QStrings representing the restaurants visited
     * @param parent the parent window
     */
    explicit shoppingSummaryWindow(QVector<restaurantChoices*> choices, RestaurantList masterList, double distance,
                                   QVector<QString> visitHistory, QWidget *parent = 0);
    ~shoppingSummaryWindow();

    /**
     * @brief loadCartFromVector
     * @param choices a vector of restaurant choices
     */
    void loadCartFromVector  (QVector<restaurantChoices *> choices);
    /**
     * @brief loadTotalsFromVector
     * @param choices a vector of restaurant choices
     */
    void loadTotalsFromVector(QVector<restaurantChoices*> choices);
    /**
     * @brief makeVectorUnique
     * @param totals the vector to make unique
     * @return a unique vector (grouped together by totals.name)
     */
    QVector<total *> makeVectorUnique(QVector<total *> *totals);
    /**
     * @brief updateMasterListTotals
     * @param totals a vector of totals (total structs)
     */
    void updateMasterListTotals(QVector<total *> *totals);

private:
    Ui::shoppingSummaryWindow *ui;  ///< ui pointer
    RestaurantList masterList;      ///< the masterList pointer
};

#endif // SHOPPINGSUMMARYWINDOW_H
