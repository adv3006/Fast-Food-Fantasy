#ifndef SHORTESTTRIP_H
#define SHORTESTTRIP_H

#include <QDialog>
#include <QtWidgets> // adding new widgets in code rather than ui tool
#include "restaurantlist.h"
#include <queue>
#include "shoppingmenu.h"
#include <QDebug>

namespace Ui {
class ShortestTrip;
}

/*************************************************************************
 * Class ShortestTrip
 * This class is the window of the shortest trip which allows you to
 * choose the starting restaurant and total number of restaurants to visit
 * in the most efficient order.
 *************************************************************************/
class ShortestTrip : public QDialog
{
    Q_OBJECT

public:
    /*************************************************************************
    * Constructors & Destructors
    *************************************************************************/
    /**
     * @brief ShortestTrip
     * This is the constructor for the shortest trip window which allows you to
     * choose the starting restaurant and total number of restaurants to visit in
     * the most efficient order.
     * @param rlist pointer to the restaurant list
     * @param parent the parent window
     */
    explicit ShortestTrip(QVector<Restaurant> rlist, QWidget *parent = 0);

    /**
     * @brief ~ShortestTrip
     * This is the destructor which deletes the ui
     */
    ~ShortestTrip();

private:
    Ui::ShortestTrip    *ui;                ///< pointer to gui
    QList<QRadioButton*> radioButtonList;   ///< list of checked buttons
    RestaurantList       resList;           ///< list of restaurants
    QSpinBox             *restaurantMax;    ///< number in spin box
private slots:
    /*************************************************************************
    * Slots
    *************************************************************************/
    /**
     * @brief onCancelButtonClick
     * This method is performed when the cancel button is clicked. It closes the
     * window.
     */
    void onCancelButtonClick(bool);

    /**
     * @brief onConfirmButtonClick
     * This method is performed when the confirm button is clicked. The
     * trip/shopping menu is brought up with the starting restaurants and the
     * closest restaurants (of a number specified by the user in the spinner box)
     * to it.
     */
    void onConfirmButtonClick(bool);

    /**
     * @brief onSelectAllButtonClick
     * This method selects the total amount of restaurants in the spinner box,
     * so the user can visit all of the restaurants.
     */
    void onSelectAllButtonClick(bool);
};

#endif // SHORTESTTRIP_H
