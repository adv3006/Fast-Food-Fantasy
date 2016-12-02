#include "addmenuwindow.h"
#include "ui_addmenuwindow.h"
#include "database.h"

/**
 * @brief AddMenuWindow::AddMenuWindow
 * @param parent
 */
AddMenuWindow::AddMenuWindow(database db, Restaurant res, int i, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMenuWindow)
{
    ui->setupUi(this);
    QDoubleValidator *priceVal = new QDoubleValidator(0,999,2,this);
    ui->priceEdit->setValidator(priceVal);
    this->db = db;
    rest     = res;
    index    = i;

    if(index == 2)
    {
        ui->label_3->setText("Change Menu Item Price");
        ui->nameEdit->hide();
        ui->label->hide();
    }
    else
    {
        ui->ItemName_Label->hide();
    }
}

/**
 * @brief AddMenuWindow::~AddMenuWindow
 */
AddMenuWindow::~AddMenuWindow()
{
    delete ui;
}

/**
 * @brief AddMenuWindow::on_buttonBox_accepted
 */
void AddMenuWindow::on_buttonBox_accepted()
{
    //PROCESSING - if index passed into constructor is 1, user is trying to add a menu item to an existing restaurant
    //              so window checks database for existing menu item
    if(index == 0)
    {
        /*************************************************************
         * PROCESSING-
         *  -Gets input from user for name and price of menu item
         *  -Emits signal that the button was accepted
         *************************************************************/
        name  = ui->nameEdit->text();
        price = ui->priceEdit->text().toDouble();

        //PROCESSING - checks database for name user entered
        if(db.CheckMenuItem(name))
        {
            //PROCESSING - if name exits, opens error message telling user the problem
            QMessageBox::information(this, tr("Item Exits"), "Item already in menu! Please Enter a new Menu Item");
        }
        else
        {
            //PROCESSING - checks if all fields are entered, opens message box showing error
            if(name == "" || price == 0)
            {
                QMessageBox::information(this, tr("Missing input"), "Please enter all item information");
            }
            //PROCESSING - sends signals if user input is valid
            else
            {
                emit MenuItem(name, price);
                emit OKClicked();
                emit OKClicked(name,price);
                hide();
            }//END -if imputs are blank

        }//END - if name exits
    }
    else if(index == 1)
    {
        /*************************************************************
         * PROCESSING-
         *  -Gets input from user for name and price of menu item
         *  -Emits signal that the button was accepted
         *************************************************************/
        name  = ui->nameEdit->text();
        price = ui->priceEdit->text().toDouble();
        bool found = false; //CALC - determines if name was found

        //PROCESSING - loops through restaurants items and determines if item entered alresady exits
        for(int i = 0; i < rest.GetItems().size(); i++)
        {
            //PROCESSING - sets found to true if name exits
            if(rest.GetItems().at(i) == name)
            {
                found = true;
            }//IF - name exists
        }//For - each name in restautant

        //PROCESSING - if found is true, error box opens with error message
        if(found)
        {
            QMessageBox::information(this,tr("Item Exits"),
                         "Item already in menu! Please enter a new menu item.");
        }
        //PROCESSING - if fields are empty, error box opens asking user to enter all fields
        else if(name == "" || price == 0)
        {
            QMessageBox::information(this, tr("Missing input"), "Please enter all item information");
        }
        //PROCESSING - adds menu item and sends signal input was ok
        else
        {
            emit MenuItem(name, price);
            emit OKClicked();
            emit OKClicked(name,price);
            hide();
        }//Else - name doesnt exist
    }//Else - index == 1
    else
    {
        price = ui->priceEdit->text().toDouble();
        if(price == 0)
        {
            QMessageBox::information(this, tr("Missing input"), "Please enter all item information");
        }
        else
        {
            emit PriceChange(price);
            hide();
        }
    }
}

/**
 * @brief AddMenuWindow::on_buttonBox_destroyed
 */
void AddMenuWindow::on_buttonBox_destroyed()
{
    hide();
}
