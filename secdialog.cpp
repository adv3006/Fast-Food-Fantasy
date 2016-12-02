#include "secdialog.h"
#include "ui_secdialog.h"

/**
 * @brief SecDialog::SecDialog
 * @param parent
 */
SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    ui->label_2->hide();
}

/**
 * @brief SecDialog::~SecDialog
 */
SecDialog::~SecDialog()
{
    delete ui;
}

/**
 * @brief SecDialog::on_pushButton_clicked
 */
void SecDialog::on_pushButton_clicked()
{
    bool    myBool; //CALC - determines if password is correct
    QString myPass; //CALC - correct password

    //PROCESSING - sets correct password
    myPass = "password";

    //PROCESSING - if password is correct, closes dialog box
    if(ui->lineEdit->text() == myPass)
    {
        myBool = true;
        SecDialog::set_text(myPass);

        SecDialog::close();
    }
    else
    {
        ui->label_2->show();
        ui->lineEdit->clear();
        myBool = false;
    }
}

/**
 * @brief SecDialog::get_text
 * @return
 */
QString SecDialog::get_text()
{
    return myString;
}

/**
 * @brief SecDialog::set_text
 * @param someString
 */
void SecDialog::set_text(QString someString)
{
    myString = someString;
}
