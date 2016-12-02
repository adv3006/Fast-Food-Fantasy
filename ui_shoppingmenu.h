/********************************************************************************
** Form generated from reading UI file 'shoppingmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGMENU_H
#define UI_SHOPPINGMENU_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_shoppingMenu
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QListWidget *visitHistory;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *restaurantLogo;
    QLabel *restaurantName;
    QTableWidget *menu;
    QPushButton *addToCart;
    QLabel *distance;
    QGroupBox *cartBox;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *cart;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *next;
    QLabel *status;
    QDialogButtonBox *okay_cancel;

    void setupUi(QDialog *shoppingMenu)
    {
        if (shoppingMenu->objectName().isEmpty())
            shoppingMenu->setObjectName(QStringLiteral("shoppingMenu"));
        shoppingMenu->resize(1160, 717);
        verticalLayout = new QVBoxLayout(shoppingMenu);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_3 = new QGroupBox(shoppingMenu);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(200, 16777215));
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        visitHistory = new QListWidget(groupBox_5);
        visitHistory->setObjectName(QStringLiteral("visitHistory"));
        visitHistory->setEnabled(true);
        visitHistory->setMaximumSize(QSize(16777200, 16777215));

        verticalLayout_4->addWidget(visitHistory);


        horizontalLayout_2->addWidget(groupBox_5);

        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMaximumSize(QSize(16777204, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        restaurantLogo = new QLabel(groupBox);
        restaurantLogo->setObjectName(QStringLiteral("restaurantLogo"));

        horizontalLayout->addWidget(restaurantLogo);

        restaurantName = new QLabel(groupBox);
        restaurantName->setObjectName(QStringLiteral("restaurantName"));
        QFont font;
        font.setPointSize(24);
        restaurantName->setFont(font);

        horizontalLayout->addWidget(restaurantName);


        verticalLayout_3->addWidget(groupBox);

        menu = new QTableWidget(groupBox_2);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setEditTriggers(QAbstractItemView::NoEditTriggers);
        menu->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(menu);

        addToCart = new QPushButton(groupBox_2);
        addToCart->setObjectName(QStringLiteral("addToCart"));

        verticalLayout_3->addWidget(addToCart);

        distance = new QLabel(groupBox_2);
        distance->setObjectName(QStringLiteral("distance"));

        verticalLayout_3->addWidget(distance);


        horizontalLayout_2->addWidget(groupBox_2);

        cartBox = new QGroupBox(groupBox_3);
        cartBox->setObjectName(QStringLiteral("cartBox"));
        verticalLayout_2 = new QVBoxLayout(cartBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        cart = new QTreeWidget(cartBox);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        cart->setHeaderItem(__qtreewidgetitem);
        cart->setObjectName(QStringLiteral("cart"));
        cart->setMaximumSize(QSize(14777215, 16777215));

        verticalLayout_2->addWidget(cart);


        horizontalLayout_2->addWidget(cartBox);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(shoppingMenu);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        next = new QPushButton(groupBox_4);
        next->setObjectName(QStringLiteral("next"));
        next->setMaximumSize(QSize(250, 16777215));
        next->setAutoDefault(true);
        next->setFlat(false);

        horizontalLayout_3->addWidget(next);


        verticalLayout->addWidget(groupBox_4);

        status = new QLabel(shoppingMenu);
        status->setObjectName(QStringLiteral("status"));
        status->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(status);

        okay_cancel = new QDialogButtonBox(shoppingMenu);
        okay_cancel->setObjectName(QStringLiteral("okay_cancel"));
        okay_cancel->setContextMenuPolicy(Qt::CustomContextMenu);
        okay_cancel->setOrientation(Qt::Horizontal);
        okay_cancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        okay_cancel->setCenterButtons(true);

        verticalLayout->addWidget(okay_cancel);


        retranslateUi(shoppingMenu);
        QObject::connect(okay_cancel, SIGNAL(accepted()), shoppingMenu, SLOT(accept()));
        QObject::connect(okay_cancel, SIGNAL(rejected()), shoppingMenu, SLOT(reject()));

        next->setDefault(false);


        QMetaObject::connectSlotsByName(shoppingMenu);
    } // setupUi

    void retranslateUi(QDialog *shoppingMenu)
    {
        shoppingMenu->setWindowTitle(QApplication::translate("shoppingMenu", "Shopping Menu", 0));
        groupBox_3->setTitle(QString());
        groupBox_5->setTitle(QApplication::translate("shoppingMenu", "Visited Restaurants", 0));
        groupBox_2->setTitle(QString());
        groupBox->setTitle(QApplication::translate("shoppingMenu", "Restaurant Name", 0));
        restaurantLogo->setText(QString());
        restaurantName->setText(QString());
        addToCart->setText(QApplication::translate("shoppingMenu", "add selections to cart", 0));
        distance->setText(QString());
        cartBox->setTitle(QApplication::translate("shoppingMenu", "Shopping Cart", 0));
        groupBox_4->setTitle(QString());
        next->setText(QApplication::translate("shoppingMenu", "Visit Next Restaurant", 0));
        status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class shoppingMenu: public Ui_shoppingMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGMENU_H
