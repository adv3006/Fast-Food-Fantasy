#include "changeintvalue.h"
#include "ui_changeintvalue.h"
#include <QTextStream>

/** changeIntValue Constructor
 * @brief changeIntValue::changeIntValue
 * This method pops up a right-click context menu to change an int value of the
 * listViewItem passed into this class.
 * @param listViewItem the tree widget item that the click came from
 * @param parent the parent window defaults to 0 via QT
 */
changeIntValue::changeIntValue(QTreeWidgetItem* listViewItem, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeIntValue)
{
    ui->setupUi(this);

    this->listViewItem = listViewItem;

    //get the quantity of the listViewItem form the tree widget
    //that was passed in, we make init the value of the spin box
    //to that value.
    if(listViewItem != NULL){
     ui->value->setValue(listViewItem->text(2).toInt());
    }
}

/** changeIntValue Destructor
 * @brief changeIntValue::~changeIntValue
 */
changeIntValue::~changeIntValue()
{
    delete ui;
}

/** SLOT
 * @brief changeIntValue::on_accept_accepted
 * When the accept button is pressed, we save the value back into the listViewItem that
 * was passed into the object
 */
void changeIntValue::on_accept_accepted()
{
    if(listViewItem != NULL){
        listViewItem->setText(2,ui->value->text());

        //re-calculate the sub-total column
        int qty = ui->value->text().toInt();
        double price = listViewItem->text(1).toDouble();
        QString subTotal = QString::number(qty*price,'g',4);

        listViewItem->setText(3, subTotal);
    }
}
