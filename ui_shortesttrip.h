/********************************************************************************
** Form generated from reading UI file 'shortesttrip.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTESTTRIP_H
#define UI_SHORTESTTRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShortestTrip
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QDialog *ShortestTrip)
    {
        if (ShortestTrip->objectName().isEmpty())
            ShortestTrip->setObjectName(QStringLiteral("ShortestTrip"));
        ShortestTrip->resize(609, 300);
        gridLayoutWidget = new QWidget(ShortestTrip);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 591, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(ShortestTrip);

        QMetaObject::connectSlotsByName(ShortestTrip);
    } // setupUi

    void retranslateUi(QDialog *ShortestTrip)
    {
        ShortestTrip->setWindowTitle(QApplication::translate("ShortestTrip", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class ShortestTrip: public Ui_ShortestTrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTESTTRIP_H
