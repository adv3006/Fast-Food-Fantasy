/********************************************************************************
** Form generated from reading UI file 'addmenuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMENUWINDOW_H
#define UI_ADDMENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddMenuWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QLabel *ItemName_Label;
    QLineEdit *nameEdit;
    QLabel *label;
    QLineEdit *priceEdit;
    QLabel *label_2;

    void setupUi(QDialog *AddMenuWindow)
    {
        if (AddMenuWindow->objectName().isEmpty())
            AddMenuWindow->setObjectName(QStringLiteral("AddMenuWindow"));
        AddMenuWindow->resize(323, 267);
        buttonBox = new QDialogButtonBox(AddMenuWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 220, 251, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_3 = new QLabel(AddMenuWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 20, 161, 16));
        ItemName_Label = new QLabel(AddMenuWindow);
        ItemName_Label->setObjectName(QStringLiteral("ItemName_Label"));
        ItemName_Label->setGeometry(QRect(110, 110, 161, 20));
        nameEdit = new QLineEdit(AddMenuWindow);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(105, 106, 125, 21));
        label = new QLabel(AddMenuWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(31, 106, 66, 16));
        priceEdit = new QLineEdit(AddMenuWindow);
        priceEdit->setObjectName(QStringLiteral("priceEdit"));
        priceEdit->setGeometry(QRect(105, 162, 125, 21));
        label_2 = new QLabel(AddMenuWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(31, 162, 61, 16));

        retranslateUi(AddMenuWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddMenuWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddMenuWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddMenuWindow);
    } // setupUi

    void retranslateUi(QDialog *AddMenuWindow)
    {
        AddMenuWindow->setWindowTitle(QApplication::translate("AddMenuWindow", "Dialog", 0));
        label_3->setText(QApplication::translate("AddMenuWindow", "Add Menu Item and Price", 0));
        ItemName_Label->setText(QApplication::translate("AddMenuWindow", "Enter New Price", 0));
        label->setText(QApplication::translate("AddMenuWindow", "Item Name", 0));
        label_2->setText(QApplication::translate("AddMenuWindow", "Item Price", 0));
    } // retranslateUi

};

namespace Ui {
    class AddMenuWindow: public Ui_AddMenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMENUWINDOW_H
