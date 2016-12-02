#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QApplication>
#include <QPixmap>
#include <QTableWidget>
#include "customtrip.h"
#include "shortesttrip.h"
#include "database.h"
#include "addmenuwindow.h"
#include "secdialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void MenuItemClicked(QString);

private slots:
    /**
     * @brief GetMenu
     * Next button on first stacked widget page to go to next page
     * @param item
     * @param price
     */
    void GetMenu(QString item, float price);

    /**
     * @brief on_pushButton_clicked
     * - sets index of stack widget to page 1
     */
    void on_pushButton_clicked();

    /**
     * @brief on_pushButton_2_clicked
     * Back button that goes back one stacked widget page
     */
    void on_pushButton_2_clicked();

    /**
     * @brief on_pushButton_7_clicked
     * Administrator login button.
     *  -prompts user to enter password.
     *  -if password is correct, sets page index to admin page
     *  -fills combo box to store all restaurants
     */
    void on_pushButton_7_clicked();

    /**
     * @brief on_pushButton_6_clicked
     * Initial list button
     *      - opens new window with will promput user where to confirm
     *          that they want to go to all of the restaurants in the
     *          database
     */
    void on_pushButton_6_clicked();

    /**
     * @brief on_AddRestaurant_Button_clicked
     * Add restaurant button
     *  - sets index to page that will take user input to add restaurant
     *      to the database
     */
    void on_AddRestaurant_Button_clicked();

    /**
     * @brief on_AddMenu_Button_clicked
     * adds the menu item from the menu window to
     * the restaurant
     */
    void on_AddMenu_Button_clicked();

    /**
     * @brief on_buttonBox_accepted
     * @brief MainWindow::on_buttonBox_accepted
     * adds the restaurant when the user enters
     * in forrect information
     */
    void on_buttonBox_accepted();

    /**
     * @brief on_AddItem_Button_clicked
     *  Gets the new menu items from the menu item
     *  window and sets them to the restaurants menu
     */
    void on_AddItem_Button_clicked();

    /**
     * @brief on_nextRestaurant_Button_clicked
     * - changes restaurnt lable for distances to next restaurant in database
     * - stores value in distance edit to res variable
     */
    void on_nextRestaurant_Button_clicked();

    /**
     * @brief on_buttonBox_rejected
     * resets index of stacked widget if user cancels adding a new restaurant
     */
    void on_buttonBox_rejected();

    /**
     * @brief on_pushButton_9_clicked
     * After user sees all list of all restaurants, sets the index back to options
     * user can do for program
     */
    void on_pushButton_9_clicked();

    /**
     * @brief on_ViewAll_Buton_clicked
     * sets current index to the page with a table of all restaurants and distances
     * from saddleback
     * - sets table
     */
    void on_ViewAll_Buton_clicked();

    /**
     * @brief RefreshMenu2Table
     * adds menu items and prices to menu 2 table
     */
    void RefreshMenu2Table();

    /**
     * @brief on_pushButton_8_clicked
     * reads from the file and adds restaurants to
     *  the database
     */
    void on_pushButton_8_clicked();

    /**
     * @brief on_ChoiceNumber_Button_clicked
     *  Opens shortest trip menu where user can pick a starting restaurant and
     * input a number with will let them visit that many restaurants after their
     * starting restaurant
     */
    void on_ChoiceNumber_Button_clicked();

    /**
     * @brief on_CustomList_Button_clicked
     * Opends custom trip window which lets users pick what restaurants they
     * want to go to
     */
    void on_CustomList_Button_clicked();

    /**
     * @brief ClearTable
     * @param table
     * clears table passed in
     */
    void ClearTable(QTableWidget *table);

    /**
     * @brief on_comboBox_currentIndexChanged
     * @param index
     * When user picks a new cell in combo box, resets the text box and menu item
     * with users choice
     */
    void on_comboBox_currentIndexChanged(int index);

    /**
     * @brief on_pushButton_4_clicked
     * Logout button
     *  - resets current index to first page
     */
    void on_pushButton_4_clicked();

    /**
     * @brief AddMenuToCurrentRest
     * - adds Menu to current restaurant
     * @param item
     * @param price
     */
    void AddMenuToCurrentRest(QString item, float price);

    /**
     * @brief on_Menu_Table_cellClicked
     * -saves what item was clicked in the menu table
     * @param row
     * @param column
     */
    void on_Menu_Table_cellClicked(int row, int column);

    /**
     * @brief on_deleteItem_Button_clicked
     * shows confirm message and button
     */
    void on_deleteItem_Button_clicked();

    /**
     * @brief on_confirmDeleteButton_accepted
     * calls delete item functiona and hides confirm delete label
     * and button
     */
    void on_confirmDeleteButton_accepted();

    /**
     * @brief DeleteMenuItem
     * - deletes menu item from table
     * @param itemName
     */
    void DeleteMenuItem(QString itemName);

    /**
     * @brief on_confirmDeleteButton_rejected
     * hides the confirm delete button and label if user does not wish to delte
     * menu item anymore
     */
    void on_confirmDeleteButton_rejected();

    /**
     * @brief on_Menu_Table_2_cellClicked
     * - stores the name of the menu item clicked in the table
     * @param row
     * @param column
     */
    void on_Menu_Table_2_cellClicked(int row, int column);

    /**
     * @brief on_DeleteItem2_Button_clicked
     * - shows the confirm delete menu item label and button
     */
    void on_DeleteItem2_Button_clicked();

    /**
     * @brief on_confirmDeleteButton_2_accepted
     * - Searches for menu item in restaurant variable
     * - once its found, it deletes it from the list
     * - then clears the table and refreshes it with the updated list
     */
    void on_confirmDeleteButton_2_accepted();

    /**
     * @brief on_confirmDeleteButton_2_rejected
     * - Hides confirm delete label and button
     */
    void on_confirmDeleteButton_2_rejected();

    /**
     * @brief ChangeItemPrice
     * - changes item menu price with price passed in
     * @param newPrice
     */
    void ChangeItemPrice(float newPrice);

    /**
     * @brief on_ChangePrice_B_clicked
     * - opends addmenuWindow to change item price
     */
    void on_ChangePrice_B_clicked();

private:
    Ui::MainWindow *ui;          ///< pointer to gui
    database       db;           ///< connection to database
    AddMenuWindow  *menuWindow;  ///< menu window
    Restaurant     toAdd;        ///< restaurant to add
    int            index;        ///< index of restaurant list
    int            comboBoxIndex;///< current index of combo box
    QString        itemToDelete; ///< menu item to delete
};

#endif // MAINWINDOW_H
