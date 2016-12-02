#include "shoppingsummarywindow.h"
#include "ui_shoppingsummarywindow.h"

/** shoppingSummaryWindow Constructor
 * @brief shoppingSummaryWindow::shoppingSummaryWindow
 * @param choices a vector of choices from the previous window
 * @param masterList the master restaurant list instantiated from main.cpp
 * @param distance the total distance traveled
 * @param visitHistory a vector of QStrings which is a history of all visited restaurants
 * @param parent qt paretn window (defaults to null)
 */
shoppingSummaryWindow::shoppingSummaryWindow(QVector<restaurantChoices*> choices,
                                             RestaurantList masterList,
                                             double distance,
                                             QVector<QString> visitHistory,
                                             QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shoppingSummaryWindow)
{
    ui->setupUi(this);

    this->masterList = masterList;
    //set cart headers and column sizes
    QStringList cartHeaders;
    cartHeaders.push_back("Item");
    cartHeaders.push_back("Price");
    cartHeaders.push_back("Quantity");
    cartHeaders.push_back("Sub-Total");
    ui->cart->setColumnCount(cartHeaders.count());
    ui->cart->setHeaderLabels(cartHeaders);
    ui->cart->expandAll();
    ui->cart->setContextMenuPolicy(Qt::CustomContextMenu);

    ui->summary->setColumnCount(3);
    //ui->summary->setRowCount(1);

    ui->summary->setHorizontalHeaderItem(0,new QTableWidgetItem("Restaurant Name"));
    ui->summary->setHorizontalHeaderItem(1,new QTableWidgetItem("Item Count"));
    ui->summary->setHorizontalHeaderItem(2,new QTableWidgetItem("Sub-Total"));

    ui->distance->setText("Total Distance Traveled: " + QString::number(distance));

    for(unsigned int i = 0; i < visitHistory.size(); i++){
        //add Restaurant Name to the visit history
        ui->visitHistory->addItem(visitHistory.at(i));
    }

    loadCartFromVector(choices);
    loadTotalsFromVector(choices);

}

/** shoppingSummaryWindow Destructor
 * @brief shoppingSummaryWindow::~shoppingSummaryWindow
 */
shoppingSummaryWindow::~shoppingSummaryWindow()
{
    delete ui;
}

/** loadCartFromVector
 * @brief shoppingSummaryWindow::loadCartFromVector
 * This method loads items from the choices vector passed into the constructor
 * @param choices a vector of restaurantChoices structs
 */
void shoppingSummaryWindow::loadCartFromVector(QVector<restaurantChoices*> choices){

    double total = 0;

    for(unsigned int i = 0; i < choices.size(); i++){

        //save a reference
        restaurantChoices* topItem = choices.at(i);

        //add a root-level item to the cart
        QTreeWidgetItem* root = new QTreeWidgetItem(ui->cart);
        root->setText(0,topItem->restaurantName);

        for(unsigned int j = 0; j < topItem->purchases.size(); j++){

            //save a reference to the purchase at this iteration
            purchase* menuPurchase = topItem->purchases.at(j);

            QTreeWidgetItem* child = new QTreeWidgetItem(root);

            child->setText(0,menuPurchase->itemName);
            child->setText(1,QString::number(menuPurchase->price));
            child->setText(2,QString::number(menuPurchase->quantity));

            //calculate sub-total
            double subTotal = menuPurchase->quantity * menuPurchase->price;
            child->setText(3,QString::number(subTotal));

            total += subTotal;
        }//end inner-for

        ui->cart->addTopLevelItem(root);
    } //end outter-for

    ui->cart->expandAll();

}


/** loadTotalsFromVector
 * @brief shoppingSummaryWindow::loadTotalsFromVector
 * Similarily to the loadCartFromVector this method does accounting in regards to the
 * master list class, so that it adds a vector of restuarantChoices up and accumulates
 * them into the list
 * @param choices a vector of choices passed in from the constructor
 */
void shoppingSummaryWindow::loadTotalsFromVector(QVector<restaurantChoices *> choices){
    QVector<total*>* totals = new QVector<total*>;

    double grandTotal = 0;
    int    totalCount = 0;
    for(unsigned int i = 0; i < choices.size(); i++){
        QString restName = choices[i]->restaurantName;
        int itemCount     = 0;
        double subRevenue = 0;

        for(unsigned int j = 0; j < choices[i]->purchases.size(); j++){
            purchase* thisPurchase = choices[i]->purchases.at(j);

            itemCount  += thisPurchase->quantity;
            subRevenue += thisPurchase->price * thisPurchase->quantity;
        }
        totalCount += itemCount;
        grandTotal += subRevenue;

        total* rTotal = new total;


        rTotal->restaurantName = restName;
        rTotal->purchaseCount  = itemCount;
        rTotal->revenue        = subRevenue;

        totals->push_back(rTotal);

    } //end outter-for loop

    //get rid of duplicates in the totals vector
    makeVectorUnique(totals);

    //output them to the table
    int rowIdx = 0;
    for(unsigned int i = 0; i < totals->size(); i++){
        if(totals->at(i)->restaurantName != "no"){
            QString restName   = totals->at(i)->restaurantName;
            int     itemCount  = totals->at(i)->purchaseCount;
            double  subRevenue = totals->at(i)->revenue;

            //row, col, item
            //0 = restaurant name
            //1 = quantity
            //2 = revenue
//            /ui->summary->setRowCount( rowIdx + 1 ); //change to rowIdx + 1 if having problems. I had problems..
            ui->summary->insertRow( rowIdx );
            ui->summary->setItem(rowIdx,0,new QTableWidgetItem(restName));
            ui->summary->setItem(rowIdx,1,new QTableWidgetItem(QString::number(itemCount)));
            ui->summary->setItem(rowIdx,2,new QTableWidgetItem(QString::number(subRevenue)));

            rowIdx++;
        }
    }

    //accounthing method - we take the original restaurant List and now add each item count
    //and sub-revenue to each restaurant object out of the unique totals vector
    updateMasterListTotals(totals);
    masterList.addPurchase(grandTotal,totalCount);

    ui->totalCount->setText(QString::number(totalCount));
    QString formattedTotal = QString("$%L1").arg(grandTotal, 0, 'f', 2);
    ui->grandTotal->setText(formattedTotal);

}

//this method got out of hand, should ideally be refactored. It's bad spaghetti code, sorry
//but it works and it does what its suppose to do.. kind of, also its O(n^2).. :(
/** makeVectorUnique
 * @brief shoppingSummaryWindow::makeVectorUnique
 * @param totals a pointer to a vector of total struct pointers
 * @return that same vector but made unique via a grouping algorithm
 */
QVector<total*> shoppingSummaryWindow::makeVectorUnique(QVector<total*>* totals){

    //the idea is that we are going to iterate the vector and compare each element by name
    //if we have a match, we group the quantity and revenue into the firstTotal (uses i index)
    //and nullify the secondTotal (uses j index)
    //look below to see why we are using "no"
    for(unsigned int i = 0; i < totals->size(); i++){
        total* firstTotal = totals->at(i);

        for(unsigned int j = i + 1; j < totals->size(); j++){
            total* secondTotal = totals->at(j);
            if(firstTotal->restaurantName == secondTotal->restaurantName){

                //combine
                firstTotal->revenue       += secondTotal->revenue;
                firstTotal->purchaseCount += secondTotal->purchaseCount;

                //let me explain, what happens is that we are trying to "group"
                //the structs together and make them unique, this algo follows
                //an insert sort style algorithm, but instead of moving the element
                //it sets the name to "no" so that we can select to not
                //choose "no" when we iterate this vector again.
                secondTotal->restaurantName = "no";
                //erase
//                std::vector<total*>::iterator it = totals->begin() + j;
//                totals->erase(it);

                int innerSize = totals->size();
            } //end inner if
        } //end inner for
    } //end outter for
} //end method

//O(n)
/** updateMasterListTotals
 * @brief shoppingSummaryWindow::updateMasterListTotals
 * This method adds everything up after the vector has been made unique. It
 * accounts for every restaurant and accurately inserts this info back into
 * the restaurant list.
 * @param totals a pointer to a vector of total pointers
 */
void shoppingSummaryWindow::updateMasterListTotals(QVector<total *> *totals){
    for(unsigned int i = 0; i < totals->size(); i++){
        if(totals->at(i)->restaurantName != "no"){
            Restaurant rest = masterList.restaurant(totals->at(i)->restaurantName);
            if(rest.GetName() != ""){
                //revenue
                //purchaseCount
                double revenue    = totals->at(i)->revenue;
                int purchaseCount = totals->at(i)->purchaseCount;

                rest.addRevenue(revenue);
                rest.addSalesCount(purchaseCount);
            }
        }
    }
    masterList.saveRevenue();
}
