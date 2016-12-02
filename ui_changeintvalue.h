/********************************************************************************
** Form generated from reading UI file 'changeintvalue.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEINTVALUE_H
#define UI_CHANGEINTVALUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_changeIntValue
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *value;
    QDialogButtonBox *accept;

    void setupUi(QDialog *changeIntValue)
    {
        if (changeIntValue->objectName().isEmpty())
            changeIntValue->setObjectName(QStringLiteral("changeIntValue"));
        changeIntValue->resize(247, 145);
        verticalLayout = new QVBoxLayout(changeIntValue);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(changeIntValue);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        value = new QSpinBox(groupBox);
        value->setObjectName(QStringLiteral("value"));

        verticalLayout_2->addWidget(value);


        verticalLayout->addWidget(groupBox);

        accept = new QDialogButtonBox(changeIntValue);
        accept->setObjectName(QStringLiteral("accept"));
        accept->setOrientation(Qt::Horizontal);
        accept->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        accept->setCenterButtons(true);

        verticalLayout->addWidget(accept);


        retranslateUi(changeIntValue);
        QObject::connect(accept, SIGNAL(accepted()), changeIntValue, SLOT(accept()));
        QObject::connect(accept, SIGNAL(rejected()), changeIntValue, SLOT(reject()));

        QMetaObject::connectSlotsByName(changeIntValue);
    } // setupUi

    void retranslateUi(QDialog *changeIntValue)
    {
        changeIntValue->setWindowTitle(QApplication::translate("changeIntValue", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("changeIntValue", "Change Item Quantity", 0));
    } // retranslateUi

};

namespace Ui {
    class changeIntValue: public Ui_changeIntValue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINTVALUE_H
