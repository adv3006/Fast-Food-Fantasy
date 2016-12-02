#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include <QDialog>
#include <QtWidgets> // adding new widgets in code rather than ui tool
#include "mainwindow.h"
#include "restaurantlist.h"
#include <queue>
#include "shoppingmenu.h"

namespace Ui {
class CustomTrip;
}

/*************************************************************************
 * Class CustomTrip
 * This is a window where a custom trip can be chosen: specific restaurants
 * can be chosen to go to on a trip.
 *************************************************************************/
class CustomTrip : public QDialog
{
    Q_OBJECT

public:
    /*************************************************************************
    * Constructors & Destructors
    *************************************************************************/
    /**
     * @brief CustomTrip
     * This is the constructor for the custom trip. It places widgets for the
     * appearance and function of the window, including connecting slots to the
     * dynamically made widgets.
     * @param rlist the pointer to the restaurant list
     * @param parent the parent window
     */
    explicit CustomTrip(QVector<Restaurant> rlist,bool all, QWidget *parent = 0);

    /**
     * @brief ~CustomTrip
     * This is the destructor for custom trip, it deletes the ui
     */
    ~CustomTrip();

private:
    Ui::CustomTrip     *ui;             ///< pointer to gui
    QList<QCheckBox*> checkboxList;     ///< list of checkboxex
    QVector<int>      listOfIndices;    ///< vector of check boxes
    queue<int>        queueOfIndices;   ///< check boxes in order
    RestaurantList    resList;          ///< list of restaurants
    QLabel            *errorMessage;    ///< error message
    QPalette          invalidPalette;   ///< invalid pallete


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
     * This method is performed when the confirm button is clicked, it will record
     * which checkboxes were clicked for the restaurants and bring up a shopping menu
     * of the restaurants for the trip
     */
    void onConfirmButtonClick(bool);

    /**
     * @brief onSelectAllClicked
     * -checks if all of the check boxes are clicked
     */
    void onSelectAllClicked(bool);
};

#endif // CUSTOMTRIP_H
