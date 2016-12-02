#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->confirmDeleteLabel->hide();
    ui->confirmDeleteButton->hide();
    ui->confirmDeleteButton_2->hide();
    ui->confirmDeleteLabel_2->hide();
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::GetMenu
 * sets menu from parameters passed in
 * @param item
 * @param price
 */
void MainWindow::GetMenu(QString item, float price)
{
    toAdd.SetMenu(item, price);
}

/**
 * @brief MainWindow::on_pushButton_clicked
 * Next button on first stacked widget page to go to next page
 */
void MainWindow::on_pushButton_clicked()
{
    //PROCESSING - sets index of stacked widget to 1
   ui->stackedWidget->setCurrentIndex(1);
}

/**
 * @brief MainWindow::on_pushButton_2_clicked
 * Back button that goes back one stacked widget page
 */
void MainWindow::on_pushButton_2_clicked()
{
     //PROCESSING - sets index of stacked widget to 0
    ui->stackedWidget->setCurrentIndex(0);
}

/**
 * @brief MainWindow::on_pushButton_7_clicked
 * Administrator login button.
 *  -prompts user to enter password.
 *  -if password is correct, sets page index to admin page
 *  -fills combo box to store all restaurants
 */
void MainWindow::on_pushButton_7_clicked()
{
    SecDialog secdialog;    //Dialog box

    //PROCESSING - opends dialog box that asks user to ender password
    secdialog.setModal(true);
    secdialog.exec();
    QString myPass;
    myPass = "password";

    //PROCESSING - if password is correct, sets index to admin page and
    //                  fills combo box
    if(secdialog.isVisible() == false && secdialog.get_text() == myPass)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->stackedWidget->hide();
        ui->stackedWidget->show();

        //PROCESSING - clears table so its ready to be filled
        ClearTable(ui->Menu_Table);

        //PROCESSING - gets list of all restaurants and fills combo box
        QVector<Restaurant> allRes = db.AllRestaurantInfo();
        for(int i = 0; i < allRes.size(); i++)
        {
            ui->comboBox->insertItem(i, allRes[i].GetName());
        }
    }
}
/**
 * @brief MainWindow::on_pushButton_6_clicked
 * Initial list button
 *      - opens new window with will promput user where to confirm
 *          that they want to go to all of the restaurants in the
 *          database
 */
void MainWindow::on_pushButton_6_clicked()
{
    QVector<Restaurant> listRestaurants;    //CALC - list of restaurants

    //PROCESSING - stores all restaurant info to vector of restaurants
    listRestaurants = db.AllRestaurantInfo();

    //PROCESSING - opends custom trip windo
    CustomTrip ctrip(listRestaurants, true);
    ctrip.exec();
}

/**
 * @brief MainWindow::on_AddRestaurant_Button_clicked
 * Add restaurant button
 *  - sets index to page that will take user input to add restaurant
 *      to the database
 */
void MainWindow::on_AddRestaurant_Button_clicked()
{
    //PROCESSING - sets index to zero and stacked page widget to 3
    index = 0;
    ui->stackedWidget->setCurrentIndex(3);

    //PROCESSING - gets all restaurant names and stores them to a vector
    QVector<QString> list = db.GetRestaurantsName();

    //PROCESSING - sets validators from distance and number inputs
    QDoubleValidator *distance = new QDoubleValidator(0,999,2,this);
    QIntValidator *number = new QIntValidator(0,10000,this);
    ui->Number_Edit->setValidator(number);
    ui->distance_edit->setValidator(distance);
    ui->Distance_Edit->setValidator(distance);

    //PROCESSING - sets lable to restaurant, clears distance edit,
    //              and increments index
    ui->name_label->setText(list[index]);
    ui->distance_edit->clear();
    index++;
}

/**
 * @brief MainWindow::on_AddMenu_Button_clicked
 * adds the menu item from the menu window to
 * the restaurant
 */
void MainWindow::on_AddMenu_Button_clicked()
{
    //PROCESSING - opens menu window and connects signal of item name and price
    //              entered and sets menu items
    menuWindow = new AddMenuWindow(db, toAdd, 0);

    connect(menuWindow, SIGNAL(MenuItem(QString,float)),
            this, SLOT(AddMenuToCurrentRest(QString,float)));
    menuWindow->show();
}


/**
 * @brief MainWindow::on_buttonBox_accepted
 * adds the restaurant when the user enters
 * in forrect information
 */
void MainWindow::on_buttonBox_accepted()
{
    QString name;   //CALC - restaurant name
    int     num;    //CALC - restuarnat num
    float   distSB; //CALC - restaurant distance from saddleback
    QVector<QString> list = db.GetRestaurantsName();

    //PROCESSING - stores user input into varibales
    name   = ui->Name_Edit->text();
    num    = ui->Number_Edit->text().toInt(0);
    distSB = ui->Distance_Edit->text().toFloat(0);

    /************************************************************
     * Checks if all Fields have entries
     *      - opens window with corresponding error
     *************************************************************/
    if(name.isEmpty() || (num == NULL || distSB == NULL))
    {
        QMessageBox::information(this, tr("Empty Fields"),
                                 "Please enter All Fields");
    }


    /************************************************************
     * Checks if all Distances were entered
     * - opens window with corresponding error
     *************************************************************/
    if(list.size() == toAdd.GetDistances().size())
    {
        /************************************************************
         * Checks if the name and number of the restaurant
         *  entered alredy exist in the database
         *  - opens window with corresponding error
         *************************************************************/
        if(!db.SearchForName(name) && !db.SearchForNumber(num))
        {
            //PROCESSING - sets distanctes to zero, creates new restaurant and
            //                  adds it to the database
           toAdd.SetDistances(0.0);
           Restaurant newRes(name, num, distSB, toAdd.GetDistances(),
                             toAdd.GetItems(), toAdd.GetPrices());
           db.AddRestaurant(newRes);

           //qDebug() << "name -" <<  name;
           //qDebug() << "num - " << num;
           //qDebug() << "distance - " <<distSB;
           //for(int i = 0; i < toAdd.GetPrices().size(); i++)
           //{
               //qDebug() << toAdd.GetItems().at(i);
               //qDebug() << toAdd.GetPrices().at(i);
           //}//end -for

           //PROCESSING - resets current index to admin page
           ui->stackedWidget->setCurrentIndex(2);
        }
        //PROCESSING - checks if name already exists in database. If so,
        //              opens message box and asks user to enter new name
        else if(db.SearchForName(name) && !db.SearchForNumber(num))
        {
            QMessageBox::information(this, tr("Name Already Exists"),
                                     "Please enter a new name");
        }
        //PROCESSING - checks if number already exists in database. If so,
        //              opens message box and asks user to enter new number
        else if(!db.SearchForName(name) && db.SearchForNumber(num))
        {
            QMessageBox::information(this, tr("Number Already Exists"),
                                     "Please enter a new number");
        }
        //PROCESSING - checks if name and num already exists in database. If so,
        //            opens message box and asks user to enter new name and num
        else
        {
            QMessageBox::information(this, tr("Name and Number Already Exist"),
                                     "Please enter a new name and number");
        }
    }
    //PROCESSING - if user didnt enter all distances, opens message box and
    //              asks user to enter distances
    else
    {
        QMessageBox::information(this, tr("Distances Missing"),
                                 "Please enter all distances");
    }

    //PROCESSING - clears all line edits and combo box
    ui->Name_Edit->clear();
    ui->Number_Edit->clear();
    ui->Distance_Edit->clear();
    ui->comboBox->clear();

    //PROCESSING - refills combobox with updated restaurants
    QVector<Restaurant> allRes = db.AllRestaurantInfo();
    for(int i = 0; i < allRes.size(); i++)
    {
        ui->comboBox->insertItem(i, allRes[i].GetName());
    }

    ClearTable(ui->Menu_Table_2);
}

/**
 * @brief MainWindow::on_AddItem_Button_clicked
 *  Gets the new menu items from the menu item
 *  window and sets them to the restaurants menu
 */
void MainWindow::on_AddItem_Button_clicked()
{
    //PROCESSING - opens menu window and adds them to new restaurant
    menuWindow = new AddMenuWindow(db, toAdd, 1);
    connect(menuWindow, SIGNAL(MenuItem(QString,float )),
            this, SLOT(GetMenu(QString, float)));
    connect(menuWindow, SIGNAL(OKClicked()), this, SLOT(RefreshMenu2Table()));
    menuWindow->show();
}

/**
 * @brief MainWindow::on_nextRestaurant_Button_clicked
 * - changes restaurnt lable for distances to next restaurant in database
 * - stores value in distance edit to res variable
 */
void MainWindow::on_nextRestaurant_Button_clicked()
{
    //PROCESSING - stores list of restaurant names and sets validators
    QVector<QString> list = db.GetRestaurantsName();
    QDoubleValidator *valid = new QDoubleValidator(0.0,1000.0,2,this);
    ui->distance_edit->setValidator(valid);

    float dist; //CALC - distance from one restaurant to the other

    if(ui->distance_edit->text() == "")
    {
        QMessageBox::information(0, "Information", "Please Enter a distance!");
    }
    else
    {
        //PROCESSING - if index is less then size, sets restaurant lable to next
        //              restaurant
        if(index < list.size())
        {
            //PROCESSING - sets label to restaurant for distance to be added
            ui->name_label->setText(list[index]);
            if(index > 0)
            {
                dist = ui->distance_edit->text().toFloat();
                toAdd.SetDistances(dist);
                //qDebug() << ui->distance_edit->text().toFloat();
            }
        }
        //PROCESSING - stores distance of last restaurant
        else if(index == list.size())
        {
            dist = ui->distance_edit->text().toFloat();
            toAdd.SetDistances(dist);
            //qDebug() << ui->distance_edit->text().toFloat();
        }

        //PROCESSING - increments index and clears distance edit
        index++;
    }

    ui->distance_edit->clear();
}

/**
 * @brief MainWindow::on_buttonBox_rejected
 * resets index of stacked widget if user cancels adding a new restaurant
 */
void MainWindow::on_buttonBox_rejected()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->Name_Edit->clear();
    ui->Number_Edit->clear();
    ui->Distance_Edit->clear();

    ClearTable(ui->Menu_Table_2);
}

/**
 * @brief MainWindow::on_pushButton_9_clicked
 * After user sees all list of all restaurants, sets the index back to options
 * user can do for program
 */
void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/**
 * @brief MainWindow::on_ViewAll_Buton_clicked
 * sets current index to the page with a table of all restaurants and distances
 * from saddleback
 * - sets table
 */
void MainWindow::on_ViewAll_Buton_clicked()
{
    //PROCESSING - sets current index to page with table of restaurants
    ui->stackedWidget->setCurrentIndex(4);

    QVector<QString> names;     //CALC - name of restaurants
    QVector<float>   distanceSB;//CALC - distances from saddleback for res.

    //PROCESSING - sets vectors of names and distances from saddleback
    db.GetAllRestaurants(names, distanceSB);

    //PROCESSING - clears table before new info is added
    int rowCount = ui->tableWidget->rowCount();
    for(int i = 0; i < rowCount; i++)
    {
        ui->tableWidget->removeRow(0);
    }
    int colCount = ui->tableWidget->columnCount();
    for(int i = 0; i < colCount; i++)
    {
        ui->tableWidget->removeColumn(0);
    }

    //ADDS COLUMNS TO TABLE
    ui->tableWidget->insertColumn(0);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Distance from Saddleback"));

    //ADDS NAME AND DISTANCES TO TABLE
    for(int i = 0; i < names.size();i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(names[i]));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(distanceSB[i],'f',2)));
    }

    //PROCESSING - resizes table to fill box
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}

/**
 * @brief MainWindow::RefreshMenu2Table
 * adds menu items and prices to menu 2 table
 */
void MainWindow::RefreshMenu2Table()
{
    //CLEARS TABLE
    int rowCount = ui->Menu_Table_2->rowCount();
    for(int i = 0; i < rowCount; i++)
    {
        ui->Menu_Table_2->removeRow(0);
    }

    //ADDS MENU ITEMS
    for(int i = 0; i < toAdd.GetItems().size(); i++)
    {
        ui->Menu_Table_2->insertRow(i);
        ui->Menu_Table_2->setItem(i, 0, new QTableWidgetItem(toAdd.GetItems()[i]));
        ui->Menu_Table_2->setItem(i, 1, new QTableWidgetItem(QString::number(toAdd.GetPrices()[i])));
    }
    ui->Menu_Table_2->resizeColumnsToContents();
    ui->Menu_Table_2->horizontalHeader()->setStretchLastSection(true);
}

/**
 * @brief MainWindow::on_pushButton_8_clicked
 *  reads from the file and adds restaurants to
 *  the database
 */
void MainWindow::on_pushButton_8_clicked()
{
    //QMessageBox::information(this, tr("Text File"), "Enter name of Text File");
    /************************************************
                                                             / Temporarily no text input for file, but can be
                                                             / changed easily by changing the path to:
                                                             /
                                                             /
                                                             / "C:\\Users\\yourName\\Desktop\\EagleEye-master\\"<File name Variable>".txt"
                                                             /
                                                             / or whichever respective repository we choose to pull from
                                                             /*************************************************/
        QString nameInput;
        int     numInput;
        int numItems;
        int index2; //For some reason, I cannot reiterate index in second loop, so had to make a second index.
        QString myMenuItem;
        float myPrice;
        float   distInput;
        float distFrom;
        float distFromSaddle;
        QVector<QString> listInput; /*= db.GetRestaurantsName();*/
        QVector<float> distancesInput;
        QVector<QString> namesInput;
        QVector<float> pricesInput;


        QFile file("C:\\Users\\ahernandez109\\Desktop\\input.txt"); //Whatever our filename is
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            while (!in.atEnd())
            {
                nameInput = in.readLine();
                nameInput = nameInput.split(": ")[1];

                qDebug() << nameInput << endl;//For testing

                numInput = in.readLine().split(" ")[4].toInt();
               qDebug() << numInput << endl;
                distInput = in.readLine().split("- ")[1].toFloat();
                qDebug() << distInput << endl;

                for(int index = 0; index < distInput; index++)
                {
                    distFrom = in.readLine().split(" ")[1].toDouble();
                    distancesInput.push_back(distFrom);

                   qDebug() << index << " distance from: " << distFrom << endl;

                }
                distFromSaddle = in.readLine().split(" ")[0].toFloat();
                qDebug() << distFromSaddle << endl;
                numItems = in.readLine().split(" ")[0].toInt();
                qDebug() << numItems << endl;
                for(index2 = 0; index2 < numItems; index2++)
                {
                    myMenuItem = in.readLine();
                    qDebug() << index2 << " Menu item: " << myMenuItem << endl;
                    namesInput.push_back(myMenuItem);
                    myPrice = in.readLine().toFloat();
                    qDebug() << index2 << " Price: " << myPrice << endl;
                    pricesInput.push_back(myPrice);
                }
                in.readLine();
                in.readLine();
                if(!db.SearchForName(nameInput))
                {
                    Restaurant myRes(nameInput, numInput, distFromSaddle, distancesInput, namesInput, pricesInput);
                    db.AddRestaurant(myRes);
                    QMessageBox::information(0, "Information", "Restaurants Added");
                }
                else
                {
                    QMessageBox::information(0, "Information", "Restaurants Already in System!");
                }
                distancesInput.clear();
                namesInput.clear();
                pricesInput.clear();
              }

        }
        else
        {
            QMessageBox::information(0, "Information", file.errorString());
        }
    }

/**
 * @brief MainWindow::on_ChoiceNumber_Button_clicked
 * Opens shortest trip menu where user can pick a starting restaurant and
 * input a number with will let them visit that many restaurants after their
 * starting restaurant
 */
void MainWindow::on_ChoiceNumber_Button_clicked()
{
    QVector<Restaurant> listRestaurants;    //CALC - vector of all restaurants

    //PROCESSING - stores all restaurants from database into vector
    listRestaurants = db.AllRestaurantInfo();

    //PROCESSING - opens shortest trip window and passes in vector of all
    //              restaurants
    ShortestTrip ShortTrip(db.AllRestaurantInfo());
    ShortTrip.exec();
}

/**
 * @brief MainWindow::on_CustomList_Button_clicked
 * Opends custom trip window which lets users pick what restaurants they
 * want to go to
 */
void MainWindow::on_CustomList_Button_clicked()
{
    QVector<Restaurant> listRestaurants; //CALC - vector of all restaurants

    //PROCESSING - stores all restaurants from database into vector
    listRestaurants = db.AllRestaurantInfo();

    //PROCESSING - opens custom trip window and passes in vector of all
    //              restaurants
    CustomTrip ctrip(listRestaurants, false);
    ctrip.exec();
}

/**
 * @brief MainWindow::ClearTable
 * @param table
 * clears table passed in
 */
void MainWindow::ClearTable(QTableWidget *table)
{
    int row = table->rowCount();    //Gets row count from table passed in

    //PROCESSING - removes first row until there are no more rows to remove
    for(int i = 0; i < row; i++)
    {
        table->removeRow(0);
    }
}

/**
 * @brief MainWindow::on_comboBox_currentIndexChanged
 * @param index
 * When user picks a new cell in combo box, resets the text box and menu item
 * with users choice
 */
void MainWindow::on_comboBox_currentIndexChanged(int index)
{

    QString    name = ui->comboBox->itemText(index); //CALC - name of current
                                                     // cell of combo box
    Restaurant res  = db.GetRestaurant(name);        //CALC - restaurant info

    comboBoxIndex = index;
    //PROCESSING - clears table and text box
    ClearTable(ui->Menu_Table);
    ui->Restauraunt_Info->clear();

    //PROCESSING - adds restaurant name, number, and distance from saddleback
    //              into text box
    ui->Restauraunt_Info->append(name);
    ui->Restauraunt_Info->append("Restaurant Number: " + QString::number(res.GetNum()));
    ui->Restauraunt_Info->append("Distance From Saddleback College: " + QString::number(res.GetDistanceSB()));

    //PROCESSING - fills menu table with restaurants menu
    for(int i = 0; i < res.GetItems().size(); i++)
    {
        ui->Menu_Table->insertRow(i);
        ui->Menu_Table->setItem(i,0,new QTableWidgetItem(res.GetItems()[i]));
        ui->Menu_Table->setItem(i,1,new QTableWidgetItem(QString::number(res.GetPrices()[i])));
    }

    //PROCESSING - resizes table to fit area
    ui->Menu_Table->resizeColumnsToContents();
    ui->Menu_Table->horizontalHeader()->setStretchLastSection(true);
}

/**
 * @brief MainWindow::on_pushButton_4_clicked
 * Logout button
 *  - resets current index to first page
 */
void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox->clear();
}

/**
 * @brief MainWindow::AddMenuToCurrentRest
 * - adds Menu to current restaurant
 * @param item
 * @param price
 */
void MainWindow::AddMenuToCurrentRest(QString item, float price)
{
    bool done;  //CALC - determines if database successfully updated

    //PROCESSING - adds menu to selected restaurant and returns if was successful
    done = db.AddMenuItem(item,price,ui->comboBox->itemText(comboBoxIndex));

    //PROCESSING - if adding database was successful, updates menu table
    if(done)
    {
        //PROCESSING - clears table and gets updated restaurant information
        ClearTable(ui->Menu_Table);
        Restaurant res = db.GetRestaurant(ui->comboBox->itemText(comboBoxIndex));

        //PROCESSING - updates menu table
        for(int i = 0; i < res.GetItems().size(); i++)
        {
            ui->Menu_Table->insertRow(i);
            ui->Menu_Table->setItem(i,0,new QTableWidgetItem(res.GetItems()[i]));
            ui->Menu_Table->setItem(i,1,new QTableWidgetItem(QString::number(res.GetPrices()[i])));

            ui->Menu_Table->resizeColumnsToContents();
            ui->Menu_Table->horizontalHeader()->setStretchLastSection(true);
        }
    }
}

/**
 * @brief MainWindow::on_Menu_Table_cellClicked
 * -saves what item was clicked in the menu table
 * @param row
 * @param column
 */
void MainWindow::on_Menu_Table_cellClicked(int row, int column)
{
    itemToDelete = ui->Menu_Table->item(row,0)->text();
    ui->confirmDeleteLabel->setText("Are you sure you want to delete " + itemToDelete + "?");
}

/**
 * @brief MainWindow::on_deleteItem_Button_clicked
 * shows confirm message and button
 */
void MainWindow::on_deleteItem_Button_clicked()
{
    ui->confirmDeleteButton->show();
    ui->confirmDeleteLabel->show();
}

/**
 * @brief MainWindow::on_confirmDeleteButton_accepted
 * calls delete item functiona and hides confirm delete label
 * and button
 */
void MainWindow::on_confirmDeleteButton_accepted()
{
    DeleteMenuItem(itemToDelete);
    ui->confirmDeleteButton->hide();
    ui->confirmDeleteLabel->hide();
}

/**
 * @brief MainWindow::DeleteMenuItem
 * - deletes menu item from table
 * @param itemName
 */
void MainWindow::DeleteMenuItem(QString itemName)
{
    bool success;   //CALC - determines if item sucessfully deleted

    //PROCESSING- deletes menu item if sucessful
    success = db.DelteMenuItem(itemName, ui->comboBox->itemText(comboBoxIndex));

    //PROCESSING - if sucessful, clears the table and resets it with the updated
    //menu items
    if(success)
    {
        ClearTable(ui->Menu_Table);
        Restaurant res = db.GetRestaurant(ui->comboBox->itemText(comboBoxIndex));

        //PROCESSING - updates menu table
        for(int i = 0; i < res.GetItems().size(); i++)
        {
            ui->Menu_Table->insertRow(i);
            ui->Menu_Table->setItem(i,0,new QTableWidgetItem(res.GetItems()[i]));
            ui->Menu_Table->setItem(i,1,new QTableWidgetItem(QString::number(res.GetPrices()[i])));

            ui->Menu_Table->resizeColumnsToContents();
            ui->Menu_Table->horizontalHeader()->setStretchLastSection(true);
        }
    }

}

/**
 * @brief MainWindow::on_confirmDeleteButton_rejected
 * hides the confirm delete button and label if user does not wish to delte
 * menu item anymore
 */
void MainWindow::on_confirmDeleteButton_rejected()
{
    ui->confirmDeleteButton->hide();
    ui->confirmDeleteLabel->hide();
}

/**
 * @brief MainWindow::on_Menu_Table_2_cellClicked
 * - stores the name of the menu item clicked in the table
 * @param row
 * @param column
 */
void MainWindow::on_Menu_Table_2_cellClicked(int row, int column)
{
    itemToDelete = ui->Menu_Table_2->item(row,0)->text();
    qDebug() << itemToDelete;
    ui->confirmDeleteLabel_2->setText("Are you sure you want to delete " + itemToDelete + "?");
}

/**
 * @brief MainWindow::on_DeleteItem2_Button_clicked
 * - shows the confirm delete menu item label and button
 */
void MainWindow::on_DeleteItem2_Button_clicked()
{
    ui->confirmDeleteButton_2->show();
    ui->confirmDeleteLabel_2->show();
}

/**
 * @brief MainWindow::on_confirmDeleteButton_2_accepted
 * - Searches for menu item in restaurant variable
 * - once its found, it deletes it from the list
 * - then clears the table and refreshes it with the updated list
 */
void MainWindow::on_confirmDeleteButton_2_accepted()
{
    //PROCESSING - searches for item to delete then deltes it
    for(int i = 0; i < toAdd.GetItems().size(); i++)
    {
        if(toAdd.GetItems()[i] == itemToDelete)
        {
            toAdd.RemoveMenuItem(i);
        }
    }

    //PROCESSING - clears table
    ClearTable(ui->Menu_Table_2);

    //PROCESSING - updates menu table
    for(int i = 0; i < toAdd.GetItems().size(); i++)
    {
        ui->Menu_Table_2->insertRow(i);
        ui->Menu_Table_2->setItem(i,0,new QTableWidgetItem(toAdd.GetItems()[i]));
        ui->Menu_Table_2->setItem(i,1,new QTableWidgetItem(QString::number(toAdd.GetPrices()[i])));

        ui->Menu_Table_2->resizeColumnsToContents();
        ui->Menu_Table_2->horizontalHeader()->setStretchLastSection(true);
    }

    //PROCESSING - hides confirm delete label and button
    ui->confirmDeleteButton_2->hide();
    ui->confirmDeleteLabel_2->hide();
}

/**
 * @brief MainWindow::on_confirmDeleteButton_2_rejected
 * - Hides confirm delete label and button
 */
void MainWindow::on_confirmDeleteButton_2_rejected()
{
    ui->confirmDeleteButton_2->hide();
    ui->confirmDeleteLabel_2->hide();
}

/**
 * @brief MainWindow::ChangeItemPrice
 * changes menu item from database and updates table
 * @param newPrice
 */
void MainWindow::ChangeItemPrice(float newPrice)
{
    //PROCESSING - changes menu item price in database
    if(db.ChangePrice(itemToDelete, newPrice))
    {
        //PRICESSING - clears table and gets restaurant info
        ClearTable(ui->Menu_Table);
        Restaurant res = db.GetRestaurant(ui->comboBox->itemText(comboBoxIndex));

        //PROCESSING - updates menu table
        for(int i = 0; i < res.GetItems().size(); i++)
        {
            ui->Menu_Table->insertRow(i);
            ui->Menu_Table->setItem(i,0,new QTableWidgetItem(res.GetItems()[i]));
            ui->Menu_Table->setItem(i,1,new QTableWidgetItem(QString::number(res.GetPrices()[i])));

            ui->Menu_Table->resizeColumnsToContents();
            ui->Menu_Table->horizontalHeader()->setStretchLastSection(true);
        }//END - refill table
    }//END - if - price changed
}


/**
 * @brief MainWindow::on_ChangePrice_B_clicked
 * When button is clicked, opens add menu item window and shows the window
 */
void MainWindow::on_ChangePrice_B_clicked()
{
    menuWindow = new AddMenuWindow(db,toAdd,2);

    connect (menuWindow, SIGNAL(PriceChange(float)),
             this, SLOT(ChangeItemPrice(float)));
    menuWindow->show();
}
