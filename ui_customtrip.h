/********************************************************************************
** Form generated from reading UI file 'customtrip.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMTRIP_H
#define UI_CUSTOMTRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomTrip
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QDialog *CustomTrip)
    {
        if (CustomTrip->objectName().isEmpty())
            CustomTrip->setObjectName(QStringLiteral("CustomTrip"));
        CustomTrip->resize(600, 300);
        gridLayoutWidget = new QWidget(CustomTrip);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 581, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(CustomTrip);

        QMetaObject::connectSlotsByName(CustomTrip);
    } // setupUi

    void retranslateUi(QDialog *CustomTrip)
    {
        CustomTrip->setWindowTitle(QApplication::translate("CustomTrip", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class CustomTrip: public Ui_CustomTrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMTRIP_H
