#ifndef CHANGEINTVALUE_H
#define CHANGEINTVALUE_H

#include <QDialog>
#include <QTreeWidgetItem>

namespace Ui {
class changeIntValue;
}

class changeIntValue : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief changeIntValue
     * @param listViewItem the QTreeWidgetITem that the click came from
     * @param parent the parent window
     */
    explicit changeIntValue(QTreeWidgetItem* listViewItem, QWidget *parent = 0);
    ~changeIntValue();

private slots:
    /** SLOT
     * @brief on_accept_accepted
     */
    void on_accept_accepted();

private:
    Ui::changeIntValue *ui;         ///< a pointer to the ui window
    QTreeWidgetItem* listViewItem;  ///< a QTreeWidgetItem that was passed into the constructor
};

#endif // CHANGEINTVALUE_H
