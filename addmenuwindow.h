#ifndef ADDMENUWINDOW_H
#define ADDMENUWINDOW_H

#include <QDialog>
#include <QString>
#include "database.h"
#include "restaurant.h"
#include <QMessageBox>

namespace Ui {
class AddMenuWindow;
}

class AddMenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddMenuWindow(database db, Restaurant res, int i, QWidget *parent = 0);
    ~AddMenuWindow();
signals:
    void MenuItem(QString newName, float newPrice);
    void OKClicked();
    void OKClicked(QString, float);
    void PriceChange(float);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_destroyed();

private:
    Ui::AddMenuWindow *ui;   ///< CALC - pointer to gui
    QString           name;  ///< CALC - name of item
    float             price; ///< CALC - price of item
    database          db;    ///< CALC - used to check if menu item exits
    Restaurant        rest;  ///< CALC - used to check if menu item exits
    int               index; ///< CALC - determines if add menu is from new restaurant or existing
};

#endif // ADDMENUWINDOW_H
