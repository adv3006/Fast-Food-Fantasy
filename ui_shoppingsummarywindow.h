/********************************************************************************
** Form generated from reading UI file 'shoppingsummarywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGSUMMARYWINDOW_H
#define UI_SHOPPINGSUMMARYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_shoppingSummaryWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *cart;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *summary;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_2;
    QListWidget *visitHistory;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *distance;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *totalCount;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *grandTotal;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *shoppingSummaryWindow)
    {
        if (shoppingSummaryWindow->objectName().isEmpty())
            shoppingSummaryWindow->setObjectName(QStringLiteral("shoppingSummaryWindow"));
        shoppingSummaryWindow->resize(574, 653);
        verticalLayout = new QVBoxLayout(shoppingSummaryWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(shoppingSummaryWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cart = new QTreeWidget(groupBox);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        cart->setHeaderItem(__qtreewidgetitem);
        cart->setObjectName(QStringLiteral("cart"));
        cart->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout->addWidget(cart);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(shoppingSummaryWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777214, 175));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        summary = new QTableWidget(groupBox_2);
        summary->setObjectName(QStringLiteral("summary"));
        summary->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout_2->addWidget(summary);


        verticalLayout->addWidget(groupBox_2);

        groupBox_7 = new QGroupBox(shoppingSummaryWindow);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setMaximumSize(QSize(16777215, 150));
        verticalLayout_2 = new QVBoxLayout(groupBox_7);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        visitHistory = new QListWidget(groupBox_7);
        visitHistory->setObjectName(QStringLiteral("visitHistory"));
        visitHistory->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(visitHistory);


        verticalLayout->addWidget(groupBox_7);

        groupBox_5 = new QGroupBox(shoppingSummaryWindow);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        distance = new QLabel(groupBox_6);
        distance->setObjectName(QStringLiteral("distance"));

        horizontalLayout_6->addWidget(distance);


        horizontalLayout_5->addWidget(groupBox_6);

        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        totalCount = new QLabel(groupBox_4);
        totalCount->setObjectName(QStringLiteral("totalCount"));

        horizontalLayout_4->addWidget(totalCount);


        horizontalLayout_5->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(groupBox_5);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        grandTotal = new QLabel(groupBox_3);
        grandTotal->setObjectName(QStringLiteral("grandTotal"));

        horizontalLayout_3->addWidget(grandTotal);


        horizontalLayout_5->addWidget(groupBox_3);


        verticalLayout->addWidget(groupBox_5);

        buttonBox = new QDialogButtonBox(shoppingSummaryWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(shoppingSummaryWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), shoppingSummaryWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), shoppingSummaryWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(shoppingSummaryWindow);
    } // setupUi

    void retranslateUi(QDialog *shoppingSummaryWindow)
    {
        shoppingSummaryWindow->setWindowTitle(QApplication::translate("shoppingSummaryWindow", "Receipt", 0));
        groupBox->setTitle(QApplication::translate("shoppingSummaryWindow", "Your Order", 0));
        groupBox_2->setTitle(QApplication::translate("shoppingSummaryWindow", "Summary", 0));
        groupBox_7->setTitle(QApplication::translate("shoppingSummaryWindow", "Restaurants Visited", 0));
        groupBox_5->setTitle(QString());
        groupBox_6->setTitle(QApplication::translate("shoppingSummaryWindow", "Total Distance Traveled", 0));
        distance->setText(QString());
        groupBox_4->setTitle(QApplication::translate("shoppingSummaryWindow", "Total Items", 0));
        totalCount->setText(QString());
        groupBox_3->setTitle(QApplication::translate("shoppingSummaryWindow", "Grand Total", 0));
        grandTotal->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class shoppingSummaryWindow: public Ui_shoppingSummaryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGSUMMARYWINDOW_H
