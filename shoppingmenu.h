#ifndef SHOPPINGMENU_H
#define SHOPPINGMENU_H

#include <QDialog>
#include <queue>
#include <QSpinBox>
#include <QMenu>
#include <QAction>
#include "changeintvalue.h"
#include "shoppingsummarywindow.h"

namespace Ui {
class shoppingMenu;
}

class shoppingMenu : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief shoppingMenu
     * @param sortedRestaurantIndexes the index of restaurants in order of visting priority
     * @param masterList the master restaurant list
     * @param parent the parent window
     */
    explicit shoppingMenu(queue<int> sortedRestaurantIndexes,
                          RestaurantList masterList, QWidget *parent = 0);

    /**
     * @brief shoppingMenu Destructor
     */
    ~shoppingMenu();
    /**
     * @brief buildRestaurantSelectionWindow
     */
    void buildRestaurantSelectionWindow();
    /**
     * @brief buildMenuSelectionList
     * @param selectedIndex the index (from masterList) of the restaurant list
     */
    void buildMenuSelectionList(int selectedIndex);
    /**
     * @brief addToCart
     * @param currentIndex the current index from the restaurant list
     */
    void addToCart(int currentIndex);
    /**
     * @brief startSelectingItems
     * @param i index of the restaurant from the restaurant list
     */
    void startSelectingItems(int i);
    /**
     * @brief selectLogo
     * @param idx the index of the restaurant from the restaurant list
     * @return a pixmap from the logo path of the restaurant object
     */
    QPixmap selectLogo(int idx);
    /**
     * @brief buildChoicesFromCart
     * @return  a vector of restaurantChoices built from the QT Tree widget cart
     */
    QVector<restaurantChoices*> buildChoicesFromCart();

private slots:
    /** SLOT
     * @brief on_buttonBox_accepted
     */
    void on_buttonBox_accepted();
    void on_next_clicked();
    /** SLOT
     * @brief on_prev_clicked
     */
    void on_prev_clicked();
    /** SLOT
     * @brief on_addToCart_clicked
     */
    void on_addToCart_clicked();
    /** SLOT
     * @brief modifyCartItem
     */
    void modifyCartItem(QAction*);
    /** SLOT
     * @brief on_cart_customContextMenuRequested
     * @param pos position of the right click on the UI
     */
    void on_cart_customContextMenuRequested(const QPoint &pos);
    /** SLOT
     * @brief on_okay_cancel_accepted
     */
    void on_okay_cancel_accepted();

private:
    Ui::shoppingMenu   *ui;                   ///< The ui window pointer
    RestaurantList     selectedRestaurants;   ///< The selected restaurants object
    RestaurantList     masterRestaurantList;  ///< The Master restaurant object
    unsigned int       idxCounter;            ///< the idx counter iterates through selectedRestaurants
    restaurantChoices* choices;               ///< A restaurant choices pointer
    double             totalDistance;         ///< The totalDistance traveled accumulator
    QVector<QString>   visitHistory;          ///<  vector of QString visitHistory
};

#endif // SHOPPINGMENU_H
